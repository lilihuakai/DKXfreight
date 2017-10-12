#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 2048                         //�ļ���ȡʱ��ÿ������ֽ���
#define MAX_NUM_STRING 50                                   //�ַ�������
#define MAX_NUM_STRINGS 1600                                //�����ַ�������
#define MAX_NUM_DOUBLE_STRING 16                            //�����ַ�������
#define IF_WRITE_CSV 0                                      //�Ƿ�����������ݵ��ļ�

#define MAX_NUM_WAREHOUSE 50                                //���ֿ⡱�����
#define MAX_NUM_COUNTRY 300                                 //�����ҡ������
#define MAX_NUM_TRANS 300                                   //�����䷽ʽ�������
#define MAX_NUM_AREA 1500                                   //�����������������
#define MAX_NUM_COST 10000                                  //���������á������
#define MAX_NUM_ADDRESS 300                                 //���Ʒѵص㡱�����
#define MAX_NUM_COST_OTHER 10000                            //�������ӷѡ������

#define MAX_NUM_RESULT 300                                  //���������������


int row_warehouse;                                          //���ֿ⡱��
char warehouse[MAX_NUM_WAREHOUSE][MAX_NUM_STRING], head_warehouse[MAX_NUM_STRING];

int row_country;                                            //�����ҡ���
char country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_country[MAX_NUM_STRING];
char code_country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_code_country[MAX_NUM_STRING];

int row_transport;                                          //�����䷽ʽ����
char code_trans[MAX_NUM_TRANS][MAX_NUM_STRING], head_code_trans[MAX_NUM_STRING];
char name_trans[MAX_NUM_TRANS][MAX_NUM_STRING], head_name_trans[MAX_NUM_STRING];
char ware_trans[MAX_NUM_TRANS][MAX_NUM_STRING], head_ware_trans[MAX_NUM_STRING];

int row_area;                                               //��������������
char name_area[MAX_NUM_AREA][MAX_NUM_STRING], head_name_area[MAX_NUM_STRING];
char code_area[MAX_NUM_AREA][MAX_NUM_STRING], head_code_area[MAX_NUM_STRING];
char area_area[MAX_NUM_AREA][MAX_NUM_STRING], head_area_area[MAX_NUM_STRING];
char country_area[MAX_NUM_AREA][MAX_NUM_STRINGS], head_country_area[MAX_NUM_STRING];

int row_cost;                                               //���������á���
char name_cost[MAX_NUM_COST][MAX_NUM_STRING], head_name_cost[MAX_NUM_STRING];
char area_cost[MAX_NUM_COST][MAX_NUM_STRING], head_area_cost[MAX_NUM_STRING];
char type_cost[MAX_NUM_COST][MAX_NUM_STRING], head_type_cost[MAX_NUM_STRING];
char weight_start_cost[MAX_NUM_COST][MAX_NUM_DOUBLE_STRING], head_weight_start_cost[MAX_NUM_STRING];
char weight_end_cost[MAX_NUM_COST][MAX_NUM_DOUBLE_STRING], head_weight_end_cost[MAX_NUM_STRING];
char weight_average_cost[MAX_NUM_COST][MAX_NUM_DOUBLE_STRING], head_weight_average_cost[MAX_NUM_STRING];
char price_cost[MAX_NUM_COST][MAX_NUM_DOUBLE_STRING], head_price_cost[MAX_NUM_STRING];
char discount_cost[MAX_NUM_COST][MAX_NUM_DOUBLE_STRING], head_discount_cost[MAX_NUM_STRING];
double weight_start_cost_lf[MAX_NUM_COST];
double weight_end_cost_lf[MAX_NUM_COST];
double weight_average_cost_lf[MAX_NUM_COST];
double price_cost_lf[MAX_NUM_COST];
double discount_cost_lf[MAX_NUM_COST];

int row_address;                                            //���Ʒѵص㡱��
char name_address[MAX_NUM_ADDRESS][MAX_NUM_STRING], head_name_address[MAX_NUM_STRING];
char ware_address[MAX_NUM_ADDRESS][MAX_NUM_STRING], head_ware_address[MAX_NUM_STRING];

int row_cost_other;                                         //�������ӷѡ���
char name_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_STRING], head_name_cost_other[MAX_NUM_STRING];
char area_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_STRING], head_area_cost_other[MAX_NUM_STRING];
char type_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_STRING], head_type_cost_other[MAX_NUM_STRING];
char unit_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_STRING], head_unit_cost_other[MAX_NUM_STRING];
char weight_start_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_DOUBLE_STRING], head_weight_start_cost_other[MAX_NUM_STRING];
char weight_end_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_DOUBLE_STRING], head_weight_end_cost_other[MAX_NUM_STRING];
char price_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_DOUBLE_STRING], head_price_cost_other[MAX_NUM_STRING];
char discount_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_DOUBLE_STRING], head_discount_cost_other[MAX_NUM_STRING];
double weight_start_cost_other_lf[MAX_NUM_COST_OTHER];
double weight_end_cost_other_lf[MAX_NUM_COST_OTHER];
double price_cost_other_lf[MAX_NUM_COST_OTHER];
double discount_cost_other_lf[MAX_NUM_COST_OTHER];


int warehouse_input_id, country_input_id, num_result;                              //�û�����
int name_area_id_result[MAX_NUM_RESULT];                                           //������������
int name_trans_id_result[MAX_NUM_RESULT];                                          //���䷽ʽ����
int code_trans_id_result[MAX_NUM_RESULT];
int area_area_id_result[MAX_NUM_RESULT];
int num_best_result_id, best_result_id[MAX_NUM_RESULT];
double weight_input;
double price_cost_lf_result[MAX_NUM_RESULT];
double price_cost_other_lf_result[MAX_NUM_RESULT];
double sum_result[MAX_NUM_RESULT];

int num_main_country, main_country[MAX_NUM_COUNTRY];                                        //���ù���

int read_file();
int check_data();
void prepare_data();
int get_input();
int get_input_warehouse();
int get_input_country();
int get_input_weight();
int find_code_and_name();
int find_area();
int get_sum();
int get_price_cost();
int get_price_cost_other();
void my_sort();
void get_best_result();
int get_main_country();
int run();
int write_csv_test(char *filename, int row);
int write_csv_result();
int write_csv_best_result(char path[MAX_NUM_STRING], char filename[MAX_NUM_STRING]);
int write_csv_main_country();

//��ȡ�ļ�
int read_file()
{
    FILE *fp;
    int i;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //��ȡ������

    /*
    ��ȡ�ֿ�
    */
    if((fp = fopen("./��������/�ֿ�.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'�ֿ�.csv'�ļ�ʧ��!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        if (i == 0)
        {
            strcpy(head_warehouse, strtok(strTemp,","));
        }
        else
        {
            strcpy(warehouse[i - 1], strtok(strTemp,","));
        }
        i++;
        if (i >= MAX_NUM_WAREHOUSE)
            printf("���棺���ֿ⡱����������ѳ�������\n");
    }
    row_warehouse = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'�ֿ�.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ����
    */
    if((fp = fopen("./��������/����.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'����.csv'�ļ�ʧ��!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        if (i == 0)
        {
            strcpy(head_country, strtok(strTemp,","));
            strcpy(head_code_country, strtok(NULL,","));
            strcpy(head_code_country, strtok(NULL,","));
        }
        else
        {
            strcpy(country[i - 1], strtok(strTemp,","));
            strcpy(code_country[i - 1], strtok(NULL,","));
            strcpy(code_country[i - 1], strtok(NULL,","));
        }
        i++;
        if (i >= MAX_NUM_COUNTRY)
            printf("���棺�����ҡ�����������ѳ�������\n");
    }
    row_country = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'����.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ���䷽ʽ
    */
    if((fp = fopen("./��������/���䷽ʽ.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'���䷽ʽ.csv'�ļ�ʧ��!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        if (i == 0)
        {
            strcpy(head_code_trans, strtok(strTemp,","));
            strcpy(head_name_trans, strtok(NULL,","));
            strcpy(head_ware_trans, strtok(NULL,","));
        }
        else
        {
            strcpy(code_trans[i - 1], strtok(strTemp,","));
            strcpy(name_trans[i - 1], strtok(NULL,","));
            strcpy(ware_trans[i - 1], strtok(NULL,","));
        }
        i++;
        if (i >= MAX_NUM_TRANS)
            printf("���棺�����䷽ʽ������������ѳ�������\n");
    }
    row_transport = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'���䷽ʽ.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ��������
    */
    if((fp = fopen("./��������/��������.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'��������.csv'�ļ�ʧ��!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        if (strlen(strTemp) >= MAX_NUM_STRINGS)
            printf("���棺���������ѳ���������ƣ�����Ϊ��%d\n", strlen(strTemp));
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        if (i == 0)
        {
            strcpy(head_name_area, strtok(strTemp,","));
            strcpy(head_code_area, strtok(NULL,","));
            strcpy(head_area_area, strtok(NULL,","));
            strcpy(head_country_area, strtok(NULL,","));
        }
        else
        {
            strcpy(name_area[i - 1], strtok(strTemp,","));
            strcpy(code_area[i - 1], strtok(NULL,","));
            strcpy(area_area[i - 1], strtok(NULL,","));
            strcpy(country_area[i - 1], strtok(NULL,","));
        }
        i++;
        if (i >= MAX_NUM_AREA)
            printf("���棺����������������������ѳ�������\n");
    }
    row_area = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'��������.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ��������
    */
    if((fp = fopen("./��������/��������.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'��������.csv'�ļ�ʧ��!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        if (i == 0)
        {
            strcpy(head_name_cost, strtok(strTemp,","));
            strcpy(head_area_cost, strtok(NULL,","));
            strcpy(head_type_cost, strtok(NULL,","));
            strcpy(head_weight_start_cost, strtok(NULL,","));
            strcpy(head_weight_end_cost, strtok(NULL,","));
            strcpy(head_weight_average_cost, strtok(NULL,","));
            strcpy(head_price_cost, strtok(NULL,","));
            strcpy(head_discount_cost, strtok(NULL,","));
        }
        else
        {
            strcpy(name_cost[i - 1], strtok(strTemp,","));
            strcpy(area_cost[i - 1], strtok(NULL,","));
            strcpy(type_cost[i - 1], strtok(NULL,","));
            strcpy(weight_start_cost[i - 1], strtok(NULL,","));
            strcpy(weight_end_cost[i - 1], strtok(NULL,","));
            strcpy(weight_average_cost[i - 1], strtok(NULL,","));
            strcpy(price_cost[i - 1], strtok(NULL,","));
            strcpy(discount_cost[i - 1], strtok(NULL,","));
        }
        i++;
        if (i >= MAX_NUM_COST)
            printf("���棺���������á�����������ѳ�������\n");
    }
    row_cost = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'��������.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ�Ʒѵص�
    */
    if((fp = fopen("./��������/�Ʒѵص�.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'�Ʒѵص�.csv'�ļ�ʧ��!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        if (i == 0)
        {
            strcpy(head_name_address, strtok(strTemp,","));
            strcpy(head_ware_address, strtok(NULL,","));
        }
        else
        {
            strcpy(name_address[i - 1], strtok(strTemp,","));
            strcpy(ware_address[i - 1], strtok(NULL,","));
        }
        i++;
        if (i >= MAX_NUM_ADDRESS)
            printf("���棺���Ʒѵص㡱����������ѳ�������\n");
    }
    row_address = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'�Ʒѵص�.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ�����ӷ�
    */
    if((fp = fopen("./��������/�����ӷ�.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'�����ӷ�.csv'�ļ�ʧ��!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        if (i == 0)
        {
            strcpy(head_name_cost_other, strtok(strTemp,","));
            strcpy(head_area_cost_other, strtok(NULL,","));
            strcpy(head_type_cost_other, strtok(NULL,","));
            strcpy(head_unit_cost_other, strtok(NULL,","));
            strcpy(head_weight_start_cost_other, strtok(NULL,","));
            strcpy(head_weight_end_cost_other, strtok(NULL,","));
            strcpy(head_price_cost_other, strtok(NULL,","));
            strcpy(head_discount_cost_other, strtok(NULL,","));
        }
        else
        {
            strcpy(name_cost_other[i - 1], strtok(strTemp,","));
            strcpy(area_cost_other[i - 1], strtok(NULL,","));
            strcpy(type_cost_other[i - 1], strtok(NULL,","));
            strcpy(unit_cost_other[i - 1], strtok(NULL,","));
            strcpy(weight_start_cost_other[i - 1], strtok(NULL,","));
            strcpy(weight_end_cost_other[i - 1], strtok(NULL,","));
            strcpy(price_cost_other[i - 1], strtok(NULL,","));
            strcpy(discount_cost_other[i - 1], strtok(NULL,","));
        }
        i++;
        if (i >= MAX_NUM_COST_OTHER)
            printf("���棺�������ӷѡ�����������ѳ�������\n");
    }
    row_cost_other = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'�����ӷ�.csv'�ļ��ɹ�!\n");

    return 0;
}

//�������ݵ��ı���������
int check_data()
{
    if (IF_WRITE_CSV == 0)return 0;
    if (write_csv_test("�ֿ⸱��.csv", row_warehouse))
        return -1;

    if (write_csv_test("���Ҹ���.csv", row_country))
        return -1;

    if (write_csv_test("���䷽ʽ����.csv", row_transport))
        return -1;

    if (write_csv_test("������������.csv", row_area))
        return -1;

    if (write_csv_test("�������ø���.csv", row_cost))
        return -1;

    if (write_csv_test("�Ʒѵص㸱��.csv", row_address))
        return -1;

    if (write_csv_test("�����ӷѸ���.csv", row_cost_other))
        return -1;
    return 0;
}

void prepare_data()
{
    int i;

    for (i = 0; i < row_cost; i++)
    {
        weight_start_cost_lf[i] = atof(weight_start_cost[i]);
        weight_end_cost_lf[i] = atof(weight_end_cost[i]);
        weight_average_cost_lf[i] = atof(weight_average_cost[i]);
        price_cost_lf[i] = atof(price_cost[i]);
        discount_cost_lf[i] = atof(discount_cost[i]);
    }

    for (i = 0; i < row_cost_other; i++)
    {
        weight_start_cost_other_lf[i] = atof(weight_start_cost_other[i]);
        weight_end_cost_other_lf[i] = atof(weight_end_cost_other[i]);
        price_cost_other_lf[i] = atof(price_cost_other[i]);
        discount_cost_other_lf[i] = atof(discount_cost_other[i]);
    }

    // printf("%s,%s,%s,%s,%s\n", 
    //     head_weight_start_cost, 
    //     head_weight_end_cost, 
    //     head_weight_average_cost, 
    //     head_price_cost, 
    //     head_discount_cost);
    // for (i = 0; i < row_cost; i++)
    //     printf("%lf,%lf,%lf,%lf,%lf\n", 
    //         weight_start_cost_lf[i], 
    //         weight_end_cost_lf[i], 
    //         weight_average_cost_lf[i], 
    //         price_cost_lf[i], 
    //         discount_cost_lf[i]);
    // printf("%s,%s,%s,%s\n", 
    //     head_weight_start_cost_other, 
    //     head_weight_end_cost_other, 
    //     head_price_cost_other, 
    //     head_discount_cost_other);
    // for (i = 0; i < row_cost_other; i++)
    //     printf("%lf,%lf,%lf,%lf\n", 
    //         weight_start_cost_other_lf[i], 
    //         weight_end_cost_other_lf[i], 
    //         price_cost_other_lf[i], 
    //         discount_cost_other_lf[i]);
}

int get_input()
{
    int choose;
    char c;

    choose = 0;
    printf("\t1������'�ֿ�+����'���������ݽ����˷Ѽ���\n\n");
    printf("\t2������'�ֿ�'���������ݽ����˷Ѽ���\n\n");
    printf("\t3������'����'���������ݽ����˷Ѽ���\n\n");
    printf("\t4��ȫ�������˷Ѽ���(����ʱ��ϳ�������ʹ��)\n\n");
    printf("\t5���˷Ѽ�����ֻ���������\n\n");
    printf("\t6���Գ��ù��ҽ��м��㣬��������ļ�\n\n");
    printf("\t7���˳�\n\n");
    while(1)
    {
        printf("��ѡ���������֣�ѡ���Ӧ������ģʽ��");
        scanf("%d", &choose);c = getchar();
        if (choose >= 1 && choose <= 7)
            break;
        printf("���벻���Ϲ淶����Ҫ�������롣\n");
    }
    if (choose == 7)
        return -1;
    if (choose == 1)
    {
        memset(price_cost_lf_result, 0, sizeof(price_cost_lf_result));
        memset(price_cost_other_lf_result, 0, sizeof(price_cost_other_lf_result));
        memset(sum_result, 0, sizeof(sum_result));
        if (get_input_warehouse())
            return -1;
        if (get_input_country())
            return -1;
    }
    if (choose == 2)
    {
        if (get_input_warehouse())
            return -1;
    }
    if (choose == 3)
    {
        if (get_input_country())
            return -1;
    }
    if (choose == 5)
    {
        if (get_input_warehouse())
            return -1;
        if (get_input_country())
            return -1;
        if (get_input_weight())
            return -1;
    }

    return choose;
}

int get_input_warehouse()
{
    int i, j;
    char tmp[MAX_NUM_STRING];
    while(1)
    {
        printf("���вֿ����£�\n\n");
        for (i = 0, j = 1; i < row_warehouse; i++, j++)
        {
            printf("%s", warehouse[i]);
            if (j % 3 == 0)
                printf("\n");
            else if (strlen(warehouse[i]) <= 8)
                printf("\t\t");
            else if (strlen(warehouse[i]) > 8 && strlen(warehouse[i]) <= 16)
                printf("\t");
        }
        if (j % 3 == 0)
            printf("\n");
        else
            printf("\n\n");
        printf("������ֿ�����ֿ����ƣ�֧��ģ�����룩��");
        gets(tmp);
        j = 0;
        for (i = 0; i < row_warehouse; i++)
            if (strstr(warehouse[i], tmp) != NULL)
            {
                j++;
                warehouse_input_id = i;
            }
        if (j == 0)
            printf("�����ڴ˲ֿ⣬���������룡\n\n\n");
        if (j > 1)
            printf("�������ݹ��٣����������룡\n\n\n");
        if (j == 1)
        {
            printf("��ѡ��Ĳֿ���'%s'\n\n\n", warehouse[warehouse_input_id]);
            break;
        }
    }

    return 0;
}

int get_input_country()
{
    int i, j;
    char tmp[MAX_NUM_STRING];
    while (1)
    {
        printf("������������ƣ�֧��ģ�����룩��");
        gets(tmp);
        j = 0;
        if (!strcmp(tmp, "����") ||                                                   //���⴦������ģ������
            !strcmp(tmp, "�յ�") || 
            !strcmp(tmp, "������") || 
            !strcmp(tmp, "������") || 
            !strcmp(tmp, "����˹") || 
            !strcmp(tmp, "����") || 
            !strcmp(tmp, "����") || 
            !strcmp(tmp, "ӡ��") || 
            !strcmp(tmp, "������") || 
            !strcmp(tmp, "������") || 
            !strcmp(tmp, "�չ�"))
        {
            for (i = 0; i < row_country; i++)
                if (!strcmp(country[i], tmp))
                {
                    j = 1;
                    country_input_id = i;
                    break;
                }
        }
        else 
        {
            for (i = 0; i < row_country; i++)
                if (strstr(country[i], tmp) != NULL)
                {
                    j++;
                    country_input_id = i;
                }
            if (j == 0)
                printf("�����ڴ˹��ң����������룡\n\n");
            if (j > 1)
                printf("�������ݹ��٣����������룡\n\n");
        }
        if (j == 1)
            break;
    }
    printf("������Ĺ�����'%s'\n\n\n", country[country_input_id]);

    return 0;
}

int get_input_weight()
{
    char tmp[MAX_NUM_DOUBLE_STRING];

    while (1)
    {
        printf("������������");
        gets(tmp);
        weight_input = atof(tmp);
        if (weight_input >= 0.000000 && weight_input <= 0.000001)
        {
            printf("��������\n");
        }
        else
        {
            printf("\n");
            break;
        }
    }

    return 0;
}

int find_code_and_name()
{
    int i;
    for (i = 0; i < row_transport; i++)
        if(!strcmp(ware_trans[i], warehouse[warehouse_input_id]))
        {
            name_trans_id_result[num_result] = i;
            code_trans_id_result[num_result] = i;
            num_result++;
        }
    return 0;
}

int find_area()
{
    int i, j;
    for (i = 0; i < num_result; i++)
    {
        for (j = 0; j < row_area; j++)
        {
            if ((strstr(country_area[j], country[country_input_id]) != NULL || 
                strstr(country_area[j], code_country[country_input_id]) != NULL) && 
                !strcmp(code_area[j], code_trans[code_trans_id_result[i]]))
            {
                name_area_id_result[i] = j;
                area_area_id_result[i] = j;
                break;
            }
        }
        if (j == row_area)
            price_cost_lf_result[i] = 99999999;
    }

    return 0;
}

int get_sum()
{
    int i;
    if (get_price_cost())
        return -1;
    if (get_price_cost_other())
        return -1;

    for(i = 0; i < num_result; i++)
        sum_result[i] = price_cost_lf_result[i] + price_cost_other_lf_result[i];
    return 0;
}

int get_price_cost()
{
    int i, j, k;

    for (i = 0; i < num_result; i++)
    {
        for (j = 0; j < row_cost; j++)
            if (!strcmp(name_cost[j], name_area[name_area_id_result[i]]) && 
                !strcmp(area_cost[j], area_area[area_area_id_result[i]]))
            {
                // �����ۡ�
                if (!strcmp(type_cost[j], "����") && 
                    weight_input > weight_start_cost_lf[j] && 
                    weight_input <=weight_end_cost_lf[j] &&
                    price_cost_lf_result[i] < 99999999)
                {
                    price_cost_lf_result[i] = weight_input * price_cost_lf[j] / weight_average_cost_lf[j] * discount_cost_lf[j];
                    break;
                }
                // ���ܼۡ�
                if (!strcmp(type_cost[j], "�ܼ�") && 
                    weight_input > weight_start_cost_lf[j] && 
                    weight_input <=weight_end_cost_lf[j] &&
                    price_cost_lf_result[i] < 99999999)
                {
                    price_cost_lf_result[i] = price_cost_lf[j] / weight_average_cost_lf[j] * discount_cost_lf[j];
                    break;
                }
                // ���ܼۡ�+��������""
                if (!strcmp(type_cost[j], "������") && 
                    weight_input > weight_start_cost_lf[j] && 
                    weight_input <=weight_end_cost_lf[j] &&
                    price_cost_lf_result[i] < 99999999)
                {
                    price_cost_lf_result[i] = (weight_input - weight_start_cost_lf[j]) * price_cost_lf[j] / weight_average_cost_lf[j] * discount_cost_lf[j];
                    for (k = 0; k < row_cost; k++)
                    {
                        if (!strcmp(name_cost[k], name_area[name_area_id_result[i]]) && 
                            !strcmp(area_cost[k], area_area[area_area_id_result[i]]) && 
                            weight_input > weight_end_cost_lf[k])
                        {
                            if (!strcmp(type_cost[k], "�ܼ�"))
                                price_cost_lf_result[i] += price_cost_lf[k];
                            // if (!strcmp(type_cost[k], "������"))
                            //     price_cost_lf_result[i] += price_cost_lf[k] * (weight_end_cost_lf[k] - weight_start_cost_lf[k]) / weight_average_cost_lf[k];
                        }
                    }
                    break;
                }
            }
        if (j == row_cost &&                                                        //��û���ҵ����ʵļ۸�ʱ�����Ϊ������
            price_cost_lf_result[i] >= 0.000000 && 
            price_cost_lf_result[i] <= 0.000001)
            price_cost_lf_result[i] = 88888888;
    }
    return 0;
}

int get_price_cost_other()
{
    int i, j, k;
    int flag;

    for (i = 0; i < num_result; i++)
    {
        flag = 0;
        for (j = 0; j < row_cost_other; j++)
            if (!strcmp(name_cost_other[j], name_area[name_area_id_result[i]]) && 
                !strcmp(area_cost_other[j], area_area[area_area_id_result[i]]))
            {
                for (k = 0; k < row_address; k++)
                    if (!strcmp(name_address[k], name_area[name_area_id_result[i]]) && 
                        !strcmp(ware_address[k], warehouse[warehouse_input_id]))
                    {
                        flag = 1;
                        break;
                    }
                if (flag == 0)                                                                      //����ӷ�û�а󶨸òֿ⣬���ӷ�Ϊ0
                    break;
                if (!strcmp(unit_cost_other[j], "Ʊ") && 
                    weight_input > weight_start_cost_other_lf[j] && 
                    weight_input <=weight_end_cost_other_lf[j])
                {
                    price_cost_other_lf_result[i] = price_cost_other_lf[j] * discount_cost_other_lf[j];
                    break;
                }
            }
    }
    return 0;
}

void my_sort()
{
    int i, j, temp_int;
    int flag = 1;
    double temp_double;

    while (flag)
    {
        flag = 0;
        for (i = 0; i < num_result - 1; i++)
            if (sum_result[i] > sum_result[i + 1])
            {
                temp_int = name_area_id_result[i];
                name_area_id_result[i] = name_area_id_result[i + 1];
                name_area_id_result[i + 1] = temp_int;

                temp_int = name_trans_id_result[i];
                name_trans_id_result[i] = name_trans_id_result[i + 1];
                name_trans_id_result[i + 1] = temp_int;

                temp_int = code_trans_id_result[i];
                code_trans_id_result[i] = code_trans_id_result[i + 1];
                code_trans_id_result[i + 1] = temp_int;

                temp_int = area_area_id_result[i];
                area_area_id_result[i] = area_area_id_result[i + 1];
                area_area_id_result[i + 1] = temp_int;

                temp_double = price_cost_lf_result[i];
                price_cost_lf_result[i] = price_cost_lf_result[i + 1];
                price_cost_lf_result[i + 1] = temp_double;

                temp_double = price_cost_other_lf_result[i];
                price_cost_other_lf_result[i] = price_cost_other_lf_result[i + 1];
                price_cost_other_lf_result[i + 1] = temp_double;

                temp_double = sum_result[i];
                sum_result[i] = sum_result[i + 1];
                sum_result[i + 1] = temp_double;

                flag = 1;
            }
    }
}

void get_best_result()
{
    int i, tmp;

    tmp = 0;
    for (i = 1; i < num_result; i++)
        if (sum_result[i] < sum_result[tmp])
            tmp = i;

    if (price_cost_lf_result[tmp] < 88888888)
    {
        num_best_result_id = 1;
        best_result_id[0] = tmp;
        for (i = tmp + 1; i < num_result; i++)
            if (sum_result[i] - sum_result[tmp] >= 0.000000 && sum_result[i] - sum_result[tmp] <= 0.000001)
            {
                best_result_id[num_best_result_id] = i;
                num_best_result_id++;
            }
    }
    else
        num_best_result_id = 0;
}

int get_main_country()
{
    int i, j, k;
    char area_main[] = "SZZYPY";
    char tmp[MAX_NUM_STRING];

    num_main_country = 0;
    memset(main_country, 0, sizeof(main_country));
    for (i = 0; i < row_area; i++)
    {
        if (!strcmp(code_area[i], area_main) && 
            (!strcmp(area_area[i], "1") || 
            !strcmp(area_area[i], "2") || 
            !strcmp(area_area[i], "3") || 
            !strcmp(area_area[i], "4") || 
            !strcmp(area_area[i], "8")))
        {
            if (strlen(country_area[i]) == 0)
            {
                printf("���棺'%s'��������,'%s'�����е�'%s'Ϊ�գ�\n", 
                    name_area[i], 
                    area_area[i], 
                    head_country_area);
                system("pause");
            }
            j = 0;
            while (j < strlen(country_area[i]))
            {
                k = 0;
                while (country_area[i][j] != '|' && j < strlen(country_area[i]))
                {
                    tmp[k] = country_area[i][j];
                    j++;k++;
                }
                j++;
                tmp[k] = '\0';
                k = 0;
                while (k < row_country)
                {
                    if (!strcmp(tmp, country[k]) || 
                        !strcmp(tmp, code_country[k]))
                    {
                        main_country[num_main_country] = k;
                        num_main_country++;
                        break;
                    }
                    k++;
                }
                if (k == row_country)
                {
                    printf("���������в����ڴ˹���'%s' %d %s\n", tmp, i, country_area[i]);
                    return -1;
                }
            }
        }
    }
    for (i = 0, j = 1; i < num_main_country; i++, j++)
    {
        // if (j % 3 == 0)
        //     printf("\n");
        // printf("%s\n", country[main_country[i]]);
        if (!strcmp(country[main_country[i]], "����͢") || 
            !strcmp(country[main_country[i]], "AR"))
        {
            printf("%s�Ѵ���\n", "����͢");
            break;
        }
        if (!strcmp(country[main_country[i]], "����") || 
            !strcmp(country[main_country[i]], "BR"))
        {
            printf("%s�Ѵ���\n", "����");
            break;
        }
        if (!strcmp(country[main_country[i]], "ɳ�ذ�����") || 
            !strcmp(country[main_country[i]], "SA"))
        {
            printf("%s�Ѵ���\n", "ɳ�ذ�����");
            break;
        }
        if (!strcmp(country[main_country[i]], "����˹") || 
            !strcmp(country[main_country[i]], "RU"))
        {
            printf("%s�Ѵ���\n", "����˹");
            break;
        }
    }
    k = 0;
    while (k < row_country)
    {
        if (!strcmp("����͢", country[k]) || 
            !strcmp("����͢", code_country[k]))
        {
            main_country[num_main_country] = k;
            num_main_country++;
            break;
        }
        k++;
    }
    k = 0;
    while (k < row_country)
    {
        if (!strcmp("����", country[k]) || 
            !strcmp("����", code_country[k]))
        {
            main_country[num_main_country] = k;
            num_main_country++;
            break;
        }
        k++;
    }
    k = 0;
    while (k < row_country)
    {
        if (!strcmp("ɳ�ذ�����", country[k]) || 
            !strcmp("ɳ�ذ�����", code_country[k]))
        {
            main_country[num_main_country] = k;
            num_main_country++;
            break;
        }
        k++;
    }
    k = 0;
    while (k < row_country)
    {
        if (!strcmp("����˹", country[k]) || 
            !strcmp("����˹", code_country[k]))
        {
            main_country[num_main_country] = k;
            num_main_country++;
            break;
        }
        k++;
    }

    return 0;
}

int run()
{
    int i, j;
    int choose;

    choose = get_input();
    if (choose == -1)
        return -1;
    if (choose == 1)
    {
        if (write_csv_best_result(warehouse[warehouse_input_id], country[country_input_id]))
            return -1;
    }
    if (choose == 2)
    {
        for (i = 0; i < row_country; i++)
        {
            country_input_id = i;
            memset(price_cost_lf_result, 0, sizeof(price_cost_lf_result));
            memset(price_cost_other_lf_result, 0, sizeof(price_cost_other_lf_result));
            memset(sum_result, 0, sizeof(sum_result));
            if (write_csv_best_result(warehouse[warehouse_input_id], country[country_input_id]))
                return -1;
            printf("���Ͳ֣�%s��Ŀ�Ĺ��ң�%s\n", warehouse[warehouse_input_id], country[country_input_id]);
        }
    }
    if (choose == 3)
    {
        for (i = 0; i < row_warehouse; i++)
        {
            warehouse_input_id = i;
            memset(price_cost_lf_result, 0, sizeof(price_cost_lf_result));
            memset(price_cost_other_lf_result, 0, sizeof(price_cost_other_lf_result));
            memset(sum_result, 0, sizeof(sum_result));
            if (write_csv_best_result(warehouse[warehouse_input_id], country[country_input_id]))
                return -1;
            printf("���Ͳ֣�%s��Ŀ�Ĺ��ң�%s\n", warehouse[warehouse_input_id], country[country_input_id]);
        }
    }
    if (choose == 4)
    {
        for (i = 0; i < row_warehouse; i++)
        {
            for (j = 0; j < row_country; j++)
                {
                    warehouse_input_id = i;
                    country_input_id = j;
                    memset(price_cost_lf_result, 0, sizeof(price_cost_lf_result));
                    memset(price_cost_other_lf_result, 0, sizeof(price_cost_other_lf_result));
                    memset(sum_result, 0, sizeof(sum_result));
                    if (write_csv_best_result(warehouse[warehouse_input_id], country[country_input_id]))
                        return -1;
                    printf("���Ͳ֣�%s��Ŀ�Ĺ��ң�%s\n", warehouse[warehouse_input_id], country[country_input_id]);
                }
        }
    }
    if (choose == 5)
    {
        num_result = 0;
        if (find_code_and_name())
            return -1;
        if (find_area())
            return -1;
        if (get_sum())
            return -1;

        my_sort();
        printf("%s,%s,%s,%s,%s,%s,%s\n", 
            head_name_trans, 
            head_code_trans, 
            head_area_area, 
            "����", 
            "�˷�", 
            "�ӷ�", 
            "�ܷ���");
        for(i = 0; i < num_result; i++)
        {
            if (price_cost_lf_result[i] < 88888888)
                printf("%s,%s,%s,%.2lf,%.2lf,%.2lf,%.2lf\n", 
                    name_trans[name_trans_id_result[i]], 
                    code_trans[code_trans_id_result[i]], 
                    area_area[area_area_id_result[i]], 
                    weight_input, 
                    price_cost_lf_result[i], 
                    price_cost_other_lf_result[i], 
                    sum_result[i]);
            else
                printf("%s,%s,%s\n", 
                    name_trans[name_trans_id_result[i]], 
                    code_trans[code_trans_id_result[i]], 
                    "�����ͷ�ʽ��֧�ָù���");
        }
        write_csv_result();
        system("pause");
    }
    if (choose == 6)
    {
        if (get_main_country())
            return -1;
        for (i = 0; i < row_warehouse; i++)
        {
            warehouse_input_id = i;
            if (write_csv_main_country())
                return -1;
            printf("���ù��������ʷѽ�����(%s).csv �����\n\n", warehouse[warehouse_input_id]);
            // system("pause");
        }
    }

    return 0;
}

int write_csv_test(char *filename, int row)
{
    FILE *fp;
    int i;

    if(!strcmp(filename, "�ֿ⸱��.csv"))
    {
        if((fp = fopen("./��������/�ֿ⸱��.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
        {
            printf("��'%s'�ļ�ʧ��!\n", filename);
            return -1;
        }

        fprintf(fp, "%s\n", head_warehouse);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s\n", warehouse[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "���Ҹ���.csv"))
    {
        if((fp = fopen("./��������/���Ҹ���.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
        {
            printf("��'%s'�ļ�ʧ��!\n", filename);
            return -1;
        }

        fprintf(fp, "%s,%s\n", head_country, head_code_country);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s\n", country[i], code_country[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "���䷽ʽ����.csv"))
    {
        if((fp = fopen("./��������/���䷽ʽ����.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
        {
            printf("��'%s'�ļ�ʧ��!\n", filename);
            return -1;
        }

        fprintf(fp, "%s,%s,%s\n", head_code_trans, head_name_trans, head_ware_trans);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s,%s\n", code_trans[i], name_trans[i], ware_trans[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "������������.csv"))
    {
        if((fp = fopen("./��������/������������.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
        {
            printf("��'%s'�ļ�ʧ��!\n", filename);
            return -1;
        }

        fprintf(fp, "%s,%s,%s,%s\n", 
            head_name_area, 
            head_code_area, 
            head_area_area, 
            head_country_area);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s,%s,%s\n", 
                name_area[i], 
                code_area[i], 
                area_area[i], 
                country_area[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "�������ø���.csv"))
    {
        if((fp = fopen("./��������/�������ø���.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
        {
            printf("��'%s'�ļ�ʧ��!\n", filename);
            return -1;
        }

        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", 
            head_name_cost, 
            head_area_cost, 
            head_type_cost, 
            head_weight_start_cost, 
            head_weight_end_cost, 
            head_weight_average_cost, 
            head_price_cost, 
            head_discount_cost);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s,%s,%lf,%lf,%lf,%lf,%lf\n", 
                name_cost[i], 
                area_cost[i], 
                type_cost[i], 
                weight_start_cost_lf[i], 
                weight_end_cost_lf[i], 
                weight_average_cost_lf[i], 
                price_cost_lf[i], 
                discount_cost_lf[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "�Ʒѵص㸱��.csv"))
    {
        if((fp = fopen("./��������/�Ʒѵص㸱��.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
        {
            printf("��'%s'�ļ�ʧ��!\n", filename);
            return -1;
        }

        fprintf(fp, "%s,%s\n", head_name_address, head_ware_address);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s\n", name_address[i], ware_address[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "�����ӷѸ���.csv"))
    {
        if((fp = fopen("./��������/�����ӷѸ���.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
        {
            printf("��'%s'�ļ�ʧ��!\n", filename);
            return -1;
        }

        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", 
            head_name_cost_other, 
            head_area_cost_other, 
            head_type_cost_other, 
            head_unit_cost_other, 
            head_weight_start_cost_other, 
            head_weight_end_cost_other, 
            head_price_cost_other, 
            head_discount_cost_other);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s,%s,%s,%lf,%lf,%lf,%lf\n", 
                name_cost_other[i], 
                area_cost_other[i], 
                type_cost_other[i], 
                unit_cost_other[i], 
                weight_start_cost_other_lf[i], 
                weight_end_cost_other_lf[i], 
                price_cost_other_lf[i], 
                discount_cost_other_lf[i]);

        fclose(fp);
    }

    return 0;
}

int write_csv_result()
{
    FILE *fp;
    int i;

    if((fp = fopen("����.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'%s'�ļ�ʧ��!", "����.csv");
        return -1;
    }

    my_sort();
    fprintf(fp, "�����֣�,Ŀ�ĵع��ң�,������\n");
    fprintf(fp, "%s,%s,%lf\n\n", warehouse[warehouse_input_id], country[country_input_id], weight_input);
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s\n", 
        head_name_trans, 
        head_code_trans, 
        head_area_area, 
        "����", 
        "�˷�", 
        "�ӷ�", 
        "�ܷ���");
    for(i = 0; i < num_result; i++)
    {
        if (price_cost_lf_result[i] < 88888888)
            fprintf(fp, "%s,%s,%s,%lf,%lf,%lf,%lf\n", 
                name_trans[name_trans_id_result[i]], 
                code_trans[code_trans_id_result[i]], 
                area_area[area_area_id_result[i]], 
                weight_input, 
                price_cost_lf_result[i], 
                price_cost_other_lf_result[i], 
                sum_result[i]);
        else
            fprintf(fp, "%s,%s,%s\n", 
                name_trans[name_trans_id_result[i]], 
                code_trans[code_trans_id_result[i]], 
                "�����ͷ�ʽ��֧�ָù���");
    }

    fclose(fp);

    return 0;
}

int write_csv_best_result(char path[MAX_NUM_STRING], char filename[MAX_NUM_STRING])
{
    FILE *fp, *fp_detail;
    int i, j;
    char realname[MAX_NUM_STRING] = "./������/";
    char realname_detail[MAX_NUM_STRING] = "./������/";

    num_result = 0;
    if (find_code_and_name())
        return -1;
    if (find_area())
        return -1;

    strcat(realname, path);strcat(realname_detail, path);
    strcat(realname, "/");strcat(realname_detail, "/");
    strcat(realname, filename);strcat(realname_detail, filename);
    strcat(realname, ".csv");strcat(realname_detail, "_��ϸ.csv");
    if((fp = fopen(realname,"w")) == NULL)                                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'%s.csv'�ļ�ʧ��!", filename);
        return -1;
    }
    if((fp_detail = fopen(realname_detail,"w")) == NULL)                    //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'%s_��ϸ.csv'�ļ�ʧ��!", filename);
        return -1;
    }

    fprintf(fp, "������,Ŀ�ĵع���\n");
    fprintf(fp, "%s,%s\n\n", warehouse[warehouse_input_id], country[country_input_id]);
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s\n", 
        "����", 
        "�˷�", 
        "�ӷ�", 
        "�ܷ���", 
        head_name_trans, 
        head_code_trans, 
        head_area_area);
    fprintf(fp_detail, "������,Ŀ�ĵع���\n");
    fprintf(fp_detail, "%s,%s\n\n", warehouse[warehouse_input_id], country[country_input_id]);
    fprintf(fp_detail, "%s,%s,%s,%s,%s,%s,%s\n", 
        "����", 
        "�˷�", 
        "�ӷ�", 
        "�ܷ���", 
        head_name_trans, 
        head_code_trans, 
        head_area_area);
    for (i = 1; i <= 2000; i++)
    {
        weight_input = i * 0.001;
        if (get_sum())
        {
            fclose(fp);
            fclose(fp_detail);
            return -1;
        }
        get_best_result();
        if (num_best_result_id == 0)
        {
            fprintf(fp, "%lf,��֧�ִ˹���\n", weight_input);
            fprintf(fp_detail, "%lf,��֧�ִ˹���\n", weight_input);
            continue;
        }
        for (j = 0; j < num_best_result_id; j++)                                        //�˷Ѽ��������
            fprintf(fp, "%lf,%lf,%lf,%lf,%s,%s,%s\n", 
                weight_input, 
                price_cost_lf_result[best_result_id[j]], 
                price_cost_other_lf_result[best_result_id[j]], 
                sum_result[best_result_id[j]], 
                name_trans[name_trans_id_result[best_result_id[j]]], 
                code_trans[code_trans_id_result[best_result_id[j]]], 
                area_area[area_area_id_result[best_result_id[j]]]);

        for (j = 0; j < num_best_result_id; j++)                                        //�˷Ѽ��������ϸ��
            fprintf(fp_detail, "%lf,%lf,%lf,%lf,%s,%s,%s\n", 
                weight_input, 
                price_cost_lf_result[best_result_id[j]], 
                price_cost_other_lf_result[best_result_id[j]], 
                sum_result[best_result_id[j]], 
                name_trans[name_trans_id_result[best_result_id[j]]], 
                code_trans[code_trans_id_result[best_result_id[j]]], 
                area_area[area_area_id_result[best_result_id[j]]]);
        fprintf(fp_detail, "\n");
        my_sort();
        fprintf(fp_detail, "%s,%s,%s,%s,%s,%s,%s\n", 
            head_name_trans, 
            head_code_trans, 
            head_area_area, 
            "����", 
            "�˷�", 
            "�ӷ�", 
            "�ܷ���");
        for(j = 0; j < num_result; j++)
        {
            if (price_cost_lf_result[j] < 88888888)
                fprintf(fp_detail, "%s,%s,%s,%lf,%lf,%lf,%lf\n", 
                    name_trans[name_trans_id_result[j]], 
                    code_trans[code_trans_id_result[j]], 
                    area_area[area_area_id_result[j]], 
                    weight_input, 
                    price_cost_lf_result[j], 
                    price_cost_other_lf_result[j], 
                    sum_result[j]);
            else
                fprintf(fp_detail, "%s,%s,%s\n", 
                    name_trans[name_trans_id_result[j]], 
                    code_trans[code_trans_id_result[j]], 
                    "�����ͷ�ʽ��֧�ָù���");
        }
        fprintf(fp_detail, "\n\n");
    }

    fclose(fp);
    fclose(fp_detail);
    return 0;
}

int write_csv_main_country()
{
    FILE *fp;
    int i, j, k;
    char last_transport[MAX_NUM_STRINGS], tmp[MAX_NUM_STRINGS];

    char realname[MAX_NUM_STRING] = "./������/���ù��������ʷѽ�����(";
    strcat(realname, warehouse[warehouse_input_id]);
    strcat(realname, ").csv");
    if((fp = fopen(realname,"w")) == NULL)                                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'���ù��������ʷѽ�����(%s).csv'�ļ�ʧ��!", 
            warehouse[warehouse_input_id]);
        return -1;
    }

    fprintf(fp, "%s,%s,%s,%s\n","����", "��ʼ����", "��������", "�������䷽ʽ");
    for (k = 0; k < num_main_country; k++)
    {
        country_input_id = main_country[k];
        num_result = 0;
        memset(price_cost_lf_result, 0, sizeof(price_cost_lf_result));
        memset(price_cost_other_lf_result, 0, sizeof(price_cost_other_lf_result));
        memset(sum_result, 0, sizeof(sum_result));
        if (find_code_and_name())
        {
            fclose(fp);
            return -1;
        }
        if (find_area())
        {
            fclose(fp);
            return -1;
        }

        strcpy(last_transport, "");
        for (i = 1; i <= 2000; i++)
        {
            weight_input = i * 0.001;
            if (get_sum())
            {
                fclose(fp);
                return -1;
            }
            get_best_result();
            if (num_best_result_id == 0)
            {
                strcpy(tmp, "�����ں��ʵ����䷽ʽ");
            }
            else{
                strcpy(tmp, name_trans[name_trans_id_result[best_result_id[0]]]);
                for (j = 1; j < num_best_result_id; j++)                                        //�˷Ѽ��������
                {
                    strcat(tmp, "|");
                    strcat(tmp, name_trans[name_trans_id_result[best_result_id[j]]]);
                }
            }
            if (!strcmp(last_transport, ""))
            {
                strcpy(last_transport, tmp);
                fprintf(fp, "%s,%lf", 
                    country[country_input_id], (weight_input - 0.001));
                continue;
            }
            if (strcmp(last_transport, tmp))
            {
                fprintf(fp, ",%lf,%s\n", weight_input, last_transport);
                strcpy(last_transport, tmp);
                fprintf(fp, "%s,%lf", 
                    country[country_input_id], (weight_input + 0.001));
            }
        }
        fprintf(fp, ",%lf,%s\n", weight_input, last_transport);
        printf("����ɹ��ң�%s\n", country[country_input_id]);
    }

    fclose(fp);
    return 0;
}

int main()
{
    if (read_file())
    {
        system("pause");
        return -1;
    }
    prepare_data();
    if (check_data())                                        //����ȡ�����Ƿ���ȷ
    {
        system("pause");
        return -1;
    }


    if (run())
    {
        system("pause");
        return -1;
    }

    return 0;
}
