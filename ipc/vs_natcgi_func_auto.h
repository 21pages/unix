//[login] web��¼
void get_login_pgh( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.login.pgh.var );
    strcat( outbuf, temp );
}
//[user]�û���Ϣ  
void get_user_user_num( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.user.user_num.var );
    strcat( outbuf, temp );
}
void get_user_username_0( char * outbuf )// username_0ϵͳ����Ա
{
    strcat( outbuf, g_config.user.username_0.var );
}
void get_user_password_0( char * outbuf )
{
    strcat( outbuf, g_config.user.password_0.var );
}
void get_user_username_1( char * outbuf )// username_1 RTU�û�					
{
    strcat( outbuf, g_config.user.username_1.var );
}
void get_user_password_1( char * outbuf )
{
    strcat( outbuf, g_config.user.password_1.var );
}
void get_user_username_2( char * outbuf )// username_2 ��ͨ�û�
{
    strcat( outbuf, g_config.user.username_2.var );
}
void get_user_password_2( char * outbuf )
{
    strcat( outbuf, g_config.user.password_2.var );
}
void get_user_username_3( char * outbuf )// username_3 ��ͨ�û�
{
    strcat( outbuf, g_config.user.username_3.var );
}
void get_user_password_3( char * outbuf )
{
    strcat( outbuf, g_config.user.password_3.var );
}
//[video]��Ƶ����
void get_video_rtv_num( char * outbuf )//�ݶ�ֻ��2·��Ƶ
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.rtv_num.var );
    strcat( outbuf, temp );
}
void get_video_solution_x_1( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.solution_x_1.var );
    strcat( outbuf, temp );
}
void get_video_solution_y_1( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.solution_y_1.var );
    strcat( outbuf, temp );
}
void get_video_bright_1( char * outbuf )//���� : 0~255
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.bright_1.var );
    strcat( outbuf, temp );
}
void get_video_contrast_1( char * outbuf )//�Աȶ�: 0~255
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.contrast_1.var );
    strcat( outbuf, temp );
}
void get_video_frame_interval_1( char * outbuf )//����֡�����,0Ϊ�޼��
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.frame_interval_1.var );
    strcat( outbuf, temp );
}
void get_video_speed_1( char * outbuf )//֡��
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.speed_1.var );
    strcat( outbuf, temp );
}
void get_video_cache_time_1( char * outbuf )//��ƵͼƬԤ����ʱ�䳤��
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.cache_time_1.var );
    strcat( outbuf, temp );
}
void get_video_solution_x_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.solution_x_2.var );
    strcat( outbuf, temp );
}
void get_video_solution_y_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.solution_y_2.var );
    strcat( outbuf, temp );
}
void get_video_bright_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.bright_2.var );
    strcat( outbuf, temp );
}
void get_video_contrast_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.contrast_2.var );
    strcat( outbuf, temp );
}
void get_video_frame_interval_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.frame_interval_2.var );
    strcat( outbuf, temp );
}
void get_video_speed_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.speed_2.var );
    strcat( outbuf, temp );
}
void get_video_cache_time_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.video.cache_time_2.var );
    strcat( outbuf, temp );
}
//[network]�������
void get_network_ip_addr( char * outbuf )
{
    strcat( outbuf, g_config.network.ip_addr.var );
}
void get_network_ip_mask( char * outbuf )
{
    strcat( outbuf, g_config.network.ip_mask.var );
}
void get_network_ip_gateway( char * outbuf )
{
    strcat( outbuf, g_config.network.ip_gateway.var );
}
void get_network_dns( char * outbuf )
{
    strcat( outbuf, g_config.network.dns.var );
}
void get_network_mac_addr( char * outbuf )
{
    strcat( outbuf, g_config.network.mac_addr.var );
}
void get_network_web_port( char * outbuf )//web���������ʶ˿�
{
    char temp[16];
    sprintf( temp, "%d", g_config.network.web_port.var );
    strcat( outbuf, temp );
}
void get_network_socket_port( char * outbuf )//socket����˿�
{
    char temp[16];
    sprintf( temp, "%d", g_config.network.socket_port.var );
    strcat( outbuf, temp );
}
void get_network_rtv_port( char * outbuf )//��Ƶ���Ͷ˿�
{
    char temp[16];
    sprintf( temp, "%d", g_config.network.rtv_port.var );
    strcat( outbuf, temp );
}
void get_network_alarm_remote_addr( char * outbuf )//Զ�̵�ַ������IPC�������͸澯
{
    strcat( outbuf, g_config.network.alarm_remote_addr.var );
}
void get_network_alarm_remote_port( char * outbuf )//Զ�̶˿�
{
    char temp[16];
    sprintf( temp, "%d", g_config.network.alarm_remote_port.var );
    strcat( outbuf, temp );
}
//[alert]��������	
void get_alert_alert_num( char * outbuf )//2·����
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.alert_num.var );
    strcat( outbuf, temp );
}
void get_alert_capture_pic_enable_1( char * outbuf )//����ץ��ͼƬ
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_pic_enable_1.var );
    strcat( outbuf, temp );
}
void get_alert_capture_pic_num_1( char * outbuf )//ͼƬץ����Ŀ
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_pic_num_1.var );
    strcat( outbuf, temp );
}
void get_alert_capture_pic_interval_1( char * outbuf )//ͼƬץ�ļ��, ����ɾ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_pic_interval_1.var );
    strcat( outbuf, temp );
}
void get_alert_capture_video_enable_1( char * outbuf )//����¼��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_video_enable_1.var );
    strcat( outbuf, temp );
}
void get_alert_capture_video_last_time_1( char * outbuf )//¼�����ʱ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_video_last_time_1.var );
    strcat( outbuf, temp );
}
void get_alert_alarm_enable_1( char * outbuf )//���þ���
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.alarm_enable_1.var );
    strcat( outbuf, temp );
}
void get_alert_alarm_delay_1( char * outbuf )//�����ӳ�ʱ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.alarm_delay_1.var );
    strcat( outbuf, temp );
}
void get_alert_alarm_last_time_1( char * outbuf )//�������ʱ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.alarm_last_time_1.var );
    strcat( outbuf, temp );
}
void get_alert_md_enable_1( char * outbuf )//�����ƶ����
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.md_enable_1.var );
    strcat( outbuf, temp );
}
void get_alert_md_sensitivity_1( char * outbuf )//������жȣ�30%��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.md_sensitivity_1.var );
    strcat( outbuf, temp );
}
void get_alert_md_area_0_1( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_0_1.var );
}
void get_alert_md_area_1_1( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_1_1.var );
}
void get_alert_md_area_2_1( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_2_1.var );
}
void get_alert_md_area_3_1( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_3_1.var );
}
void get_alert_week_alert_plan_1( char * outbuf )
{
    strcat( outbuf, g_config.alert.week_alert_plan_1.var );
}
void get_alert_plan_cap_enalbe_1( char * outbuf )// ����ʱ�䵽ʱ���Ƿ�����¼��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.plan_cap_enalbe_1.var );
    strcat( outbuf, temp );
}
void get_alert_plan_cap_last_sec_1( char * outbuf )// ¼�����������0����¼��ʱ���������һ������
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.plan_cap_last_sec_1.var );
    strcat( outbuf, temp );
}
void get_alert_capture_pic_enable_2( char * outbuf )//����ץ��ͼƬ
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_pic_enable_2.var );
    strcat( outbuf, temp );
}
void get_alert_capture_pic_num_2( char * outbuf )//ͼƬץ����Ŀ
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_pic_num_2.var );
    strcat( outbuf, temp );
}
void get_alert_capture_pic_interval_2( char * outbuf )//ͼƬץ�ļ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_pic_interval_2.var );
    strcat( outbuf, temp );
}
void get_alert_capture_video_enable_2( char * outbuf )//����¼��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_video_enable_2.var );
    strcat( outbuf, temp );
}
void get_alert_capture_video_last_time_2( char * outbuf )//¼�����ʱ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.capture_video_last_time_2.var );
    strcat( outbuf, temp );
}
void get_alert_alarm_enable_2( char * outbuf )//���þ���
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.alarm_enable_2.var );
    strcat( outbuf, temp );
}
void get_alert_alarm_delay_2( char * outbuf )//�����ӳ�ʱ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.alarm_delay_2.var );
    strcat( outbuf, temp );
}
void get_alert_alarm_last_time_2( char * outbuf )//�������ʱ��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.alarm_last_time_2.var );
    strcat( outbuf, temp );
}
void get_alert_md_enable_2( char * outbuf )//�����ƶ����
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.md_enable_2.var );
    strcat( outbuf, temp );
}
void get_alert_md_sensitivity_2( char * outbuf )//������жȣ�30%��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.md_sensitivity_2.var );
    strcat( outbuf, temp );
}
void get_alert_md_area_0_2( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_0_2.var );
}
void get_alert_md_area_1_2( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_1_2.var );
}
void get_alert_md_area_2_2( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_2_2.var );
}
void get_alert_md_area_3_2( char * outbuf )//������򣨾��Σ�
{
    strcat( outbuf, g_config.alert.md_area_3_2.var );
}
void get_alert_week_alert_plan_2( char * outbuf )
{
    strcat( outbuf, g_config.alert.week_alert_plan_2.var );
}
void get_alert_plan_cap_enalbe_2( char * outbuf )// ����ʱ�䵽ʱ���Ƿ�����¼��
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.plan_cap_enalbe_2.var );
    strcat( outbuf, temp );
}
void get_alert_plan_cap_last_sec_2( char * outbuf )// ¼�����������0����¼��ʱ���������һ������
{
    char temp[16];
    sprintf( temp, "%d", g_config.alert.plan_cap_last_sec_2.var );
    strcat( outbuf, temp );
}
//[store]�洢����	
void get_store_sd_status( char * outbuf )//״̬��0��δ���룬1���Ѳ���
{
    char temp[16];
    sprintf( temp, "%d", g_config.store.sd_status.var );
    strcat( outbuf, temp );
}
void get_store_sd_total_size( char * outbuf )//SD��������
{
    char temp[16];
    sprintf( temp, "%d", g_config.store.sd_total_size.var );
    strcat( outbuf, temp );
}
void get_store_sd_used_size( char * outbuf )//SD����ʹ�����������������ڴ������壬��Ҫ�Ƿ�װ��һ���ṹ���ڣ�sd_store_enable
{
    char temp[16];
    sprintf( temp, "%d", g_config.store.sd_used_size.var );
    strcat( outbuf, temp );
}
void get_store_sd_store_enable( char * outbuf )//����SD���洢
{
    char temp[16];
    sprintf( temp, "%d", g_config.store.sd_store_enable.var );
    strcat( outbuf, temp );
}
void get_store_auto_cover_older( char * outbuf )//�Զ����Ǿ��ļ�
{
    char temp[16];
    sprintf( temp, "%d", g_config.store.auto_cover_older.var );
    strcat( outbuf, temp );
}
void get_store_percent_alarm( char * outbuf )// ִ�и澯�ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_alarm,����и澯�percent_del
{
    char temp[16];
    sprintf( temp, "%d", g_config.store.percent_alarm.var );
    strcat( outbuf, temp );
}
void get_store_percent_del( char * outbuf )// ִ��ɾ���ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_del,�����ɾ�����sys
{
    char temp[16];
    sprintf( temp, "%d", g_config.store.percent_del.var );
    strcat( outbuf, temp );
}
//[sys]ϵͳ����	                        	
void get_sys_app_version( char * outbuf )
{
    strcat( outbuf, g_config.sys.app_version.var );
}
void get_sys_app_time( char * outbuf )
{
    strcat( outbuf, g_config.sys.app_time.var );
}
//[rtv_start] ʵʱ��Ƶ��������
void get_rtv_start_channel( char * outbuf )// ��Ƶ�ŵ� 0, 1
{
    char temp[16];
    sprintf( temp, "%d", g_config.rtv_start.channel.var );
    strcat( outbuf, temp );
}
//[htv_start] ¼����������
void get_htv_start_channel( char * outbuf )// ��Ƶ�ŵ� 0, 1	
{
    char temp[16];
    sprintf( temp, "%d", g_config.htv_start.channel.var );
    strcat( outbuf, temp );
}
//[htv_end] ¼��ֹͣ����
void get_htv_end_channel( char * outbuf )// ��Ƶ�ŵ� 0, 1
{
    char temp[16];
    sprintf( temp, "%d", g_config.htv_end.channel.var );
    strcat( outbuf, temp );
}
//[pic_start] ͼƬץ����������
void get_pic_start_channel( char * outbuf )// ��Ƶ�ŵ� 0, 1
{
    char temp[16];
    sprintf( temp, "%d", g_config.pic_start.channel.var );
    strcat( outbuf, temp );
}
void get_pic_start_num( char * outbuf )// ץ������
{
    char temp[16];
    sprintf( temp, "%d", g_config.pic_start.num.var );
    strcat( outbuf, temp );
}
//[ptz_control] ��̨��������
void get_ptz_control_channel( char * outbuf )// ��Ƶ�ŵ� 0, 1
{
    char temp[16];
    sprintf( temp, "%d", g_config.ptz_control.channel.var );
    strcat( outbuf, temp );
}
void get_ptz_control_left( char * outbuf )// ����ת��  0���޲��� 1������
{
    char temp[16];
    sprintf( temp, "%d", g_config.ptz_control.left.var );
    strcat( outbuf, temp );
}
void get_ptz_control_right( char * outbuf )// ����ת��  0���޲��� 1������
{
    char temp[16];
    sprintf( temp, "%d", g_config.ptz_control.right.var );
    strcat( outbuf, temp );
}
void get_ptz_control_up( char * outbuf )// ����ת��  0���޲��� 1������
{
    char temp[16];
    sprintf( temp, "%d", g_config.ptz_control.up.var );
    strcat( outbuf, temp );
}
void get_ptz_control_down( char * outbuf )// ����ת��  0���޲��� 1������
{
    char temp[16];
    sprintf( temp, "%d", g_config.ptz_control.down.var );
    strcat( outbuf, temp );
}
//[sys_quit] IPC�˳�����
void get_sys_quit_flag( char * outbuf )// 0��IPC���˳���1��IPC�˳�
{
    char temp[16];
    sprintf( temp, "%d", g_config.sys_quit.flag.var );
    strcat( outbuf, temp );
}
//[log] ��־��ȡ
void get_log_flag( char * outbuf )// 0: ����ȡ��־, 1:��ȡ��־
{
    char temp[16];
    sprintf( temp, "%d", g_config.log.flag.var );
    strcat( outbuf, temp );
}
//[usb_remove]
void get_usb_remove_channel( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.usb_remove.channel.var );
    strcat( outbuf, temp );
}
//[hb] ����
void get_hb_flag( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.hb.flag.var );
    strcat( outbuf, temp );
}
//[def_config] �ָ���������
void get_def_config_flag( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.def_config.flag.var );
    strcat( outbuf, temp );
}
//[md_report]
void get_md_report_md_area_0_0( char * outbuf )// 0·��Ƶ��0�������Ƿ����ƶ� 0��û�� 1����
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_0_0.var );
    strcat( outbuf, temp );
}
void get_md_report_md_area_0_1( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_0_1.var );
    strcat( outbuf, temp );
}
void get_md_report_md_area_0_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_0_2.var );
    strcat( outbuf, temp );
}
void get_md_report_md_area_0_3( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_0_3.var );
    strcat( outbuf, temp );
}
void get_md_report_md_area_1_0( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_1_0.var );
    strcat( outbuf, temp );
}
void get_md_report_md_area_1_1( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_1_1.var );
    strcat( outbuf, temp );
}
void get_md_report_md_area_1_2( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_1_2.var );
    strcat( outbuf, temp );
}
void get_md_report_md_area_1_3( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.md_report.md_area_1_3.var );
    strcat( outbuf, temp );
}
//[alarm_disk] �������ɴ洢����ȫ�ֱ����ṩ
void get_alarm_disk_flag( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.alarm_disk.flag.var );
    strcat( outbuf, temp );
}
//[time_syn] ʱ��ͬ��
void get_time_syn_time( char * outbuf )// ����ϵͳ�����ڣ���ʽ����: 2008-10-12 13:14:34
{
    strcat( outbuf, g_config.time_syn.time.var );
}
//[alarm_error] IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
void get_alarm_error_alarm_error_id( char * outbuf )// �澯����id
{
    char temp[16];
    sprintf( temp, "%d", g_config.alarm_error.alarm_error_id.var );
    strcat( outbuf, temp );
}
void get_alarm_error_alarm_error_name( char * outbuf )
{
    strcat( outbuf, g_config.alarm_error.alarm_error_name.var );
}
//[process_info] ��ȡipc������Ϣ
void get_process_info_flag( char * outbuf )
{
    char temp[16];
    sprintf( temp, "%d", g_config.process_info.flag.var );
    strcat( outbuf, temp );
}
//[end]
void get_end_flag( char * outbuf )// �������
{
    char temp[16];
    sprintf( temp, "%d", g_config.end.flag.var );
    strcat( outbuf, temp );
}


