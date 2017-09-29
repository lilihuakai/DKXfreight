#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 1024                         //�ļ���ȡʱ��ÿ������ֽ���
#define MAX_NUM_STRING 50                                   //�ַ�������
#define MAX_NUM_STRINGS 500                                 //�����ַ�������
#define MAX_NUM_DOUBLE_STRING 16                            //�����ַ�������
#define IF_WRITE_CSV 0                                      //�Ƿ�����������ݵ��ļ�
#define IF_CHECK_INPUT 0                                    //�Ƿ�������������

#define MAX_NUM_WAREHOUSE 50                                //���ֿ⡱�����
#define MAX_NUM_COUNTRY 300                                 //�����ҡ������
#define MAX_NUM_TRANS 300                                   //�����䷽ʽ�������
#define MAX_NUM_AREA 300                                    //�����������������
#define MAX_NUM_COST 10000                                  //���������á������
#define MAX_NUM_ADDRESS 300                                 //���Ʒѵص㡱�����
#define MAX_NUM_COST_OTHER 10000                            //�������ӷѡ������

#define MAX_NUM_RESULT 300                                  //���������������


int row_warehouse;                                          //���ֿ⡱��
char warehouse[MAX_NUM_WAREHOUSE][MAX_NUM_STRING], head_warehouse[MAX_NUM_STRING];

int row_country;                                            //�����ҡ���
char country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_country[MAX_NUM_STRING];

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


<<<<<<< HEAD
int warehose_input,num_result;                              //�û�����
char country_input[30];
double sum[MAX_NUM_RESULT];
=======
int warehouse_input_id, country_input_id, num_result;                                //�û�����
int name_area_id_result[MAX_NUM_RESULT];                                           //������������
int name_trans_id_result[MAX_NUM_RESULT];                                          //���䷽ʽ����
int code_trans_id_result[MAX_NUM_RESULT];
int area_area_id_result[MAX_NUM_RESULT];
double weight_input;
double price_cost_lf_result[MAX_NUM_RESULT];
double price_cost_other_lf_result[MAX_NUM_RESULT];
double sum_result[MAX_NUM_RESULT];

>>>>>>> 1.修改了杂费计算错误的问题;2.添加了杂费的计费地点的验证;3.修改了名称错误的问题

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
        }
        else
        {
            strcpy(country[i - 1], strtok(strTemp,","));
        }
        i++;
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
    }
    row_address = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'�Ʒѵص�.csv'�ļ��ɹ�!\n");

<<<<<<< HEAD
    if (check_file())                                        //����ȡ�����Ƿ���ȷ
        return -1;

    return 0;
}

