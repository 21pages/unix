#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


#include <stdlib.h>         /*  for malloc() */
#include <string.h>         /*  for memcpy() */
#include <dirent.h>         /* for opendir() */
#include <sys/vfs.h>        /* for statfs() */
#include <stdio.h>          /* for sprintf() */

#include <sys/stat.h>        /* for stat() */
#include <unistd.h>
#include <sys/types.h>       /* for mkdir() */

#include "config.h"
#include "vs_config_put_var_auto.h"


typedef struct tagConfig_timer_param
{
    int         timer_id_detect;            // ��ʱ�ƶ����Ķ�ʱ�����
    int         timer_id_cap;               // ��ʱץ�ĵĶ�ʱ�����
}Config_timer_param;
Config_timer_param g_conf_timer;

// sx added auto
//#include "vs_config_put_var_auto.h"
// sx added auto end 


// ��weekplan�е����ݿ�����schedule��

// ��ȡ�����ļ�
int config_read(char *file_name)
{
    FILE *fp;
    char line[512];
    char name[48];      // ǰ������֣��涨�������20
    char var[256];      // �������ֵ
    char note[256];      // ע������
    
    char c;
    int start, pos;
	int flag_4_close = 0;       // var�����Ƿ���"��
	int flag_1_box = 0;
	int flag_1_box_end = 0;
    int flag = 0;
    char *ret = line;

    memset(&g_config, 0, sizeof(AllConfig));
    
    fp = fopen(file_name, "r");
    if ( fp == NULL )
    {
        return -1;
    }
    
    while( !feof(fp) )
    {
        ret = fgets(line, 512, fp);
        if ( ret == NULL )
        {
            break;
        }

        // ����line�Ľ���, ��=�ŷָ�. ������strstr, �Լ�������. ��Ϊ��ϣ��trim,ȥ��"�ŵȵȡ�ʹ��strstr�鷳��

		// ������Ч���� name���֣����������=��
		//              var���֣����Ժ���=�š�
		//              ���пո񶼺��ԡ�������trim���ܡ�var���֣����ϣ�����пո��"�ţ���Ҫ��"��������(��Ҫ��ǰ�沿��)
		//              ������[]ʱ,Ч������name[0]=='\0', ��var��ֵΪ[]�е��ڲ�,var�Ǿ���trim�ġ�
		// ���������У�
		//aaa=bbbb
		//  aaa   =    bbb
        //  aaa   == bbb
        //  aaa   ===  bb===bb
        //  aaa  ======= "  b ==  b   b  "
        //[abc]
        //  [  abc  ]
        //  [  a  b  c ]

        // ����ǡ������ aaa = bb bb    ��ֻ�൱�� aaa = bb�ˣ���Ϊ bb bb �м��пո�ȴû��"�Ű�������
        
		start = 0;
		flag = 0;
		pos = 0;
		name[0] = '\0';
		var[0] = '\0';
		note[0] = '\0';
		flag_4_close = 0;
		flag_1_box = 0;
		flag_1_box_end = 0;
		c = line[0];

		// |_| AAA |_| = |_| BBB |_|
		// 0   1  2    3     4  5     flag
		while( c != '\0' )
		{
			c = line[pos];
			if ( (( c == ' ' || c == '\t') && flag_4_close == 0 ) || c == '\0' || c == '\n' || c == '\r' || (c == '=' && flag <= 3) || (c == '/' && line[pos+1] == '/') )
			{
				if ( flag == 0 || flag == 3 )
				{
					start = pos;        // �����ո���ʼ����ǰ��
				}
				if ( flag == 1 )        // ����
				{
					memcpy( name, line+start, pos-start );
					name[pos-start] = '\0';
					flag ++;
				}
				if ( flag == 4 )
				{
					if (flag_1_box == 1)
					{
						if (start > 0)
						{
							memcpy( var, line+start, flag_1_box_end-start+1);
							var[flag_1_box_end-start+1] = '\0';
						}
						if ( flag_1_box_end-start >= 0 && var[flag_1_box_end-start] == '"' && flag_4_close == 1 )
						{
							var[flag_1_box_end-start] = '\0';  // ȥ�� " ��
						}
						break;
					}
					if ( line[start-1] == '/' && line[start] == '/' )       //  a=//ccc �������var�ǿ�
					{
						strcpy(note, line+start-1);
						break;
					}
					memcpy( var, line+start, pos-start );
					var[pos-start] = '\0';
					flag ++;
					
					if ( pos-start-1 >= 0 && var[pos-start-1] == '"' && flag_4_close == 1 )
					{
						var[pos-start-1] = '\0';  // ȥ�� " ��
					}
					break;
				}
				if ( c == '=' && ( flag == 2 || flag == 5) )
				{
					flag = 3;
				}
			}
			else
			{
				if ( flag_1_box == 1 && c != ' ' && c != '\t' && c != ']' )
				{
					if (start < 0)
					{
						start = pos;
					}
					flag_1_box_end = pos;
				}
				if ( flag == 0 || flag == 3 )
				{
					flag ++;
					start = pos;

					if ( flag == 1 && c == '[' )
					{
						flag = 4;
						flag_1_box = 1;	// �����ŷ�ʽ
						flag_4_close = 1;		// ����"��
						start = -1;
					}
					if ( flag == 4 && c == '"' )
					{
						flag_4_close = 1;		// ����"��
						start ++;
						flag_1_box = 1;
					}
				}
				if ( flag == 4 && flag_1_box == 1 && c == ']' )
				{
					if (start > 0)
					{
						memcpy( var, line+start, flag_1_box_end-start+1);
						var[flag_1_box_end-start+1] = '\0';
					}
					break;
				}
			}
			pos ++;
		}

		// ��pos��ʼ������noteע������
		if (note[0] =='\0')
		{
			while (line[pos] != '\0')
			{
				if ( line[pos] == '/' && line[pos+1] == '/' )
				{
					strcpy(note, line+pos);
					/*
					int note_len = strlen(note);
					if ( note[note_len-1] == '\n' )
					    note[note_len-1] = '\0';
					if ( note[note_len -2] == '\r' )
					    note[note_len -2] = '\0';
					*/
					break;
				}
				pos ++;
			}
		}
		if (name[0] == '\r' || name[0] == '\n')
		{
			continue;
		}
        // ����ȫ�ֱ����ĸ�ֵ
        vs_config_put_var(name, var, note);
        
    }

    fclose(fp);
    return 0;
}

