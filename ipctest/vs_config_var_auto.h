// ���ִ����ö��
enum CONFIG_VAR_INDEX_
{
    CFG_var_login = 1, // web��¼
    CFG_var_user, //�û���Ϣ  
    CFG_var_video, //��Ƶ����
    CFG_var_network, //�������
    CFG_var_alert, //��������	
    CFG_var_store, //�洢����	
    CFG_var_sys, //ϵͳ����	                        	
    CFG_var_rtv_start, // ʵʱ��Ƶ��������
    CFG_var_htv_start, // ¼����������
    CFG_var_htv_end, // ¼��ֹͣ����
    CFG_var_pic_start, // ͼƬץ����������
    CFG_var_ptz_control, // ��̨��������
    CFG_var_sys_quit, // IPC�˳�����
    CFG_var_log, // ��־��ȡ
    CFG_var_usb_remove, 
    CFG_var_hb, // ����
    CFG_var_def_config, // �ָ���������
    CFG_var_md_report, 
    CFG_var_alarm_disk, // �������ɴ洢����ȫ�ֱ����ṩ
    CFG_var_time_syn, // ʱ��ͬ��
    CFG_var_alarm_error, // IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
    CFG_var_process_info, // ��ȡipc������Ϣ
    CFG_var_end, 
};

//���ִ���Ķ���
typedef struct tag_var_login// web��¼
{
    int pgh;
}s_var_login;

typedef struct tag_var_login_get_req
{
   s_user_info user_info;
}s_var_login_get_req;

typedef struct tag_var_login_set_req
{
   s_user_info user_info;
   s_var_login var_login;
}s_var_login_set_req;

typedef struct tag_var_user//�û���Ϣ  
{
    int user_num;
    char username_0[_LEN_NORMAL];// username_0ϵͳ����Ա
    char password_0[_LEN_NORMAL];
    char username_1[_LEN_NORMAL];// username_1 RTU�û�					
    char password_1[_LEN_NORMAL];
    char username_2[_LEN_NORMAL];// username_2 ��ͨ�û�
    char password_2[_LEN_NORMAL];
    char username_3[_LEN_NORMAL];// username_3 ��ͨ�û�
    char password_3[_LEN_NORMAL];
}s_var_user;

typedef struct tag_var_user_get_req
{
   s_user_info user_info;
}s_var_user_get_req;

typedef struct tag_var_user_set_req
{
   s_user_info user_info;
   s_var_user var_user;
}s_var_user_set_req;

typedef struct tag_var_video//��Ƶ����
{
    int rtv_num;//�ݶ�ֻ��2·��Ƶ
    int solution_x_1;
    int solution_y_1;
    int bright_1;//���� : 0~255
    int contrast_1;//�Աȶ�: 0~255
    int frame_interval_1;//����֡�����,0Ϊ�޼��
    int speed_1;//֡��
    int cache_time_1;//��ƵͼƬԤ����ʱ�䳤��
    int solution_x_2;
    int solution_y_2;
    int bright_2;
    int contrast_2;
    int frame_interval_2;
    int speed_2;
    int cache_time_2;
}s_var_video;

typedef struct tag_var_video_get_req
{
   s_user_info user_info;
}s_var_video_get_req;

typedef struct tag_var_video_set_req
{
   s_user_info user_info;
   s_var_video var_video;
}s_var_video_set_req;

typedef struct tag_var_network//�������
{
    char ip_addr[_LEN_NORMAL];
    char ip_mask[_LEN_NORMAL];
    char ip_gateway[_LEN_NORMAL];
    char dns[_LEN_NORMAL];
    char mac_addr[_LEN_NORMAL];
    int web_port;//web���������ʶ˿�
    int socket_port;//socket����˿�
    int rtv_port;//��Ƶ���Ͷ˿�
    char alarm_remote_addr[_LEN_NORMAL];//Զ�̵�ַ������IPC�������͸澯
    int alarm_remote_port;//Զ�̶˿�
}s_var_network;

typedef struct tag_var_network_get_req
{
   s_user_info user_info;
}s_var_network_get_req;

typedef struct tag_var_network_set_req
{
   s_user_info user_info;
   s_var_network var_network;
}s_var_network_set_req;

