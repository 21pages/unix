            //[login] web��¼
            if( 0 == strcmp( cginame, "login_pgh" ) )
            {
                get_login_pgh( outbuf );
            }
            //[user]�û���Ϣ  
            else if( 0 == strcmp( cginame, "user_user_num" ) )
            {
                get_user_user_num( outbuf );
            }
            else if( 0 == strcmp( cginame, "user_username_0" ) )
            {
                get_user_username_0( outbuf );// username_0ϵͳ����Ա
            }
            else if( 0 == strcmp( cginame, "user_password_0" ) )
            {
                get_user_password_0( outbuf );
            }
            else if( 0 == strcmp( cginame, "user_username_1" ) )
            {
                get_user_username_1( outbuf );// username_1 RTU�û�					
            }
            else if( 0 == strcmp( cginame, "user_password_1" ) )
            {
                get_user_password_1( outbuf );
            }
            else if( 0 == strcmp( cginame, "user_username_2" ) )
            {
                get_user_username_2( outbuf );// username_2 ��ͨ�û�
            }
            else if( 0 == strcmp( cginame, "user_password_2" ) )
            {
                get_user_password_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "user_username_3" ) )
            {
                get_user_username_3( outbuf );// username_3 ��ͨ�û�
            }
            else if( 0 == strcmp( cginame, "user_password_3" ) )
            {
                get_user_password_3( outbuf );
            }
            //[video]��Ƶ����
            else if( 0 == strcmp( cginame, "video_rtv_num" ) )
            {
                get_video_rtv_num( outbuf );//�ݶ�ֻ��2·��Ƶ
            }
            else if( 0 == strcmp( cginame, "video_solution_x_1" ) )
            {
                get_video_solution_x_1( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_solution_y_1" ) )
            {
                get_video_solution_y_1( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_bright_1" ) )
            {
                get_video_bright_1( outbuf );//���� : 0~255
            }
            else if( 0 == strcmp( cginame, "video_contrast_1" ) )
            {
                get_video_contrast_1( outbuf );//�Աȶ�: 0~255
            }
            else if( 0 == strcmp( cginame, "video_frame_interval_1" ) )
            {
                get_video_frame_interval_1( outbuf );//����֡�����,0Ϊ�޼��
            }
            else if( 0 == strcmp( cginame, "video_speed_1" ) )
            {
                get_video_speed_1( outbuf );//֡��
            }
            else if( 0 == strcmp( cginame, "video_cache_time_1" ) )
            {
                get_video_cache_time_1( outbuf );//��ƵͼƬԤ����ʱ�䳤��
            }
            else if( 0 == strcmp( cginame, "video_solution_x_2" ) )
            {
                get_video_solution_x_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_solution_y_2" ) )
            {
                get_video_solution_y_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_bright_2" ) )
            {
                get_video_bright_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_contrast_2" ) )
            {
                get_video_contrast_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_frame_interval_2" ) )
            {
                get_video_frame_interval_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_speed_2" ) )
            {
                get_video_speed_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "video_cache_time_2" ) )
            {
                get_video_cache_time_2( outbuf );
            }
            //[network]�������
            else if( 0 == strcmp( cginame, "network_ip_addr" ) )
            {
                get_network_ip_addr( outbuf );
            }
            else if( 0 == strcmp( cginame, "network_ip_mask" ) )
            {
                get_network_ip_mask( outbuf );
            }
            else if( 0 == strcmp( cginame, "network_ip_gateway" ) )
            {
                get_network_ip_gateway( outbuf );
            }
            else if( 0 == strcmp( cginame, "network_dns" ) )
            {
                get_network_dns( outbuf );
            }
            else if( 0 == strcmp( cginame, "network_mac_addr" ) )
            {
                get_network_mac_addr( outbuf );
            }
            else if( 0 == strcmp( cginame, "network_web_port" ) )
            {
                get_network_web_port( outbuf );//web���������ʶ˿�
            }
            else if( 0 == strcmp( cginame, "network_socket_port" ) )
            {
                get_network_socket_port( outbuf );//socket����˿�
            }
            else if( 0 == strcmp( cginame, "network_rtv_port" ) )
            {
                get_network_rtv_port( outbuf );//��Ƶ���Ͷ˿�
            }
            else if( 0 == strcmp( cginame, "network_alarm_remote_addr" ) )
            {
                get_network_alarm_remote_addr( outbuf );//Զ�̵�ַ������IPC�������͸澯
            }
            else if( 0 == strcmp( cginame, "network_alarm_remote_port" ) )
            {
                get_network_alarm_remote_port( outbuf );//Զ�̶˿�
            }
            //[alert]��������	
            else if( 0 == strcmp( cginame, "alert_alert_num" ) )
            {
                get_alert_alert_num( outbuf );//2·����
            }
            else if( 0 == strcmp( cginame, "alert_capture_pic_enable_1" ) )
            {
                get_alert_capture_pic_enable_1( outbuf );//����ץ��ͼƬ
            }
            else if( 0 == strcmp( cginame, "alert_capture_pic_num_1" ) )
            {
                get_alert_capture_pic_num_1( outbuf );//ͼƬץ����Ŀ
            }
            else if( 0 == strcmp( cginame, "alert_capture_pic_interval_1" ) )
            {
                get_alert_capture_pic_interval_1( outbuf );//ͼƬץ�ļ��, ����ɾ��
            }
            else if( 0 == strcmp( cginame, "alert_capture_video_enable_1" ) )
            {
                get_alert_capture_video_enable_1( outbuf );//����¼��
            }
            else if( 0 == strcmp( cginame, "alert_capture_video_last_time_1" ) )
            {
                get_alert_capture_video_last_time_1( outbuf );//¼�����ʱ��
            }
            else if( 0 == strcmp( cginame, "alert_alarm_enable_1" ) )
            {
                get_alert_alarm_enable_1( outbuf );//���þ���
            }
            else if( 0 == strcmp( cginame, "alert_alarm_delay_1" ) )
            {
                get_alert_alarm_delay_1( outbuf );//�����ӳ�ʱ��
            }
            else if( 0 == strcmp( cginame, "alert_alarm_last_time_1" ) )
            {
                get_alert_alarm_last_time_1( outbuf );//�������ʱ��
            }
            else if( 0 == strcmp( cginame, "alert_md_enable_1" ) )
            {
                get_alert_md_enable_1( outbuf );//�����ƶ����
            }
            else if( 0 == strcmp( cginame, "alert_md_sensitivity_1" ) )
            {
                get_alert_md_sensitivity_1( outbuf );//������жȣ�30%��
            }
            else if( 0 == strcmp( cginame, "alert_md_area_0_1" ) )
            {
                get_alert_md_area_0_1( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_md_area_1_1" ) )
            {
                get_alert_md_area_1_1( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_md_area_2_1" ) )
            {
                get_alert_md_area_2_1( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_md_area_3_1" ) )
            {
                get_alert_md_area_3_1( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_week_alert_plan_1" ) )
            {
                get_alert_week_alert_plan_1( outbuf );
            }
            else if( 0 == strcmp( cginame, "alert_plan_cap_enalbe_1" ) )
            {
                get_alert_plan_cap_enalbe_1( outbuf );// ����ʱ�䵽ʱ���Ƿ�����¼��
            }
            else if( 0 == strcmp( cginame, "alert_plan_cap_last_sec_1" ) )
            {
                get_alert_plan_cap_last_sec_1( outbuf );// ¼�����������0����¼��ʱ���������һ������
            }
            else if( 0 == strcmp( cginame, "alert_capture_pic_enable_2" ) )
            {
                get_alert_capture_pic_enable_2( outbuf );//����ץ��ͼƬ
            }
            else if( 0 == strcmp( cginame, "alert_capture_pic_num_2" ) )
            {
                get_alert_capture_pic_num_2( outbuf );//ͼƬץ����Ŀ
            }
            else if( 0 == strcmp( cginame, "alert_capture_pic_interval_2" ) )
            {
                get_alert_capture_pic_interval_2( outbuf );//ͼƬץ�ļ��
            }
            else if( 0 == strcmp( cginame, "alert_capture_video_enable_2" ) )
            {
                get_alert_capture_video_enable_2( outbuf );//����¼��
            }
            else if( 0 == strcmp( cginame, "alert_capture_video_last_time_2" ) )
            {
                get_alert_capture_video_last_time_2( outbuf );//¼�����ʱ��
            }
            else if( 0 == strcmp( cginame, "alert_alarm_enable_2" ) )
            {
                get_alert_alarm_enable_2( outbuf );//���þ���
            }
            else if( 0 == strcmp( cginame, "alert_alarm_delay_2" ) )
            {
                get_alert_alarm_delay_2( outbuf );//�����ӳ�ʱ��
            }
            else if( 0 == strcmp( cginame, "alert_alarm_last_time_2" ) )
            {
                get_alert_alarm_last_time_2( outbuf );//�������ʱ��
            }
            else if( 0 == strcmp( cginame, "alert_md_enable_2" ) )
            {
                get_alert_md_enable_2( outbuf );//�����ƶ����
            }
            else if( 0 == strcmp( cginame, "alert_md_sensitivity_2" ) )
            {
                get_alert_md_sensitivity_2( outbuf );//������жȣ�30%��
            }
            else if( 0 == strcmp( cginame, "alert_md_area_0_2" ) )
            {
                get_alert_md_area_0_2( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_md_area_1_2" ) )
            {
                get_alert_md_area_1_2( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_md_area_2_2" ) )
            {
                get_alert_md_area_2_2( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_md_area_3_2" ) )
            {
                get_alert_md_area_3_2( outbuf );//������򣨾��Σ�
            }
            else if( 0 == strcmp( cginame, "alert_week_alert_plan_2" ) )
            {
                get_alert_week_alert_plan_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "alert_plan_cap_enalbe_2" ) )
            {
                get_alert_plan_cap_enalbe_2( outbuf );// ����ʱ�䵽ʱ���Ƿ�����¼��
            }
            else if( 0 == strcmp( cginame, "alert_plan_cap_last_sec_2" ) )
            {
                get_alert_plan_cap_last_sec_2( outbuf );// ¼�����������0����¼��ʱ���������һ������
            }
            //[store]�洢����	
            else if( 0 == strcmp( cginame, "store_sd_status" ) )
            {
                get_store_sd_status( outbuf );//״̬��0��δ���룬1���Ѳ���
            }
            else if( 0 == strcmp( cginame, "store_sd_total_size" ) )
            {
                get_store_sd_total_size( outbuf );//SD��������
            }
            else if( 0 == strcmp( cginame, "store_sd_used_size" ) )
            {
                get_store_sd_used_size( outbuf );//SD����ʹ�����������������ڴ������壬��Ҫ�Ƿ�װ��һ���ṹ���ڣ�sd_store_enable
            }
            else if( 0 == strcmp( cginame, "store_sd_store_enable" ) )
            {
                get_store_sd_store_enable( outbuf );//����SD���洢
            }
            else if( 0 == strcmp( cginame, "store_auto_cover_older" ) )
            {
                get_store_auto_cover_older( outbuf );//�Զ����Ǿ��ļ�
            }
            else if( 0 == strcmp( cginame, "store_percent_alarm" ) )
            {
                get_store_percent_alarm( outbuf );// ִ�и澯�ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_alarm,����и澯�percent_del
            }
            else if( 0 == strcmp( cginame, "store_percent_del" ) )
            {
                get_store_percent_del( outbuf );// ִ��ɾ���ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_del,�����ɾ�����sys
            }
            //[sys]ϵͳ����	                        	
            else if( 0 == strcmp( cginame, "sys_app_version" ) )
            {
                get_sys_app_version( outbuf );
            }
            else if( 0 == strcmp( cginame, "sys_app_time" ) )
            {
                get_sys_app_time( outbuf );
            }
            //[rtv_start] ʵʱ��Ƶ��������
            else if( 0 == strcmp( cginame, "rtv_start_channel" ) )
            {
                get_rtv_start_channel( outbuf );// ��Ƶ�ŵ� 0, 1
            }
            //[htv_start] ¼����������
            else if( 0 == strcmp( cginame, "htv_start_channel" ) )
            {
                get_htv_start_channel( outbuf );// ��Ƶ�ŵ� 0, 1	
            }
            //[htv_end] ¼��ֹͣ����
            else if( 0 == strcmp( cginame, "htv_end_channel" ) )
            {
                get_htv_end_channel( outbuf );// ��Ƶ�ŵ� 0, 1
            }
            //[pic_start] ͼƬץ����������
            else if( 0 == strcmp( cginame, "pic_start_channel" ) )
            {
                get_pic_start_channel( outbuf );// ��Ƶ�ŵ� 0, 1
            }
            else if( 0 == strcmp( cginame, "pic_start_num" ) )
            {
                get_pic_start_num( outbuf );// ץ������
            }
            //[ptz_control] ��̨��������
            else if( 0 == strcmp( cginame, "ptz_control_channel" ) )
            {
                get_ptz_control_channel( outbuf );// ��Ƶ�ŵ� 0, 1
            }
            else if( 0 == strcmp( cginame, "ptz_control_left" ) )
            {
                get_ptz_control_left( outbuf );// ����ת��  0���޲��� 1������
            }
            else if( 0 == strcmp( cginame, "ptz_control_right" ) )
            {
                get_ptz_control_right( outbuf );// ����ת��  0���޲��� 1������
            }
            else if( 0 == strcmp( cginame, "ptz_control_up" ) )
            {
                get_ptz_control_up( outbuf );// ����ת��  0���޲��� 1������
            }
            else if( 0 == strcmp( cginame, "ptz_control_down" ) )
            {
                get_ptz_control_down( outbuf );// ����ת��  0���޲��� 1������
            }
            //[sys_quit] IPC�˳�����
            else if( 0 == strcmp( cginame, "sys_quit_flag" ) )
            {
                get_sys_quit_flag( outbuf );// 0��IPC���˳���1��IPC�˳�
            }
            //[log] ��־��ȡ
            else if( 0 == strcmp( cginame, "log_flag" ) )
            {
                get_log_flag( outbuf );// 0: ����ȡ��־, 1:��ȡ��־
            }
            //[usb_remove]
            else if( 0 == strcmp( cginame, "usb_remove_channel" ) )
            {
                get_usb_remove_channel( outbuf );
            }
            //[hb] ����
            else if( 0 == strcmp( cginame, "hb_flag" ) )
            {
                get_hb_flag( outbuf );
            }
            //[def_config] �ָ���������
            else if( 0 == strcmp( cginame, "def_config_flag" ) )
            {
                get_def_config_flag( outbuf );
            }
            //[md_report]
            else if( 0 == strcmp( cginame, "md_report_md_area_0_0" ) )
            {
                get_md_report_md_area_0_0( outbuf );// 0·��Ƶ��0�������Ƿ����ƶ� 0��û�� 1����
            }
            else if( 0 == strcmp( cginame, "md_report_md_area_0_1" ) )
            {
                get_md_report_md_area_0_1( outbuf );
            }
            else if( 0 == strcmp( cginame, "md_report_md_area_0_2" ) )
            {
                get_md_report_md_area_0_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "md_report_md_area_0_3" ) )
            {
                get_md_report_md_area_0_3( outbuf );
            }
            else if( 0 == strcmp( cginame, "md_report_md_area_1_0" ) )
            {
                get_md_report_md_area_1_0( outbuf );
            }
            else if( 0 == strcmp( cginame, "md_report_md_area_1_1" ) )
            {
                get_md_report_md_area_1_1( outbuf );
            }
            else if( 0 == strcmp( cginame, "md_report_md_area_1_2" ) )
            {
                get_md_report_md_area_1_2( outbuf );
            }
            else if( 0 == strcmp( cginame, "md_report_md_area_1_3" ) )
            {
                get_md_report_md_area_1_3( outbuf );
            }
            //[alarm_disk] �������ɴ洢����ȫ�ֱ����ṩ
            else if( 0 == strcmp( cginame, "alarm_disk_flag" ) )
            {
                get_alarm_disk_flag( outbuf );
            }
            //[time_syn] ʱ��ͬ��
            else if( 0 == strcmp( cginame, "time_syn_time" ) )
            {
                get_time_syn_time( outbuf );// ����ϵͳ�����ڣ���ʽ����: 2008-10-12 13:14:34
            }
            //[alarm_error] IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
            else if( 0 == strcmp( cginame, "alarm_error_alarm_error_id" ) )
            {
                get_alarm_error_alarm_error_id( outbuf );// �澯����id
            }
            else if( 0 == strcmp( cginame, "alarm_error_alarm_error_name" ) )
            {
                get_alarm_error_alarm_error_name( outbuf );
            }
            //[process_info] ��ȡipc������Ϣ
            else if( 0 == strcmp( cginame, "process_info_flag" ) )
            {
                get_process_info_flag( outbuf );
            }
            //[end]
            else if( 0 == strcmp( cginame, "end_flag" ) )
            {
                get_end_flag( outbuf );// �������
            }