// дһ�д�[]����Ϣ
int vs_config_box_line(FILE *fp, char *line, char *name, char *note)
{
    int max_first_len = 48;     // ǰ���48���ַ�
    int len = 0;

    //fprintf(fp, "\r\n");
    
    sprintf(line, "[%s]", name);
    if ( note[0] != '\0' )
    {
        len = strlen(line);     // �ƻ�ǰ��ĳ��ȣ�׷��һ���Ŀո񣬶���
        if (len < max_first_len)
        {
            memset(line+len, ' ', max_first_len - len);
            line[max_first_len] = '\0';
        }
        strcat(line, note);  // ��ע��׷��
    }
    fprintf(fp, "%s\r\n", line);
    return 0;
}

// дһ��������ֵ. name = var   note(//...)
int vs_config_var_line(FILE *fp, char *line, char *name, char *var, char *note)
{
    int max_first_len = 48;     // ǰ���48���ַ�
    int len = 0;

    if ( name[0] == '\0' )
    {
        return 0;
    }
    if ( var[0] == '\0' )
    {
        sprintf(line, "  %s = ", name);
    }
    else
    {
        sprintf(line, "  %s = \"%s\"", name, var);
    }
    if ( note[0] != '\0' )
    {
        len = strlen(line);     // �ƻ�ǰ��ĳ��ȣ�׷��һ���Ŀո񣬶���
        if (len < max_first_len)
        {
            memset(line+len, ' ', max_first_len - len);
            line[max_first_len] = '\0';
        }
        if ( note[0] == '\0')
        {
            strcat(line, "\n");
        }
        else
        {
            strcat(line, note);  // ��ע��׷��
            if (note[strlen(note)-1] != '\n' )
            {
                strcat(line, "\n");
            }
        }
    }
    fprintf(fp, "%s\r\n", line);
    return 0;
}

// дһ��������ֵ. name = var   note(//...)
int vs_config_var_line2(FILE *fp, char *line, char *name, long var, char *note)
{
    int max_first_len = 48;     // ǰ���48���ַ�
    int len = 0;

    if ( name[0] == '\0' )
    {
        return 0;
    }

    sprintf(line, "  %s = %ld", name, var);
    if ( note[0] != '\0' )
    {
        len = strlen(line);     // �ƻ�ǰ��ĳ��ȣ�׷��һ���Ŀո񣬶���
        if (len < max_first_len)
        {
            memset(line+len, ' ', max_first_len - len);
            line[max_first_len] = '\0';
        }
        if ( note[0] == '\0')
        {
            strcat(line, "\n");
        }
        else
        {
            strcat(line, note);  // ��ע��׷��
            if (note[strlen(note)-1] != '\n' )
            {
                strcat(line, "\n");
            }
        }
    }
    fprintf(fp, "%s\r\n", line);
    return 0;
}

// sx added auto
#include "vs_config_write_auto.h"
// sx added auto en

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