typedef struct tag_var_alert//��������	
{
    int alert_num;//2·����
    int capture_pic_enable_1;//����ץ��ͼƬ
    int capture_pic_num_1;//ͼƬץ����Ŀ
    int capture_pic_interval_1;//ͼƬץ�ļ��, ����ɾ��
    int capture_video_enable_1;//����¼��
    int capture_video_last_time_1;//¼�����ʱ��
    int alarm_enable_1;//���þ���
    int alarm_delay_1;//�����ӳ�ʱ��
    int alarm_last_time_1;//�������ʱ��
    int md_enable_1;//�����ƶ����
    int md_sensitivity_1;//������жȣ�30%��
    char md_area_0_1[_LEN_NORMAL];//������򣨾��Σ�
    char md_area_1_1[_LEN_NORMAL];//������򣨾��Σ�
    char md_area_2_1[_LEN_NORMAL];//������򣨾��Σ�
    char md_area_3_1[_LEN_NORMAL];//������򣨾��Σ�
    char week_alert_plan_1[_LEN_WEEK];
    int plan_cap_enalbe_1;// ����ʱ�䵽ʱ���Ƿ�����¼��
    int plan_cap_last_sec_1;// ¼�����������0����¼��ʱ���������һ������
    int capture_pic_enable_2;//����ץ��ͼƬ
    int capture_pic_num_2;//ͼƬץ����Ŀ
    int capture_pic_interval_2;//ͼƬץ�ļ��
    int capture_video_enable_2;//����¼��
    int capture_video_last_time_2;//¼�����ʱ��
    int alarm_enable_2;//���þ���
    int alarm_delay_2;//�����ӳ�ʱ��
    int alarm_last_time_2;//�������ʱ��
    int md_enable_2;//�����ƶ����
    int md_sensitivity_2;//������жȣ�30%��
    char md_area_0_2[_LEN_NORMAL];//������򣨾��Σ�
    char md_area_1_2[_LEN_NORMAL];//������򣨾��Σ�
    char md_area_2_2[_LEN_NORMAL];//������򣨾��Σ�
    char md_area_3_2[_LEN_NORMAL];//������򣨾��Σ�
    char week_alert_plan_2[_LEN_WEEK];
    int plan_cap_enalbe_2;// ����ʱ�䵽ʱ���Ƿ�����¼��
    int plan_cap_last_sec_2;// ¼�����������0����¼��ʱ���������һ������
}s_var_alert;

typedef struct tag_var_alert_get_req
{
   s_user_info user_info;
}s_var_alert_get_req;

typedef struct tag_var_alert_set_req
{
   s_user_info user_info;
   s_var_alert var_alert;
}s_var_alert_set_req;

typedef struct tag_var_store//�洢����	
{
    int sd_status;//״̬��0��δ���룬1���Ѳ���
    int sd_total_size;//SD��������
    int sd_used_size;//SD����ʹ�����������������ڴ������壬��Ҫ�Ƿ�װ��һ���ṹ���ڣ�sd_store_enable
    int sd_store_enable;//����SD���洢
    int auto_cover_older;//�Զ����Ǿ��ļ�
    int percent_alarm;// ִ�и澯�ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_alarm,����и澯�percent_del
    int percent_del;// ִ��ɾ���ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_del,�����ɾ�����sys
}s_var_store;

typedef struct tag_var_store_get_req
{
   s_user_info user_info;
}s_var_store_get_req;

typedef struct tag_var_store_set_req
{
   s_user_info user_info;
   s_var_store var_store;
}s_var_store_set_req;

typedef struct tag_var_sys//ϵͳ����	                        	
{
    char app_version[_LEN_NORMAL];
    char app_time[_LEN_NORMAL];
}s_var_sys;

typedef struct tag_var_sys_get_req
{
   s_user_info user_info;
}s_var_sys_get_req;

typedef struct tag_var_sys_set_req
{
   s_user_info user_info;
   s_var_sys var_sys;
}s_var_sys_set_req;

typedef struct tag_var_rtv_start// ʵʱ��Ƶ��������
{
    int channel;// ��Ƶ�ŵ� 0, 1
}s_var_rtv_start;

