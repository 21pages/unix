int vs_config_put_var(char *name, char *var, char *note)
{
    if ( name[0] == '\0' && var[0] != '\0' )
    {
        if ( strcmp(var, "login") == 0 )// web��¼
        {
            g_config.config_index = CFG_login;
            strcpy(g_config.login.name, var);
            strcpy(g_config.login.note, note);
        }
        else if ( strcmp(var, "user") == 0 )//�û���Ϣ  
        {
            g_config.config_index = CFG_user;
            strcpy(g_config.user.name, var);
            strcpy(g_config.user.note, note);
        }
        else if ( strcmp(var, "video") == 0 )//��Ƶ����
        {
            g_config.config_index = CFG_video;
            strcpy(g_config.video.name, var);
            strcpy(g_config.video.note, note);
        }
        else if ( strcmp(var, "network") == 0 )//�������
        {
            g_config.config_index = CFG_network;
            strcpy(g_config.network.name, var);
            strcpy(g_config.network.note, note);
        }
        else if ( strcmp(var, "alert") == 0 )//��������	
        {
            g_config.config_index = CFG_alert;
            strcpy(g_config.alert.name, var);
            strcpy(g_config.alert.note, note);
        }
        else if ( strcmp(var, "store") == 0 )//�洢����	
        {
            g_config.config_index = CFG_store;
            strcpy(g_config.store.name, var);
            strcpy(g_config.store.note, note);
        }
        else if ( strcmp(var, "sys") == 0 )//ϵͳ����	                        	
        {
            g_config.config_index = CFG_sys;
            strcpy(g_config.sys.name, var);
            strcpy(g_config.sys.note, note);
        }
        else if ( strcmp(var, "rtv_start") == 0 )// ʵʱ��Ƶ��������
        {
            g_config.config_index = CFG_rtv_start;
            strcpy(g_config.rtv_start.name, var);
            strcpy(g_config.rtv_start.note, note);
        }
        else if ( strcmp(var, "htv_start") == 0 )// ¼����������
        {
            g_config.config_index = CFG_htv_start;
            strcpy(g_config.htv_start.name, var);
            strcpy(g_config.htv_start.note, note);
        }
        else if ( strcmp(var, "htv_end") == 0 )// ¼��ֹͣ����
        {
            g_config.config_index = CFG_htv_end;
            strcpy(g_config.htv_end.name, var);
            strcpy(g_config.htv_end.note, note);
        }
        else if ( strcmp(var, "pic_start") == 0 )// ͼƬץ����������
        {
            g_config.config_index = CFG_pic_start;
            strcpy(g_config.pic_start.name, var);
            strcpy(g_config.pic_start.note, note);
        }
        else if ( strcmp(var, "ptz_control") == 0 )// ��̨��������
        {
            g_config.config_index = CFG_ptz_control;
            strcpy(g_config.ptz_control.name, var);
            strcpy(g_config.ptz_control.note, note);
        }
        else if ( strcmp(var, "sys_quit") == 0 )// IPC�˳�����
        {
            g_config.config_index = CFG_sys_quit;
            strcpy(g_config.sys_quit.name, var);
            strcpy(g_config.sys_quit.note, note);
        }
        else if ( strcmp(var, "log") == 0 )// ��־��ȡ
        {
            g_config.config_index = CFG_log;
            strcpy(g_config.log.name, var);
            strcpy(g_config.log.note, note);
        }
        else if ( strcmp(var, "usb_remove") == 0 )
        {
            g_config.config_index = CFG_usb_remove;
            strcpy(g_config.usb_remove.name, var);
            strcpy(g_config.usb_remove.note, note);
        }
        else if ( strcmp(var, "hb") == 0 )// ����
        {
            g_config.config_index = CFG_hb;
            strcpy(g_config.hb.name, var);
            strcpy(g_config.hb.note, note);
        }
        else if ( strcmp(var, "def_config") == 0 )// �ָ���������
        {
            g_config.config_index = CFG_def_config;
            strcpy(g_config.def_config.name, var);
            strcpy(g_config.def_config.note, note);
        }
        else if ( strcmp(var, "md_report") == 0 )
        {
            g_config.config_index = CFG_md_report;
            strcpy(g_config.md_report.name, var);
            strcpy(g_config.md_report.note, note);
        }
        else if ( strcmp(var, "alarm_disk") == 0 )// �������ɴ洢����ȫ�ֱ����ṩ
        {
            g_config.config_index = CFG_alarm_disk;
            strcpy(g_config.alarm_disk.name, var);
            strcpy(g_config.alarm_disk.note, note);
        }
        else if ( strcmp(var, "time_syn") == 0 )// ʱ��ͬ��
        {
            g_config.config_index = CFG_time_syn;
            strcpy(g_config.time_syn.name, var);
            strcpy(g_config.time_syn.note, note);
        }
        else if ( strcmp(var, "alarm_error") == 0 )// IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
        {
            g_config.config_index = CFG_alarm_error;
            strcpy(g_config.alarm_error.name, var);
            strcpy(g_config.alarm_error.note, note);
        }
        else if ( strcmp(var, "process_info") == 0 )// ��ȡipc������Ϣ
        {
            g_config.config_index = CFG_process_info;
            strcpy(g_config.process_info.name, var);
            strcpy(g_config.process_info.note, note);
        }
        else if ( strcmp(var, "end") == 0 )
        {
            g_config.config_index = CFG_end;
            strcpy(g_config.end.name, var);
            strcpy(g_config.end.note, note);
        }
        return 0;
    }

    // ���о������ֵ
    if ( g_config.config_index == CFG_login)// web��¼
    {
        if ( strcmp( name, "pgh" ) == 0 )
        {
            strcpy( g_config.login.pgh.name, name );
            strcpy( g_config.login.pgh.note, note );
            g_config.login.pgh.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_user)//�û���Ϣ  
    {
        if ( strcmp( name, "user_num" ) == 0 )
        {
            strcpy( g_config.user.user_num.name, name );
            strcpy( g_config.user.user_num.note, note );
            g_config.user.user_num.var = atoi( var );
        }
        if ( strcmp( name, "username_0" ) == 0 )// username_0ϵͳ����Ա
        {
            strcpy( g_config.user.username_0.name, name );
            strcpy( g_config.user.username_0.note, note );
            strcpy( g_config.user.username_0.var, var );
        }
        if ( strcmp( name, "password_0" ) == 0 )
        {
            strcpy( g_config.user.password_0.name, name );
            strcpy( g_config.user.password_0.note, note );
            strcpy( g_config.user.password_0.var, var );
        }
        if ( strcmp( name, "username_1" ) == 0 )// username_1 RTU�û�					
        {
            strcpy( g_config.user.username_1.name, name );
            strcpy( g_config.user.username_1.note, note );
            strcpy( g_config.user.username_1.var, var );
        }
        if ( strcmp( name, "password_1" ) == 0 )
        {
            strcpy( g_config.user.password_1.name, name );
            strcpy( g_config.user.password_1.note, note );
            strcpy( g_config.user.password_1.var, var );
        }
        if ( strcmp( name, "username_2" ) == 0 )// username_2 ��ͨ�û�
        {
            strcpy( g_config.user.username_2.name, name );
            strcpy( g_config.user.username_2.note, note );
            strcpy( g_config.user.username_2.var, var );
        }
        if ( strcmp( name, "password_2" ) == 0 )
        {
            strcpy( g_config.user.password_2.name, name );
            strcpy( g_config.user.password_2.note, note );
            strcpy( g_config.user.password_2.var, var );
        }
        if ( strcmp( name, "username_3" ) == 0 )// username_3 ��ͨ�û�
        {
            strcpy( g_config.user.username_3.name, name );
            strcpy( g_config.user.username_3.note, note );
            strcpy( g_config.user.username_3.var, var );
        }
        if ( strcmp( name, "password_3" ) == 0 )
        {
            strcpy( g_config.user.password_3.name, name );
            strcpy( g_config.user.password_3.note, note );
            strcpy( g_config.user.password_3.var, var );
        }
    }
    else if ( g_config.config_index == CFG_video)//��Ƶ����
    {
        if ( strcmp( name, "rtv_num" ) == 0 )//�ݶ�ֻ��2·��Ƶ
        {
            strcpy( g_config.video.rtv_num.name, name );
            strcpy( g_config.video.rtv_num.note, note );
            g_config.video.rtv_num.var = atoi( var );
        }
        if ( strcmp( name, "solution_x_1" ) == 0 )
        {
            strcpy( g_config.video.solution_x_1.name, name );
            strcpy( g_config.video.solution_x_1.note, note );
            g_config.video.solution_x_1.var = atoi( var );
        }
        if ( strcmp( name, "solution_y_1" ) == 0 )
        {
            strcpy( g_config.video.solution_y_1.name, name );
            strcpy( g_config.video.solution_y_1.note, note );
            g_config.video.solution_y_1.var = atoi( var );
        }
        if ( strcmp( name, "bright_1" ) == 0 )//���� : 0~255
        {
            strcpy( g_config.video.bright_1.name, name );
            strcpy( g_config.video.bright_1.note, note );
            g_config.video.bright_1.var = atoi( var );
        }
        if ( strcmp( name, "contrast_1" ) == 0 )//�Աȶ�: 0~255
        {
            strcpy( g_config.video.contrast_1.name, name );
            strcpy( g_config.video.contrast_1.note, note );
            g_config.video.contrast_1.var = atoi( var );
        }
        if ( strcmp( name, "frame_interval_1" ) == 0 )//����֡�����,0Ϊ�޼��
        {
            strcpy( g_config.video.frame_interval_1.name, name );
            strcpy( g_config.video.frame_interval_1.note, note );
            g_config.video.frame_interval_1.var = atoi( var );
        }
        if ( strcmp( name, "speed_1" ) == 0 )//֡��
        {
            strcpy( g_config.video.speed_1.name, name );
            strcpy( g_config.video.speed_1.note, note );
            g_config.video.speed_1.var = atoi( var );
        }
        if ( strcmp( name, "cache_time_1" ) == 0 )//��ƵͼƬԤ����ʱ�䳤��
        {
            strcpy( g_config.video.cache_time_1.name, name );
            strcpy( g_config.video.cache_time_1.note, note );
            g_config.video.cache_time_1.var = atoi( var );
        }
        if ( strcmp( name, "solution_x_2" ) == 0 )
        {
            strcpy( g_config.video.solution_x_2.name, name );
            strcpy( g_config.video.solution_x_2.note, note );
            g_config.video.solution_x_2.var = atoi( var );
        }
        if ( strcmp( name, "solution_y_2" ) == 0 )
        {
            strcpy( g_config.video.solution_y_2.name, name );
            strcpy( g_config.video.solution_y_2.note, note );
            g_config.video.solution_y_2.var = atoi( var );
        }
        if ( strcmp( name, "bright_2" ) == 0 )
        {
            strcpy( g_config.video.bright_2.name, name );
            strcpy( g_config.video.bright_2.note, note );
            g_config.video.bright_2.var = atoi( var );
        }
        if ( strcmp( name, "contrast_2" ) == 0 )
        {
            strcpy( g_config.video.contrast_2.name, name );
            strcpy( g_config.video.contrast_2.note, note );
            g_config.video.contrast_2.var = atoi( var );
        }
        if ( strcmp( name, "frame_interval_2" ) == 0 )
        {
            strcpy( g_config.video.frame_interval_2.name, name );
            strcpy( g_config.video.frame_interval_2.note, note );
            g_config.video.frame_interval_2.var = atoi( var );
        }
        if ( strcmp( name, "speed_2" ) == 0 )
        {
            strcpy( g_config.video.speed_2.name, name );
            strcpy( g_config.video.speed_2.note, note );
            g_config.video.speed_2.var = atoi( var );
        }
        if ( strcmp( name, "cache_time_2" ) == 0 )
        {
            strcpy( g_config.video.cache_time_2.name, name );
            strcpy( g_config.video.cache_time_2.note, note );
            g_config.video.cache_time_2.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_network)//�������
    {
        if ( strcmp( name, "ip_addr" ) == 0 )
        {
            strcpy( g_config.network.ip_addr.name, name );
            strcpy( g_config.network.ip_addr.note, note );
            strcpy( g_config.network.ip_addr.var, var );
        }
        if ( strcmp( name, "ip_mask" ) == 0 )
        {
            strcpy( g_config.network.ip_mask.name, name );
            strcpy( g_config.network.ip_mask.note, note );
            strcpy( g_config.network.ip_mask.var, var );
        }
        if ( strcmp( name, "ip_gateway" ) == 0 )
        {
            strcpy( g_config.network.ip_gateway.name, name );
            strcpy( g_config.network.ip_gateway.note, note );
            strcpy( g_config.network.ip_gateway.var, var );
        }
        if ( strcmp( name, "dns" ) == 0 )
        {
            strcpy( g_config.network.dns.name, name );
            strcpy( g_config.network.dns.note, note );
            strcpy( g_config.network.dns.var, var );
        }
        if ( strcmp( name, "mac_addr" ) == 0 )
        {
            strcpy( g_config.network.mac_addr.name, name );
            strcpy( g_config.network.mac_addr.note, note );
            strcpy( g_config.network.mac_addr.var, var );
        }
        if ( strcmp( name, "web_port" ) == 0 )//web���������ʶ˿�
        {
            strcpy( g_config.network.web_port.name, name );
            strcpy( g_config.network.web_port.note, note );
            g_config.network.web_port.var = atoi( var );
        }
        if ( strcmp( name, "socket_port" ) == 0 )//socket����˿�
        {
            strcpy( g_config.network.socket_port.name, name );
            strcpy( g_config.network.socket_port.note, note );
            g_config.network.socket_port.var = atoi( var );
        }
        if ( strcmp( name, "rtv_port" ) == 0 )//��Ƶ���Ͷ˿�
        {
            strcpy( g_config.network.rtv_port.name, name );
            strcpy( g_config.network.rtv_port.note, note );
            g_config.network.rtv_port.var = atoi( var );
        }
        if ( strcmp( name, "alarm_remote_addr" ) == 0 )//Զ�̵�ַ������IPC�������͸澯
        {
            strcpy( g_config.network.alarm_remote_addr.name, name );
            strcpy( g_config.network.alarm_remote_addr.note, note );
            strcpy( g_config.network.alarm_remote_addr.var, var );
        }
        if ( strcmp( name, "alarm_remote_port" ) == 0 )//Զ�̶˿�
        {
            strcpy( g_config.network.alarm_remote_port.name, name );
            strcpy( g_config.network.alarm_remote_port.note, note );
            g_config.network.alarm_remote_port.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_alert)//��������	
    {
        if ( strcmp( name, "alert_num" ) == 0 )//2·����
        {
            strcpy( g_config.alert.alert_num.name, name );
            strcpy( g_config.alert.alert_num.note, note );
            g_config.alert.alert_num.var = atoi( var );
        }
        if ( strcmp( name, "capture_pic_enable_1" ) == 0 )//����ץ��ͼƬ
        {
            strcpy( g_config.alert.capture_pic_enable_1.name, name );
            strcpy( g_config.alert.capture_pic_enable_1.note, note );
            g_config.alert.capture_pic_enable_1.var = atoi( var );
        }
        if ( strcmp( name, "capture_pic_num_1" ) == 0 )//ͼƬץ����Ŀ
        {
            strcpy( g_config.alert.capture_pic_num_1.name, name );
            strcpy( g_config.alert.capture_pic_num_1.note, note );
            g_config.alert.capture_pic_num_1.var = atoi( var );
        }
        if ( strcmp( name, "capture_pic_interval_1" ) == 0 )//ͼƬץ�ļ��, ����ɾ��
        {
            strcpy( g_config.alert.capture_pic_interval_1.name, name );
            strcpy( g_config.alert.capture_pic_interval_1.note, note );
            g_config.alert.capture_pic_interval_1.var = atoi( var );
        }
        if ( strcmp( name, "capture_video_enable_1" ) == 0 )//����¼��
        {
            strcpy( g_config.alert.capture_video_enable_1.name, name );
            strcpy( g_config.alert.capture_video_enable_1.note, note );
            g_config.alert.capture_video_enable_1.var = atoi( var );
        }
        if ( strcmp( name, "capture_video_last_time_1" ) == 0 )//¼�����ʱ��
        {
            strcpy( g_config.alert.capture_video_last_time_1.name, name );
            strcpy( g_config.alert.capture_video_last_time_1.note, note );
            g_config.alert.capture_video_last_time_1.var = atoi( var );
        }
        if ( strcmp( name, "alarm_enable_1" ) == 0 )//���þ���
        {
            strcpy( g_config.alert.alarm_enable_1.name, name );
            strcpy( g_config.alert.alarm_enable_1.note, note );
            g_config.alert.alarm_enable_1.var = atoi( var );
        }
        if ( strcmp( name, "alarm_delay_1" ) == 0 )//�����ӳ�ʱ��
        {
            strcpy( g_config.alert.alarm_delay_1.name, name );
            strcpy( g_config.alert.alarm_delay_1.note, note );
            g_config.alert.alarm_delay_1.var = atoi( var );
        }
        if ( strcmp( name, "alarm_last_time_1" ) == 0 )//�������ʱ��
        {
            strcpy( g_config.alert.alarm_last_time_1.name, name );
            strcpy( g_config.alert.alarm_last_time_1.note, note );
            g_config.alert.alarm_last_time_1.var = atoi( var );
        }
        if ( strcmp( name, "md_enable_1" ) == 0 )//�����ƶ����
        {
            strcpy( g_config.alert.md_enable_1.name, name );
            strcpy( g_config.alert.md_enable_1.note, note );
            g_config.alert.md_enable_1.var = atoi( var );
        }
        if ( strcmp( name, "md_sensitivity_1" ) == 0 )//������жȣ�30%��
        {
            strcpy( g_config.alert.md_sensitivity_1.name, name );
            strcpy( g_config.alert.md_sensitivity_1.note, note );
            g_config.alert.md_sensitivity_1.var = atoi( var );
        }
        if ( strcmp( name, "md_area_0_1" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_0_1.name, name );
            strcpy( g_config.alert.md_area_0_1.note, note );
            strcpy( g_config.alert.md_area_0_1.var, var );
        }
        if ( strcmp( name, "md_area_1_1" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_1_1.name, name );
            strcpy( g_config.alert.md_area_1_1.note, note );
            strcpy( g_config.alert.md_area_1_1.var, var );
        }
        if ( strcmp( name, "md_area_2_1" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_2_1.name, name );
            strcpy( g_config.alert.md_area_2_1.note, note );
            strcpy( g_config.alert.md_area_2_1.var, var );
        }
        if ( strcmp( name, "md_area_3_1" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_3_1.name, name );
            strcpy( g_config.alert.md_area_3_1.note, note );
            strcpy( g_config.alert.md_area_3_1.var, var );
        }
        if ( strcmp( name, "week_alert_plan_1" ) == 0 )
        {
            strcpy( g_config.alert.week_alert_plan_1.name, name );
            strcpy( g_config.alert.week_alert_plan_1.note, note );
            strcpy( g_config.alert.week_alert_plan_1.var, var );
        }
        if ( strcmp( name, "plan_cap_enalbe_1" ) == 0 )// ����ʱ�䵽ʱ���Ƿ�����¼��
        {
            strcpy( g_config.alert.plan_cap_enalbe_1.name, name );
            strcpy( g_config.alert.plan_cap_enalbe_1.note, note );
            g_config.alert.plan_cap_enalbe_1.var = atoi( var );
        }
        if ( strcmp( name, "plan_cap_last_sec_1" ) == 0 )// ¼�����������0����¼��ʱ���������һ������
        {
            strcpy( g_config.alert.plan_cap_last_sec_1.name, name );
            strcpy( g_config.alert.plan_cap_last_sec_1.note, note );
            g_config.alert.plan_cap_last_sec_1.var = atoi( var );
        }
        if ( strcmp( name, "capture_pic_enable_2" ) == 0 )//����ץ��ͼƬ
        {
            strcpy( g_config.alert.capture_pic_enable_2.name, name );
            strcpy( g_config.alert.capture_pic_enable_2.note, note );
            g_config.alert.capture_pic_enable_2.var = atoi( var );
        }
        if ( strcmp( name, "capture_pic_num_2" ) == 0 )//ͼƬץ����Ŀ
        {
            strcpy( g_config.alert.capture_pic_num_2.name, name );
            strcpy( g_config.alert.capture_pic_num_2.note, note );
            g_config.alert.capture_pic_num_2.var = atoi( var );
        }
        if ( strcmp( name, "capture_pic_interval_2" ) == 0 )//ͼƬץ�ļ��
        {
            strcpy( g_config.alert.capture_pic_interval_2.name, name );
            strcpy( g_config.alert.capture_pic_interval_2.note, note );
            g_config.alert.capture_pic_interval_2.var = atoi( var );
        }
        if ( strcmp( name, "capture_video_enable_2" ) == 0 )//����¼��
        {
            strcpy( g_config.alert.capture_video_enable_2.name, name );
            strcpy( g_config.alert.capture_video_enable_2.note, note );
            g_config.alert.capture_video_enable_2.var = atoi( var );
        }
        if ( strcmp( name, "capture_video_last_time_2" ) == 0 )//¼�����ʱ��
        {
            strcpy( g_config.alert.capture_video_last_time_2.name, name );
            strcpy( g_config.alert.capture_video_last_time_2.note, note );
            g_config.alert.capture_video_last_time_2.var = atoi( var );
        }
        if ( strcmp( name, "alarm_enable_2" ) == 0 )//���þ���
        {
            strcpy( g_config.alert.alarm_enable_2.name, name );
            strcpy( g_config.alert.alarm_enable_2.note, note );
            g_config.alert.alarm_enable_2.var = atoi( var );
        }
        if ( strcmp( name, "alarm_delay_2" ) == 0 )//�����ӳ�ʱ��
        {
            strcpy( g_config.alert.alarm_delay_2.name, name );
            strcpy( g_config.alert.alarm_delay_2.note, note );
            g_config.alert.alarm_delay_2.var = atoi( var );
        }
        if ( strcmp( name, "alarm_last_time_2" ) == 0 )//�������ʱ��
        {
            strcpy( g_config.alert.alarm_last_time_2.name, name );
            strcpy( g_config.alert.alarm_last_time_2.note, note );
            g_config.alert.alarm_last_time_2.var = atoi( var );
        }
        if ( strcmp( name, "md_enable_2" ) == 0 )//�����ƶ����
        {
            strcpy( g_config.alert.md_enable_2.name, name );
            strcpy( g_config.alert.md_enable_2.note, note );
            g_config.alert.md_enable_2.var = atoi( var );
        }
        if ( strcmp( name, "md_sensitivity_2" ) == 0 )//������жȣ�30%��
        {
            strcpy( g_config.alert.md_sensitivity_2.name, name );
            strcpy( g_config.alert.md_sensitivity_2.note, note );
            g_config.alert.md_sensitivity_2.var = atoi( var );
        }
        if ( strcmp( name, "md_area_0_2" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_0_2.name, name );
            strcpy( g_config.alert.md_area_0_2.note, note );
            strcpy( g_config.alert.md_area_0_2.var, var );
        }
        if ( strcmp( name, "md_area_1_2" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_1_2.name, name );
            strcpy( g_config.alert.md_area_1_2.note, note );
            strcpy( g_config.alert.md_area_1_2.var, var );
        }
        if ( strcmp( name, "md_area_2_2" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_2_2.name, name );
            strcpy( g_config.alert.md_area_2_2.note, note );
            strcpy( g_config.alert.md_area_2_2.var, var );
        }
        if ( strcmp( name, "md_area_3_2" ) == 0 )//������򣨾��Σ�
        {
            strcpy( g_config.alert.md_area_3_2.name, name );
            strcpy( g_config.alert.md_area_3_2.note, note );
            strcpy( g_config.alert.md_area_3_2.var, var );
        }
        if ( strcmp( name, "week_alert_plan_2" ) == 0 )
        {
            strcpy( g_config.alert.week_alert_plan_2.name, name );
            strcpy( g_config.alert.week_alert_plan_2.note, note );
            strcpy( g_config.alert.week_alert_plan_2.var, var );
        }
        if ( strcmp( name, "plan_cap_enalbe_2" ) == 0 )// ����ʱ�䵽ʱ���Ƿ�����¼��
        {
            strcpy( g_config.alert.plan_cap_enalbe_2.name, name );
            strcpy( g_config.alert.plan_cap_enalbe_2.note, note );
            g_config.alert.plan_cap_enalbe_2.var = atoi( var );
        }
        if ( strcmp( name, "plan_cap_last_sec_2" ) == 0 )// ¼�����������0����¼��ʱ���������һ������
        {
            strcpy( g_config.alert.plan_cap_last_sec_2.name, name );
            strcpy( g_config.alert.plan_cap_last_sec_2.note, note );
            g_config.alert.plan_cap_last_sec_2.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_store)//�洢����	
    {
        if ( strcmp( name, "sd_status" ) == 0 )//״̬��0��δ���룬1���Ѳ���
        {
            strcpy( g_config.store.sd_status.name, name );
            strcpy( g_config.store.sd_status.note, note );
            g_config.store.sd_status.var = atoi( var );
        }
        if ( strcmp( name, "sd_total_size" ) == 0 )//SD��������
        {
            strcpy( g_config.store.sd_total_size.name, name );
            strcpy( g_config.store.sd_total_size.note, note );
            g_config.store.sd_total_size.var = atoi( var );
        }
        if ( strcmp( name, "sd_used_size" ) == 0 )//SD����ʹ�����������������ڴ������壬��Ҫ�Ƿ�װ��һ���ṹ���ڣ�sd_store_enable
        {
            strcpy( g_config.store.sd_used_size.name, name );
            strcpy( g_config.store.sd_used_size.note, note );
            g_config.store.sd_used_size.var = atoi( var );
        }
        if ( strcmp( name, "sd_store_enable" ) == 0 )//����SD���洢
        {
            strcpy( g_config.store.sd_store_enable.name, name );
            strcpy( g_config.store.sd_store_enable.note, note );
            g_config.store.sd_store_enable.var = atoi( var );
        }
        if ( strcmp( name, "auto_cover_older" ) == 0 )//�Զ����Ǿ��ļ�
        {
            strcpy( g_config.store.auto_cover_older.name, name );
            strcpy( g_config.store.auto_cover_older.note, note );
            g_config.store.auto_cover_older.var = atoi( var );
        }
        if ( strcmp( name, "percent_alarm" ) == 0 )// ִ�и澯�ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_alarm,����и澯�percent_del
        {
            strcpy( g_config.store.percent_alarm.name, name );
            strcpy( g_config.store.percent_alarm.note, note );
            g_config.store.percent_alarm.var = atoi( var );
        }
        if ( strcmp( name, "percent_del" ) == 0 )// ִ��ɾ���ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_del,�����ɾ�����sys
        {
            strcpy( g_config.store.percent_del.name, name );
            strcpy( g_config.store.percent_del.note, note );
            g_config.store.percent_del.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_sys)//ϵͳ����	                        	
    {
        if ( strcmp( name, "app_version" ) == 0 )
        {
            strcpy( g_config.sys.app_version.name, name );
            strcpy( g_config.sys.app_version.note, note );
            strcpy( g_config.sys.app_version.var, var );
        }
        if ( strcmp( name, "app_time" ) == 0 )
        {
            strcpy( g_config.sys.app_time.name, name );
            strcpy( g_config.sys.app_time.note, note );
            strcpy( g_config.sys.app_time.var, var );
        }
    }
    else if ( g_config.config_index == CFG_rtv_start)// ʵʱ��Ƶ��������
    {
        if ( strcmp( name, "channel" ) == 0 )// ��Ƶ�ŵ� 0, 1
        {
            strcpy( g_config.rtv_start.channel.name, name );
            strcpy( g_config.rtv_start.channel.note, note );
            g_config.rtv_start.channel.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_htv_start)// ¼����������
    {
        if ( strcmp( name, "channel" ) == 0 )// ��Ƶ�ŵ� 0, 1	
        {
            strcpy( g_config.htv_start.channel.name, name );
            strcpy( g_config.htv_start.channel.note, note );
            g_config.htv_start.channel.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_htv_end)// ¼��ֹͣ����
    {
        if ( strcmp( name, "channel" ) == 0 )// ��Ƶ�ŵ� 0, 1
        {
            strcpy( g_config.htv_end.channel.name, name );
            strcpy( g_config.htv_end.channel.note, note );
            g_config.htv_end.channel.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_pic_start)// ͼƬץ����������
    {
        if ( strcmp( name, "channel" ) == 0 )// ��Ƶ�ŵ� 0, 1
        {
            strcpy( g_config.pic_start.channel.name, name );
            strcpy( g_config.pic_start.channel.note, note );
            g_config.pic_start.channel.var = atoi( var );
        }
        if ( strcmp( name, "num" ) == 0 )// ץ������
        {
            strcpy( g_config.pic_start.num.name, name );
            strcpy( g_config.pic_start.num.note, note );
            g_config.pic_start.num.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_ptz_control)// ��̨��������
    {
        if ( strcmp( name, "channel" ) == 0 )// ��Ƶ�ŵ� 0, 1
        {
            strcpy( g_config.ptz_control.channel.name, name );
            strcpy( g_config.ptz_control.channel.note, note );
            g_config.ptz_control.channel.var = atoi( var );
        }
        if ( strcmp( name, "left" ) == 0 )// ����ת��  0���޲��� 1������
        {
            strcpy( g_config.ptz_control.left.name, name );
            strcpy( g_config.ptz_control.left.note, note );
            g_config.ptz_control.left.var = atoi( var );
        }
        if ( strcmp( name, "right" ) == 0 )// ����ת��  0���޲��� 1������
        {
            strcpy( g_config.ptz_control.right.name, name );
            strcpy( g_config.ptz_control.right.note, note );
            g_config.ptz_control.right.var = atoi( var );
        }
        if ( strcmp( name, "up" ) == 0 )// ����ת��  0���޲��� 1������
        {
            strcpy( g_config.ptz_control.up.name, name );
            strcpy( g_config.ptz_control.up.note, note );
            g_config.ptz_control.up.var = atoi( var );
        }
        if ( strcmp( name, "down" ) == 0 )// ����ת��  0���޲��� 1������
        {
            strcpy( g_config.ptz_control.down.name, name );
            strcpy( g_config.ptz_control.down.note, note );
            g_config.ptz_control.down.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_sys_quit)// IPC�˳�����
    {
        if ( strcmp( name, "flag" ) == 0 )// 0��IPC���˳���1��IPC�˳�
        {
            strcpy( g_config.sys_quit.flag.name, name );
            strcpy( g_config.sys_quit.flag.note, note );
            g_config.sys_quit.flag.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_log)// ��־��ȡ
    {
        if ( strcmp( name, "flag" ) == 0 )// 0: ����ȡ��־, 1:��ȡ��־
        {
            strcpy( g_config.log.flag.name, name );
            strcpy( g_config.log.flag.note, note );
            g_config.log.flag.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_usb_remove)
    {
        if ( strcmp( name, "channel" ) == 0 )
        {
            strcpy( g_config.usb_remove.channel.name, name );
            strcpy( g_config.usb_remove.channel.note, note );
            g_config.usb_remove.channel.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_hb)// ����
    {
        if ( strcmp( name, "flag" ) == 0 )
        {
            strcpy( g_config.hb.flag.name, name );
            strcpy( g_config.hb.flag.note, note );
            g_config.hb.flag.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_def_config)// �ָ���������
    {
        if ( strcmp( name, "flag" ) == 0 )
        {
            strcpy( g_config.def_config.flag.name, name );
            strcpy( g_config.def_config.flag.note, note );
            g_config.def_config.flag.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_md_report)
    {
        if ( strcmp( name, "md_area_0_0" ) == 0 )// 0·��Ƶ��0�������Ƿ����ƶ� 0��û�� 1����
        {
            strcpy( g_config.md_report.md_area_0_0.name, name );
            strcpy( g_config.md_report.md_area_0_0.note, note );
            g_config.md_report.md_area_0_0.var = atoi( var );
        }
        if ( strcmp( name, "md_area_0_1" ) == 0 )
        {
            strcpy( g_config.md_report.md_area_0_1.name, name );
            strcpy( g_config.md_report.md_area_0_1.note, note );
            g_config.md_report.md_area_0_1.var = atoi( var );
        }
        if ( strcmp( name, "md_area_0_2" ) == 0 )
        {
            strcpy( g_config.md_report.md_area_0_2.name, name );
            strcpy( g_config.md_report.md_area_0_2.note, note );
            g_config.md_report.md_area_0_2.var = atoi( var );
        }
        if ( strcmp( name, "md_area_0_3" ) == 0 )
        {
            strcpy( g_config.md_report.md_area_0_3.name, name );
            strcpy( g_config.md_report.md_area_0_3.note, note );
            g_config.md_report.md_area_0_3.var = atoi( var );
        }
        if ( strcmp( name, "md_area_1_0" ) == 0 )
        {
            strcpy( g_config.md_report.md_area_1_0.name, name );
            strcpy( g_config.md_report.md_area_1_0.note, note );
            g_config.md_report.md_area_1_0.var = atoi( var );
        }
        if ( strcmp( name, "md_area_1_1" ) == 0 )
        {
            strcpy( g_config.md_report.md_area_1_1.name, name );
            strcpy( g_config.md_report.md_area_1_1.note, note );
            g_config.md_report.md_area_1_1.var = atoi( var );
        }
        if ( strcmp( name, "md_area_1_2" ) == 0 )
        {
            strcpy( g_config.md_report.md_area_1_2.name, name );
            strcpy( g_config.md_report.md_area_1_2.note, note );
            g_config.md_report.md_area_1_2.var = atoi( var );
        }
        if ( strcmp( name, "md_area_1_3" ) == 0 )
        {
            strcpy( g_config.md_report.md_area_1_3.name, name );
            strcpy( g_config.md_report.md_area_1_3.note, note );
            g_config.md_report.md_area_1_3.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_alarm_disk)// �������ɴ洢����ȫ�ֱ����ṩ
    {
        if ( strcmp( name, "flag" ) == 0 )
        {
            strcpy( g_config.alarm_disk.flag.name, name );
            strcpy( g_config.alarm_disk.flag.note, note );
            g_config.alarm_disk.flag.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_time_syn)// ʱ��ͬ��
    {
        if ( strcmp( name, "time" ) == 0 )// ����ϵͳ�����ڣ���ʽ����: 2008-10-12 13:14:34
        {
            strcpy( g_config.time_syn.time.name, name );
            strcpy( g_config.time_syn.time.note, note );
            strcpy( g_config.time_syn.time.var, var );
        }
    }
    else if ( g_config.config_index == CFG_alarm_error)// IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
    {
        if ( strcmp( name, "alarm_error_id" ) == 0 )// �澯����id
        {
            strcpy( g_config.alarm_error.alarm_error_id.name, name );
            strcpy( g_config.alarm_error.alarm_error_id.note, note );
            g_config.alarm_error.alarm_error_id.var = atoi( var );
        }
        if ( strcmp( name, "alarm_error_name" ) == 0 )
        {
            strcpy( g_config.alarm_error.alarm_error_name.name, name );
            strcpy( g_config.alarm_error.alarm_error_name.note, note );
            strcpy( g_config.alarm_error.alarm_error_name.var, var );
        }
    }
    else if ( g_config.config_index == CFG_process_info)// ��ȡipc������Ϣ
    {
        if ( strcmp( name, "flag" ) == 0 )
        {
            strcpy( g_config.process_info.flag.name, name );
            strcpy( g_config.process_info.flag.note, note );
            g_config.process_info.flag.var = atoi( var );
        }
    }
    else if ( g_config.config_index == CFG_end)
    {
        if ( strcmp( name, "flag" ) == 0 )// �������
        {
            strcpy( g_config.end.flag.name, name );
            strcpy( g_config.end.flag.note, note );
            g_config.end.flag.var = atoi( var );
        }
    }
}

