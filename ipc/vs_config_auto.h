// ���ִ����ö��
enum CONFIG_INDEX
{
    CFG_login = 1, // web��¼
    CFG_user, //�û���Ϣ  
    CFG_video, //��Ƶ����
    CFG_network, //�������
    CFG_alert, //��������	
    CFG_store, //�洢����	
    CFG_sys, //ϵͳ����	                        	
    CFG_rtv_start, // ʵʱ��Ƶ��������
    CFG_htv_start, // ¼����������
    CFG_htv_end, // ¼��ֹͣ����
    CFG_pic_start, // ͼƬץ����������
    CFG_ptz_control, // ��̨��������
    CFG_sys_quit, // IPC�˳�����
    CFG_log, // ��־��ȡ
    CFG_usb_remove, 
    CFG_hb, // ����
    CFG_def_config, // �ָ���������
    CFG_md_report, 
    CFG_alarm_disk, // �������ɴ洢����ȫ�ֱ����ṩ
    CFG_time_syn, // ʱ��ͬ��
    CFG_alarm_error, // IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
    CFG_process_info, // ��ȡipc������Ϣ
    CFG_end, 
};

//���ִ���Ķ���
typedef struct tag_login// web��¼
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       pgh;
} s_login;

typedef struct tag_user//�û���Ϣ  
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       user_num;
    D_string    username_0;// username_0ϵͳ����Ա
    D_string    password_0;
    D_string    username_1;// username_1 RTU�û�					
    D_string    password_1;
    D_string    username_2;// username_2 ��ͨ�û�
    D_string    password_2;
    D_string    username_3;// username_3 ��ͨ�û�
    D_string    password_3;
} s_user;

typedef struct tag_video//��Ƶ����
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       rtv_num;//�ݶ�ֻ��2·��Ƶ
    D_int       solution_x_1;
    D_int       solution_y_1;
    D_int       bright_1;//���� : 0~255
    D_int       contrast_1;//�Աȶ�: 0~255
    D_int       frame_interval_1;//����֡�����,0Ϊ�޼��
    D_int       speed_1;//֡��
    D_int       cache_time_1;//��ƵͼƬԤ����ʱ�䳤��
    D_int       solution_x_2;
    D_int       solution_y_2;
    D_int       bright_2;
    D_int       contrast_2;
    D_int       frame_interval_2;
    D_int       speed_2;
    D_int       cache_time_2;
} s_video;

typedef struct tag_network//�������
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_string    ip_addr;
    D_string    ip_mask;
    D_string    ip_gateway;
    D_string    dns;
    D_string    mac_addr;
    D_int       web_port;//web���������ʶ˿�
    D_int       socket_port;//socket����˿�
    D_int       rtv_port;//��Ƶ���Ͷ˿�
    D_string    alarm_remote_addr;//Զ�̵�ַ������IPC�������͸澯
    D_int       alarm_remote_port;//Զ�̶˿�
} s_network;

typedef struct tag_alert//��������	
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       alert_num;//2·����
    D_int       capture_pic_enable_1;//����ץ��ͼƬ
    D_int       capture_pic_num_1;//ͼƬץ����Ŀ
    D_int       capture_pic_interval_1;//ͼƬץ�ļ��, ����ɾ��
    D_int       capture_video_enable_1;//����¼��
    D_int       capture_video_last_time_1;//¼�����ʱ��
    D_int       alarm_enable_1;//���þ���
    D_int       alarm_delay_1;//�����ӳ�ʱ��
    D_int       alarm_last_time_1;//�������ʱ��
    D_int       md_enable_1;//�����ƶ����
    D_int       md_sensitivity_1;//������жȣ�30%��
    D_string    md_area_0_1;//������򣨾��Σ�
    D_string    md_area_1_1;//������򣨾��Σ�
    D_string    md_area_2_1;//������򣨾��Σ�
    D_string    md_area_3_1;//������򣨾��Σ�
    D_week_string week_alert_plan_1;
    D_int       plan_cap_enalbe_1;// ����ʱ�䵽ʱ���Ƿ�����¼��
    D_int       plan_cap_last_sec_1;// ¼�����������0����¼��ʱ���������һ������
    D_int       capture_pic_enable_2;//����ץ��ͼƬ
    D_int       capture_pic_num_2;//ͼƬץ����Ŀ
    D_int       capture_pic_interval_2;//ͼƬץ�ļ��
    D_int       capture_video_enable_2;//����¼��
    D_int       capture_video_last_time_2;//¼�����ʱ��
    D_int       alarm_enable_2;//���þ���
    D_int       alarm_delay_2;//�����ӳ�ʱ��
    D_int       alarm_last_time_2;//�������ʱ��
    D_int       md_enable_2;//�����ƶ����
    D_int       md_sensitivity_2;//������жȣ�30%��
    D_string    md_area_0_2;//������򣨾��Σ�
    D_string    md_area_1_2;//������򣨾��Σ�
    D_string    md_area_2_2;//������򣨾��Σ�
    D_string    md_area_3_2;//������򣨾��Σ�
    D_week_string week_alert_plan_2;
    D_int       plan_cap_enalbe_2;// ����ʱ�䵽ʱ���Ƿ�����¼��
    D_int       plan_cap_last_sec_2;// ¼�����������0����¼��ʱ���������һ������
} s_alert;