typedef struct tag_var_rtv_start_get_req
{
   s_user_info user_info;
}s_var_rtv_start_get_req;

typedef struct tag_var_rtv_start_set_req
{
   s_user_info user_info;
   s_var_rtv_start var_rtv_start;
}s_var_rtv_start_set_req;

typedef struct tag_var_htv_start// ¼����������
{
    int channel;// ��Ƶ�ŵ� 0, 1	
}s_var_htv_start;

typedef struct tag_var_htv_start_get_req
{
   s_user_info user_info;
}s_var_htv_start_get_req;

typedef struct tag_var_htv_start_set_req
{
   s_user_info user_info;
   s_var_htv_start var_htv_start;
}s_var_htv_start_set_req;

typedef struct tag_var_htv_end// ¼��ֹͣ����
{
    int channel;// ��Ƶ�ŵ� 0, 1
}s_var_htv_end;

typedef struct tag_var_htv_end_get_req
{
   s_user_info user_info;
}s_var_htv_end_get_req;

typedef struct tag_var_htv_end_set_req
{
   s_user_info user_info;
   s_var_htv_end var_htv_end;
}s_var_htv_end_set_req;

typedef struct tag_var_pic_start// ͼƬץ����������
{
    int channel;// ��Ƶ�ŵ� 0, 1
    int num;// ץ������
}s_var_pic_start;

typedef struct tag_var_pic_start_get_req
{
   s_user_info user_info;
}s_var_pic_start_get_req;

typedef struct tag_var_pic_start_set_req
{
   s_user_info user_info;
   s_var_pic_start var_pic_start;
}s_var_pic_start_set_req;

typedef struct tag_var_ptz_control// ��̨��������
{
    int channel;// ��Ƶ�ŵ� 0, 1
    int left;// ����ת��  0���޲��� 1������
    int right;// ����ת��  0���޲��� 1������
    int up;// ����ת��  0���޲��� 1������
    int down;// ����ת��  0���޲��� 1������
}s_var_ptz_control;

typedef struct tag_var_ptz_control_get_req
{
   s_user_info user_info;
}s_var_ptz_control_get_req;

typedef struct tag_var_ptz_control_set_req
{
   s_user_info user_info;
   s_var_ptz_control var_ptz_control;
}s_var_ptz_control_set_req;

typedef struct tag_var_sys_quit// IPC�˳�����
{
    int flag;// 0��IPC���˳���1��IPC�˳�
}s_var_sys_quit;

typedef struct tag_var_sys_quit_get_req
{
   s_user_info user_info;
}s_var_sys_quit_get_req;

typedef struct tag_var_sys_quit_set_req
{
   s_user_info user_info;
   s_var_sys_quit var_sys_quit;
}s_var_sys_quit_set_req;

typedef struct tag_var_log// ��־��ȡ
{
    int flag;// 0: ����ȡ��־, 1:��ȡ��־
}s_var_log;

typedef struct tag_var_log_get_req
{
   s_user_info user_info;
}s_var_log_get_req;

typedef struct tag_var_log_set_req
{
   s_user_info user_info;
   s_var_log var_log;
}s_var_log_set_req;

typedef struct tag_var_usb_remove
{
    int channel;
}s_var_usb_remove;

typedef struct tag_var_usb_remove_get_req
{
   s_user_info user_info;
}s_var_usb_remove_get_req;

typedef struct tag_var_usb_remove_set_req
{
   s_user_info user_info;
   s_var_usb_remove var_usb_remove;
}s_var_usb_remove_set_req;

typedef struct tag_var_hb// ����
{
    int flag;
}s_var_hb;

typedef struct tag_var_hb_get_req
{
   s_user_info user_info;
}s_var_hb_get_req;

typedef struct tag_var_hb_set_req
{
   s_user_info user_info;
   s_var_hb var_hb;
}s_var_hb_set_req;

typedef struct tag_var_def_config// �ָ���������
{
    int flag;
}s_var_def_config;

typedef struct tag_var_def_config_get_req
{
   s_user_info user_info;
}s_var_def_config_get_req;

typedef struct tag_var_def_config_set_req
{
   s_user_info user_info;
   s_var_def_config var_def_config;
}s_var_def_config_set_req;