int read_csv(char *filename, int *row, int column, char strline[MAX_NUM_ROW][MAX_NUM_COLUMN][MAX_NUM_STRING])
{
    FILE *fp;
    int i, j;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //��ȡ������

    if((fp = fopen(filename,"r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
=======
    /*
    ��ȡ�����ӷ�
    */
    if((fp = fopen("./��������/�����ӷ�.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
>>>>>>> 优化了文本数据获取的方式
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
    }
    row_cost_other = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'�����ӷ�.csv'�ļ��ɹ�!\n");

    return 0;
}

//�������ݵ��ı���������
int check_file()
{
    if (IF_WRITE_CSV == 0)return 0;
    if (write_csv("�ֿ⸱��.csv", row_warehouse))
        return -1;

    if (write_csv("���Ҹ���.csv", row_country))
        return -1;

    if (write_csv("���䷽ʽ����.csv", row_transport))
        return -1;

    if (write_csv("������������.csv", row_area))
        return -1;

    if (write_csv("�������ø���.csv", row_cost))
        return -1;

    if (write_csv("�Ʒѵص㸱��.csv", row_address))
        return -1;

    if (write_csv("�����ӷѸ���.csv", row_cost_other))
        return -1;
    return 0;
}

void check_input()
{
    int i;
    printf("ϵͳ�ڵĲֿ�������%d\n", warehouse_input_id);
    printf("ϵͳ�ڵĹ���������%d\n\n", country_input_id);
    printf("��������䷽ʽ������%d\n", num_result);
    printf("�����������%lf\n", weight_input);
    for (i = 0; i < num_result; i++)
    {
        printf("����ķ���������%d\n", name_area_id_result[i]);
        printf("��������䷽ʽ��%d\n", name_trans_id_result[i]);
        printf("����������ţ�%d\n", code_trans_id_result[i]);
        printf("��������ѷ�����%d\n", area_area_id_result[i]);
        printf("���������۸�%lf\n", price_cost_lf_result);
        printf("������ӷѼ۸�%lf\n", price_cost_other_lf_result);
        printf("������ܼۣ�%lf\n\n", sum_result);
    }
}

int write_csv(char *filename, int row)
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

        fprintf(fp, "%s\n", head_country);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s\n", country[i]);

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
            fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", 
                name_cost[i], 
                area_cost[i], 
                type_cost[i], 
                weight_start_cost[i], 
                weight_end_cost[i], 
                weight_average_cost[i], 
                price_cost[i], 
                discount_cost[i]);

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
<<<<<<< HEAD
            fprintf(fp, "%s,%s,%s,%s,%s,%s,%s\n", 
                name_cost_other[i], 
                area_cost_other[i], 
                type_cost_other[i], 
                weight_start_cost_other[i], 
                weight_end_cost_other[i], 
                price_cost_other[i], 
                discount_cost_other[i]);
=======
            fprintf(fp, "%s,%s,%s,%s,%lf,%lf,%lf,%lf\n", 
                name_cost_other[i], 
                area_cost_other[i], 
                type_cost_other[i], 
                unit_cost_other[i], 
                weight_start_cost_other_lf[i], 
                weight_end_cost_other_lf[i], 
                price_cost_other_lf[i], 
                discount_cost_other_lf[i]);
>>>>>>> 在物流杂费中新增一列数据

        fclose(fp);
    }

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
<<<<<<< HEAD
=======
    if (get_input_warehouse())
        return -1;
    if (get_input_country())
        return -1;
    if (get_input_weight())
        return -1;
    return 0;
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
            if (strstr(country_area[j], country[country_input_id]) != NULL && 
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

int write_csv_result()
{
    FILE *fp;
    int i;

    if((fp = fopen("����.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'%s'�ļ�ʧ��!", "����.csv");
        return -1;
    }

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
        if (sum_result[i] < 99999999)
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
        if (j == row_cost && 
            price_cost_lf_result[i] >= 0.000000 && 
            price_cost_lf_result[i] <= 0.000001)
            price_cost_lf_result[i] = 99999999;
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

int run()
{
    int i;
    num_result = 0;

    if (find_code_and_name())
        return -1;
    if (find_area())
        return -1;

    if (IF_CHECK_INPUT != 0)
        check_input();
    if (get_sum())
        return -1;
    if (IF_CHECK_INPUT != 0)
        check_input();

    if (write_csv_result())
        return -1;

    printf("�����֣�%s\n", warehouse[warehouse_input_id]);
    printf("Ŀ�ĵع��ң�%s\n", country[country_input_id]);
    printf("������%lf\n\n", weight_input);
    printf("%s,%s,%s,%s,%s,%s,%s\n", 
        head_name_trans, 
        head_code_trans, 
        head_area_area, 
        "����", 
        "�˷�", 
        "�ӷ�", 
        "�ܷ���");
    for (i = 0; i < num_result; i++)
    {
        if (strlen(name_trans[name_trans_id_result[i]]) >= 16)
            printf("%s\t", name_trans[name_trans_id_result[i]]);
        else if (strlen(name_trans[name_trans_id_result[i]]) >= 8)
            printf("%s\t\t", name_trans[name_trans_id_result[i]]);
        else
            printf("%s\t\t\t", name_trans[name_trans_id_result[i]]);

        if (sum_result[i] < 99999999)
            printf("%s %s %lf %lf %lf %lf\n", 
                code_trans[code_trans_id_result[i]], 
                area_area[area_area_id_result[i]], 
                weight_input, 
                price_cost_lf_result[i], 
                price_cost_other_lf_result[i], 
                sum_result[i]);
        else
            printf("%s %s\n", 
                code_trans[code_trans_id_result[i]], 
                "�����ͷ�ʽ��֧�ָù���");
    }

    printf("\n");
>>>>>>> 1.修改了杂费计算错误的问题;2.添加了杂费的计费地点的验证;3.修改了名称错误的问题

    return 0;
}

int main()
{
    if (read_file())
        return -1;
    prepare_data();

    memset(price_cost_lf_result, 0, sizeof(price_cost_lf_result));
    memset(price_cost_other_lf_result, 0, sizeof(price_cost_other_lf_result));
    memset(sum_result, 0, sizeof(sum_result));
    if (get_input())
        return -1;

    return 0;
}