typedef struct tag_store//�洢����	
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       sd_status;//״̬��0��δ���룬1���Ѳ���
    D_int       sd_total_size;//SD��������
    D_int       sd_used_size;//SD����ʹ�����������������ڴ������壬��Ҫ�Ƿ�װ��һ���ṹ���ڣ�sd_store_enable
    D_int       sd_store_enable;//����SD���洢
    D_int       auto_cover_older;//�Զ����Ǿ��ļ�
    D_int       percent_alarm;// ִ�и澯�ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_alarm,����и澯�percent_del
    D_int       percent_del;// ִ��ɾ���ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_del,�����ɾ�����sys
} s_store;

typedef struct tag_sys//ϵͳ����	                        	
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_string    app_version;
    D_string    app_time;
} s_sys;

typedef struct tag_rtv_start// ʵʱ��Ƶ��������
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       channel;// ��Ƶ�ŵ� 0, 1
} s_rtv_start;

typedef struct tag_htv_start// ¼����������
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       channel;// ��Ƶ�ŵ� 0, 1	
} s_htv_start;

typedef struct tag_htv_end// ¼��ֹͣ����
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       channel;// ��Ƶ�ŵ� 0, 1
} s_htv_end;

typedef struct tag_pic_start// ͼƬץ����������
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       channel;// ��Ƶ�ŵ� 0, 1
    D_int       num;// ץ������
} s_pic_start;

typedef struct tag_ptz_control// ��̨��������
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       channel;// ��Ƶ�ŵ� 0, 1
    D_int       left;// ����ת��  0���޲��� 1������
    D_int       right;// ����ת��  0���޲��� 1������
    D_int       up;// ����ת��  0���޲��� 1������
    D_int       down;// ����ת��  0���޲��� 1������
} s_ptz_control;

typedef struct tag_sys_quit// IPC�˳�����
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       flag;// 0��IPC���˳���1��IPC�˳�
} s_sys_quit;

typedef struct tag_log// ��־��ȡ
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       flag;// 0: ����ȡ��־, 1:��ȡ��־
} s_log;

typedef struct tag_usb_remove
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       channel;
} s_usb_remove;

typedef struct tag_hb// ����
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       flag;
} s_hb;

typedef struct tag_def_config// �ָ���������
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       flag;
} s_def_config;

typedef struct tag_md_report
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       md_area_0_0;// 0·��Ƶ��0�������Ƿ����ƶ� 0��û�� 1����
    D_int       md_area_0_1;
    D_int       md_area_0_2;
    D_int       md_area_0_3;
    D_int       md_area_1_0;
    D_int       md_area_1_1;
    D_int       md_area_1_2;
    D_int       md_area_1_3;
} s_md_report;

typedef struct tag_alarm_disk// �������ɴ洢����ȫ�ֱ����ṩ
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       flag;
} s_alarm_disk;

typedef struct tag_time_syn// ʱ��ͬ��
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_string    time;// ����ϵͳ�����ڣ���ʽ����: 2008-10-12 13:14:34
} s_time_syn;

typedef struct tag_alarm_error// IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       alarm_error_id;// �澯����id
    D_string    alarm_error_name;
} s_alarm_error;

typedef struct tag_process_info// ��ȡipc������Ϣ
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       flag;
} s_process_info;

typedef struct tag_end
{
    char        name[_LEN_NORMAL];
    char        note[_LEN_EXTEND];

    D_int       flag;// �������
}s_end;

//ȫ�ֱ���
typedef struct tagAllConfig
{
    s_login    login;// web��¼
    s_user    user;//�û���Ϣ  
    s_video    video;//��Ƶ����
    s_network    network;//�������
    s_alert    alert;//��������	
    s_store    store;//�洢����	
    s_sys    sys;//ϵͳ����	                        	
    s_rtv_start    rtv_start;// ʵʱ��Ƶ��������
    s_htv_start    htv_start;// ¼����������
    s_htv_end    htv_end;// ¼��ֹͣ����
    s_pic_start    pic_start;// ͼƬץ����������
    s_ptz_control    ptz_control;// ��̨��������
    s_sys_quit    sys_quit;// IPC�˳�����
    s_log    log;// ��־��ȡ
    s_usb_remove    usb_remove;
    s_hb    hb;// ����
    s_def_config    def_config;// �ָ���������
    s_md_report    md_report;
    s_alarm_disk    alarm_disk;// �������ɴ洢����ȫ�ֱ����ṩ
    s_time_syn    time_syn;// ʱ��ͬ��
    s_alarm_error    alarm_error;// IPC��RTU�ϱ����ش�����Ϣ����¼�񱣴�ʱ��openʧ��
    s_process_info    process_info;// ��ȡipc������Ϣ
    s_end    end;

    int config_index;
}AllConfig;