typedef struct tag_var_md_report
{
    int md_area_0_0;// 0·��Ƶ��0�������Ƿ����ƶ� 0��û�� 1����
    int md_area_0_1;
    int md_area_0_2;
    int md_area_0_3;
    int md_area_1_0;
    int md_area_1_1;
    int md_area_1_2;
    int md_area_1_3;
}s_var_md_report;

typedef struct tag_var_md_report_get_req
{
   s_user_info user_info;
}s_var_md_report_get_req;

typedef struct tag_var_md_report_set_req
{
   s_user_info user_info;
   s_var_md_report var_md_report;
}s_var_md_report_set_req;

typedef struct tag_var_alarm_disk// �������ɴ洢����ȫ�ֱ����ṩ
{
    int flag;
}s_var_alarm_disk;

typedef struct tag_var_alarm_disk_get_req
{
   s_user_info user_info;
}s_var_alarm_disk_get_req;

typedef struct tag_var_alarm_disk_set_req
{
   s_user_info user_info;
   s_var_alarm_disk var_alarm_disk;
}s_var_alarm_disk_set_req;

typedef struct tag_var_time_syn// ʱ��ͬ��
{
    char time[_LEN_NORMAL];// ����ϵͳ�����ڣ���ʽ����: 2008-10-12 13:14:34
}s_var_time_syn;

typedef struct tag_var_time_syn_get_req
{
   s_user_info user_info;
}s_var_time_syn_get_req;

typedef struct tag_var_time_syn_set_req
{
   s_user_info user_info;
   s_var_time_syn var_time_syn;
}s_var_time_syn_set_req;

typedef struct tag_var_alarm_error// IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
{
    int alarm_error_id;// �澯����id
    char alarm_error_name[_LEN_NORMAL];
}s_var_alarm_error;

typedef struct tag_var_alarm_error_get_req
{
   s_user_info user_info;
}s_var_alarm_error_get_req;

typedef struct tag_var_alarm_error_set_req
{
   s_user_info user_info;
   s_var_alarm_error var_alarm_error;
}s_var_alarm_error_set_req;

typedef struct tag_var_process_info// ��ȡipc������Ϣ
{
    int flag;
}s_var_process_info;

typedef struct tag_var_process_info_get_req
{
   s_user_info user_info;
}s_var_process_info_get_req;

typedef struct tag_var_process_info_set_req
{
   s_user_info user_info;
   s_var_process_info var_process_info;
}s_var_process_info_set_req;

typedef struct tag_var_end
{
    int flag;// �������
}s_var_end;

typedef struct tag_var_end_get_req
{
   s_user_info user_info;
}s_var_end_get_req;

typedef struct tag_var_end_set_req
{
   s_user_info user_info;
   s_var_end var_end;
}s_var_end_set_req;


//ȫ�ֱ���
typedef struct tagAllConfigVar
{
    s_var_login    login;// web��¼
    s_var_user    user;//�û���Ϣ  
    s_var_video    video;//��Ƶ����
    s_var_network    network;//�������
    s_var_alert    alert;//��������	
    s_var_store    store;//�洢����	
    s_var_sys    sys;//ϵͳ����	                        	
    s_var_rtv_start    rtv_start;// ʵʱ��Ƶ��������
    s_var_htv_start    htv_start;// ¼����������
    s_var_htv_end    htv_end;// ¼��ֹͣ����
    s_var_pic_start    pic_start;// ͼƬץ����������
    s_var_ptz_control    ptz_control;// ��̨��������
    s_var_sys_quit    sys_quit;// IPC�˳�����
    s_var_log    log;// ��־��ȡ
    s_var_usb_remove    usb_remove;
    s_var_hb    hb;// ����
    s_var_def_config    def_config;// �ָ���������
    s_var_md_report    md_report;
    s_var_alarm_disk    alarm_disk;// �������ɴ洢����ȫ�ֱ����ṩ
    s_var_time_syn    time_syn;// ʱ��ͬ��
    s_var_alarm_error    alarm_error;// IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
    s_var_process_info    process_info;// ��ȡipc������Ϣ
    s_var_end    end;

    int config_index;
}AllConfigVar;


