//[login] web��¼
void get_login_pgh( char * outbuf );
//[user]�û���Ϣ  
void get_user_user_num( char * outbuf );
void get_user_username_0( char * outbuf );// username_0ϵͳ����Ա
void get_user_password_0( char * outbuf );
void get_user_username_1( char * outbuf );// username_1 RTU�û�					
void get_user_password_1( char * outbuf );
void get_user_username_2( char * outbuf );// username_2 ��ͨ�û�
void get_user_password_2( char * outbuf );
void get_user_username_3( char * outbuf );// username_3 ��ͨ�û�
void get_user_password_3( char * outbuf );
//[video]��Ƶ����
void get_video_rtv_num( char * outbuf );//�ݶ�ֻ��2·��Ƶ
void get_video_solution_x_1( char * outbuf );
void get_video_solution_y_1( char * outbuf );
void get_video_bright_1( char * outbuf );//���� : 0~255
void get_video_contrast_1( char * outbuf );//�Աȶ�: 0~255
void get_video_frame_interval_1( char * outbuf );//����֡�����,0Ϊ�޼��
void get_video_speed_1( char * outbuf );//֡��
void get_video_cache_time_1( char * outbuf );//��ƵͼƬԤ����ʱ�䳤��
void get_video_solution_x_2( char * outbuf );
void get_video_solution_y_2( char * outbuf );
void get_video_bright_2( char * outbuf );
void get_video_contrast_2( char * outbuf );
void get_video_frame_interval_2( char * outbuf );
void get_video_speed_2( char * outbuf );
void get_video_cache_time_2( char * outbuf );
//[network]�������
void get_network_ip_addr( char * outbuf );
void get_network_ip_mask( char * outbuf );
void get_network_ip_gateway( char * outbuf );
void get_network_dns( char * outbuf );
void get_network_mac_addr( char * outbuf );
void get_network_web_port( char * outbuf );//web���������ʶ˿�
void get_network_socket_port( char * outbuf );//socket����˿�
void get_network_rtv_port( char * outbuf );//��Ƶ���Ͷ˿�
void get_network_alarm_remote_addr( char * outbuf );//Զ�̵�ַ������IPC�������͸澯
void get_network_alarm_remote_port( char * outbuf );//Զ�̶˿�
//[alert]��������	
void get_alert_alert_num( char * outbuf );//2·����
void get_alert_capture_pic_enable_1( char * outbuf );//����ץ��ͼƬ
void get_alert_capture_pic_num_1( char * outbuf );//ͼƬץ����Ŀ
void get_alert_capture_pic_interval_1( char * outbuf );//ͼƬץ�ļ��, ����ɾ��
void get_alert_capture_video_enable_1( char * outbuf );//����¼��
void get_alert_capture_video_last_time_1( char * outbuf );//¼�����ʱ��
void get_alert_alarm_enable_1( char * outbuf );//���þ���
void get_alert_alarm_delay_1( char * outbuf );//�����ӳ�ʱ��
void get_alert_alarm_last_time_1( char * outbuf );//�������ʱ��
void get_alert_md_enable_1( char * outbuf );//�����ƶ����
void get_alert_md_sensitivity_1( char * outbuf );//������жȣ�30%��
void get_alert_md_area_0_1( char * outbuf );//������򣨾��Σ�
void get_alert_md_area_1_1( char * outbuf );//������򣨾��Σ�
void get_alert_md_area_2_1( char * outbuf );//������򣨾��Σ�
void get_alert_md_area_3_1( char * outbuf );//������򣨾��Σ�
void get_alert_week_alert_plan_1( char * outbuf );
void get_alert_plan_cap_enalbe_1( char * outbuf );// ����ʱ�䵽ʱ���Ƿ�����¼��
void get_alert_plan_cap_last_sec_1( char * outbuf );// ¼�����������0����¼��ʱ���������һ������
void get_alert_capture_pic_enable_2( char * outbuf );//����ץ��ͼƬ
void get_alert_capture_pic_num_2( char * outbuf );//ͼƬץ����Ŀ
void get_alert_capture_pic_interval_2( char * outbuf );//ͼƬץ�ļ��
void get_alert_capture_video_enable_2( char * outbuf );//����¼��
void get_alert_capture_video_last_time_2( char * outbuf );//¼�����ʱ��
void get_alert_alarm_enable_2( char * outbuf );//���þ���
void get_alert_alarm_delay_2( char * outbuf );//�����ӳ�ʱ��
void get_alert_alarm_last_time_2( char * outbuf );//�������ʱ��
void get_alert_md_enable_2( char * outbuf );//�����ƶ����
void get_alert_md_sensitivity_2( char * outbuf );//������жȣ�30%��
void get_alert_md_area_0_2( char * outbuf );//������򣨾��Σ�
void get_alert_md_area_1_2( char * outbuf );//������򣨾��Σ�
void get_alert_md_area_2_2( char * outbuf );//������򣨾��Σ�
void get_alert_md_area_3_2( char * outbuf );//������򣨾��Σ�
void get_alert_week_alert_plan_2( char * outbuf );
void get_alert_plan_cap_enalbe_2( char * outbuf );// ����ʱ�䵽ʱ���Ƿ�����¼��
void get_alert_plan_cap_last_sec_2( char * outbuf );// ¼�����������0����¼��ʱ���������һ������
//[store]�洢����	
void get_store_sd_status( char * outbuf );//״̬��0��δ���룬1���Ѳ���
void get_store_sd_total_size( char * outbuf );//SD��������
void get_store_sd_used_size( char * outbuf );//SD����ʹ�����������������ڴ������壬��Ҫ�Ƿ�װ��һ���ṹ���ڣ�sd_store_enable
void get_store_sd_store_enable( char * outbuf );//����SD���洢
void get_store_auto_cover_older( char * outbuf );//�Զ����Ǿ��ļ�
void get_store_percent_alarm( char * outbuf );// ִ�и澯�ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_alarm,����и澯�percent_del
void get_store_percent_del( char * outbuf );// ִ��ɾ���ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_del,�����ɾ�����sys
//[sys]ϵͳ����	                        	
void get_sys_app_version( char * outbuf );
void get_sys_app_time( char * outbuf );
//[rtv_start] ʵʱ��Ƶ��������
void get_rtv_start_channel( char * outbuf );// ��Ƶ�ŵ� 0, 1
//[htv_start] ¼����������
void get_htv_start_channel( char * outbuf );// ��Ƶ�ŵ� 0, 1	
//[htv_end] ¼��ֹͣ����
void get_htv_end_channel( char * outbuf );// ��Ƶ�ŵ� 0, 1
//[pic_start] ͼƬץ����������
void get_pic_start_channel( char * outbuf );// ��Ƶ�ŵ� 0, 1
void get_pic_start_num( char * outbuf );// ץ������
//[ptz_control] ��̨��������
void get_ptz_control_channel( char * outbuf );// ��Ƶ�ŵ� 0, 1
void get_ptz_control_left( char * outbuf );// ����ת��  0���޲��� 1������
void get_ptz_control_right( char * outbuf );// ����ת��  0���޲��� 1������
void get_ptz_control_up( char * outbuf );// ����ת��  0���޲��� 1������
void get_ptz_control_down( char * outbuf );// ����ת��  0���޲��� 1������
//[sys_quit] IPC�˳�����
void get_sys_quit_flag( char * outbuf );// 0��IPC���˳���1��IPC�˳�
//[log] ��־��ȡ
void get_log_flag( char * outbuf );// 0: ����ȡ��־, 1:��ȡ��־
//[usb_remove]
void get_usb_remove_channel( char * outbuf );
//[hb] ����
void get_hb_flag( char * outbuf );
//[def_config] �ָ���������
void get_def_config_flag( char * outbuf );
//[md_report]
void get_md_report_md_area_0_0( char * outbuf );// 0·��Ƶ��0�������Ƿ����ƶ� 0��û�� 1����
void get_md_report_md_area_0_1( char * outbuf );
void get_md_report_md_area_0_2( char * outbuf );
void get_md_report_md_area_0_3( char * outbuf );
void get_md_report_md_area_1_0( char * outbuf );
void get_md_report_md_area_1_1( char * outbuf );
void get_md_report_md_area_1_2( char * outbuf );
void get_md_report_md_area_1_3( char * outbuf );
//[alarm_disk] �������ɴ洢����ȫ�ֱ����ṩ
void get_alarm_disk_flag( char * outbuf );
//[time_syn] ʱ��ͬ��
void get_time_syn_time( char * outbuf );// ����ϵͳ�����ڣ���ʽ����: 2008-10-12 13:14:34
//[alarm_error] IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
void get_alarm_error_alarm_error_id( char * outbuf );// �澯����id
void get_alarm_error_alarm_error_name( char * outbuf );
//[process_info] ��ȡipc������Ϣ
void get_process_info_flag( char * outbuf );
//[end]
void get_end_flag( char * outbuf );// �������


