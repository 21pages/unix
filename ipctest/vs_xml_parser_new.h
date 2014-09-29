
#ifndef __VS_XML_PARSER_NEW_H__
#define __VS_XML_PARSER_NEW_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


// ��1����struct�ڴ泤��
#pragma pack(1)


/********************************************************************************
*                    �ص����ѣ�TYPE_STRING ���͵ĳ���,������4�ı���
********************************************************************************/

#define XML_TITLE		"<IPC>\r\n"

/* ��������ṹ��������� */
enum field_types
{
    TYPE_STRUCT = 0,              // �ṹ��

    TYPE_INT,                      // 1   int
    TYPE_STRING,                   // 2   char *,   �ر�ע�⣬���ȱ���Ϊ4�ı�������Ϊ�ڴ��ֵַ�ض���4�ı���.
    TYPE_BOOL,                     // 3   int,      ���xml�г��ֵ� TRUE,FALSE ��
    TYPE_CHAR,                     // 4   char,     ������ʹ�����,�� char[4] + TYPE_STRING ���ʹ�ñ���Щ

    TYPE_IP_ADDR,                  // 5  unsigned long int,  IP��, �������� char[16] + TYPE_STRING ���ʹ�ø�����ֱ��Щ

    TYPE_DATE_DT,                  // 6  ��Щʱ��....���д�����
    TYPE_TIME_LDT,                 // 7
    TYPE_DATE_D,                   // 8
    TYPE_DATE_T,                   // 9
    TYPE_DATE_T2,                  // 10
};

enum err_xml_code
{
    XML_SUCCESS =               0,
    /* ������ش���ʱ, ���ܵĴ������ */
    XML_ERR_MEMORY =           1,    // �ڴ�������
    XML_ERR_ARRAY_LESS =      2,    // �ṹ�嶨�������̫С,XML�е��������ݶ������鶨��
    XML_ERR_NO_FIND_DESC =    4    // û���ҵ��ýṹ������,Ӧ����_INDEXû�мӵ� enum sub_struct_index��find_sub_strcut_desc������δ����
};

/* ��structת��xml��ʽʱ,һЩ��ʾ��ʽ���� */
enum input_type
{
    HAVE_TITLE = 1,                     // д�� <Message>������ͷ
    NO_TITLE = 2,                       //   ��
    
    EASY_CLOSE = 4,                     // ����ģʽ <A .. />
    FULL_CLOSE = 8,                     // ǰ��ƥ�䷽ʽ, <A> ... </A>

    LIST_SHOW = 16,                     // �б���ʾ <A>1</A> <B>2<B>...
    ATTRIB_SHOW = 32,                   // ������ʾ <A a=1 b=2 />

    SHOW_INT_0 = 64,                    // �����int��,����0Ҳ��Ϊ����Чֵ(Ĭ��0��Ч)
    SHOW_STRING_NULL = 128,            // �����string��,����NULLҲ��Ϊ��Ч(Ĭ��NULL��Ч)

    TEST_MODE = NO_TITLE | ATTRIB_SHOW |SHOW_INT_0 | SHOW_STRING_NULL       // ������
};

/***********************************************************************
*          �Խṹ��Ľ�������������struct��xml֮�����ת��Ϣ
***********************************************************************/
typedef struct tagFIELD_TYPE
{
    char name[50];                  // �ֶ�����
    int  size;                      // �ֶδ�С
    int  type;                      // �ֶ�����: ��Ҫ�ܽ�.
    int  repeat;                    // �ظ���,�����鳤�� 0,1,��ʾ��һλ(Ĭ��0Ҳ��ʾ��һλ)
    int  only_struct_index;       // ����find_sub_strcut_desc������������֮����,����structǶ��
}FIELD_TYPE, *PFIELD_TYPE;

/***********************************************************************
*          ͬ���ǶԽṹ��Ľ���,����struct��������Ϣ
*     �� INPUT_MESSAGE ����һ�� FIELD_TYPE ��ͬ���ɶ�struct������
***********************************************************************/
typedef struct tagINPUT_MESSAGE
{
    char name[50];                    // Э���ǩͷ���� ͨ������ Message ��
    int  input_fdarray_count;       // �����Э��,������
    int  input_type;                 // ��ʾ�ķ�ʽ, ���� HAVE_TITLE|FULL_CLOSE|LIST_SHOW
}INPUT_MESSAGE, *PINPUT_MESSAGE;

/***********************************************************************
*                          ������ú���
***********************************************************************/
// ���ú���ԭ��
char * find_sub_strcut_desc(int index, INPUT_MESSAGE *out_inputmsg);
// ��������
typedef char * __find_sub_strcut_desc(int index, INPUT_MESSAGE *out_inputmsg);

/***********************************************************************
*                        �ṹ�帴�ƺ���
***********************************************************************/
char * malloc_struct(INPUT_MESSAGE *in_inputmsg, char *out_msg_buf, FIELD_TYPE * in_fdarray);


/***********************************************************************
*                          ����XML����
***********************************************************************/
//int struct2xml_6091(alarmConfig_Req alarmConfig, char *outbuf);

// ��xml������struct�ṹ.���һ������fun�Ǻ���,��struct_index��ƥ��ĺ���
int xml2struct( char *xml_string, int xml_len, char *outbuf, int struct_index, __find_sub_strcut_desc fun);
// ��xml�в���һ��intֵ
int findxml_int( char *xml_string, int xml_len, char *find_str, int *out );
// ��xml�в���һ��stringֵ
int findxml_string( char *xml_string, int xml_len, char *find_str, char *outbuf );
// ��struct������һ��struct
int struct2xml( char *pstruct, char *outbuf, int struct_index, __find_sub_strcut_desc fun );

/***********************************************************************
*                             ���Ժ���
***********************************************************************/
int vs_xml_parser();
    
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __VS_XML_PARSER_NEW_H__ */

/**************************************************************************
 ��: __find_sub_strcut_desc������д��ʾ��
char * your_fun(int index, INPUT_MESSAGE *out_inputmsg)
{
    if (index == Record_INDEX)
    {
        INPUT_MESSAGE msg = { "Record", 2, TEST_MODE };
        FIELD_TYPE fdarray[] =
        {
            {"BeginTime",       100,                TYPE_STRING,    0,  0 },
            {"EndTime",         100,                TYPE_STRING,    0,  0 }
        };

        return malloc_struct(&msg, (char *)out_inputmsg, fdarray);
    }

    if (index == StoreRecord_INDEX)
    {
        INPUT_MESSAGE msg = { "StoreRecord", 3, TEST_MODE };
        FIELD_TYPE fdarray[] =
        {
            {"DevType",         sizeof(int),        TYPE_INT,       0,  0 },
            {"ID",              sizeof(int),        TYPE_INT,       0,  0 },
            {"Record",          sizeof(Record),TYPE_STRUCT,  8,  Record_INDEX }
        };
            
        return malloc_struct(&msg, (char *)out_inputmsg, fdarray);
    }

    if (index == test_xml_INDEX)
    {
        INPUT_MESSAGE msg = { "test_xml", 3, TEST_MODE };
        FIELD_TYPE fdarray[] =
        {
            {"ID",              sizeof(int),        TYPE_INT,           3,  0 },
            {"StoreRecord",     sizeof(StoreRecord),TYPE_STRUCT, 3,  StoreRecord_INDEX },
            {"StoreRecord2",        sizeof(StoreRecord),TYPE_STRUCT, 3,  StoreRecord_INDEX }
        };

        return malloc_struct(&msg, (char *)out_inputmsg, fdarray);
    };
    return NULL;
}
**************************************************************************/

