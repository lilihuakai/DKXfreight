#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 2048                         //�ļ���ȡʱ��ÿ������ֽ���
#define MAX_NUM_STRING 50                                   //�ַ�������
#define MAX_NUM_STRINGS 1600                                //�����ַ�������
#define MAX_NUM_DOUBLE_STRING 16                            //�����ַ�������
#define IF_WRITE_CSV 0                                      //�Ƿ�����������ݵ��ļ�

#define MAX_NUM_COST 10000                                  //���������á������
#define MAX_NUM_COST_OTHER 10000                            //�������ӷѡ������


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

int read_file();
void prepare_data();
int check_price_equal(int a, int b, int type);
int check_weight();
int run();
int write_file();

//��ȡ�ļ�
int read_file()
{
    FILE *fp;
    int i;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //��ȡ������

    /*
    ��ȡ��������
    */
    if((fp = fopen("�������ø���.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'�������ø���.csv'�ļ�ʧ��!\n");
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
        printf("��ȡ'�������ø���.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ�����ӷ�
    */
    if((fp = fopen("�����ӷѸ���.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'�����ӷѸ���.csv'�ļ�ʧ��!\n");
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
        printf("��ȡ'�����ӷѸ���.csv'�ļ��ɹ�!\n");

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

int check_price_equal(int a, int b, int type)
{
    double x, y;
    if (type == 0)
    {
        x = price_cost_lf[a] * discount_cost_lf[a] / weight_average_cost_lf[a];
        y = price_cost_lf[b] * discount_cost_lf[b] / weight_average_cost_lf[b];
        if (x - y >= 0.000000 && x - y <= 0.000001)
            return 0;
        else
            return 1;
    }
    if (type == 1)
    {
        x = price_cost_other_lf[a] * discount_cost_other_lf[a];
        y = price_cost_other_lf[b] * discount_cost_other_lf[b];
        if (x - y >= 0.000000 && x - y <= 0.000001)
            return 0;
        else
            return 1;
    }

    printf("�۸��жϲ�������\n");
    return 0;
}

int check_weight()
{
    return 0;
}

int run()
{
    int i, j;

    if (check_weight())
    {
        return -1;
    }
    for (i = 0; i < row_cost; i++)                                                      //���۸���ȵ��ڽ����ν��
    {
        for (j = i + 1; j < row_cost; j++)
            if (!strcmp(name_cost[i], name_cost[j]) && 
                !strcmp(area_cost[i], area_cost[j]) && 
                !strcmp(type_cost[i], type_cost[j]))
            {
                if ((weight_start_cost_lf[i] - weight_end_cost_lf[j] >= 0.000000 && weight_start_cost_lf[i] - weight_end_cost_lf[j] <= 0.000001))
                {
                    if (check_price_equal(i, j, 0) == 0)
                    {
                        weight_end_cost_lf[j] = weight_end_cost_lf[i];
                        break;
                    }
                }
                if ((weight_start_cost_lf[j] - weight_end_cost_lf[i] >= 0.000000 && weight_start_cost_lf[j] - weight_end_cost_lf[i] <= 0.000001))
                {
                    if (check_price_equal(i, j, 0) == 0)
                    {
                        weight_start_cost_lf[j] = weight_start_cost_lf[i];
                        break;
                    }
                }
            }
        if (j < row_cost)
            price_cost_lf[i] = 0;
    }

    for (i = 0; i < row_cost_other; i++)                                                //���۸���ȵ��ڽ����ν��
    {
        for (j = i + 1; j < row_cost_other; j++)
            if (!strcmp(name_cost_other[i], name_cost_other[j]) && 
                !strcmp(area_cost_other[i], area_cost_other[j]) && 
                !strcmp(type_cost_other[i], type_cost_other[j]) && 
                !strcmp(unit_cost_other[i], unit_cost_other[j]))
            {
                if ((weight_start_cost_other_lf[i] - weight_end_cost_other_lf[j] >= 0.000000 && weight_start_cost_other_lf[i] - weight_end_cost_other_lf[j] <= 0.000001))
                {
                    if (check_price_equal(i, j, 1) == 0)
                    {
                        weight_end_cost_other_lf[j] = weight_end_cost_other_lf[i];
                        break;
                    }
                }
                if ((weight_start_cost_other_lf[j] - weight_end_cost_other_lf[i] >= 0.000000 && weight_start_cost_other_lf[j] - weight_end_cost_other_lf[i] <= 0.000001))
                {
                    if (check_price_equal(i, j, 1) == 0)
                    {
                        weight_start_cost_other_lf[j] = weight_start_cost_other_lf[i];
                        break;
                    }
                }
            }
        if (j < row_cost_other)
            price_cost_other_lf[i] = 0;
    }

    return 0;
}

int write_file()
{
    FILE *fp;
    int i;

    if((fp = fopen("�������ø���_�Ż���.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'�������ø���_�Ż���.csv'�ļ�ʧ��!\n");
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
    for(i = 0; i < row_cost; i++)
        if (price_cost_lf[i] > 0.000000)
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

    if((fp = fopen("�����ӷѸ���_�Ż���.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'�����ӷѸ���_�Ż���.csv'�ļ�ʧ��!\n");
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
    for(i = 0; i < row_cost_other; i++)
        if (price_cost_other_lf[i] > 0.000000)
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

    if (run())
    {
        system("pause");
        return -1;
    }

    if (write_file())
    {
        system("pause");
        return -1;
    }

    return 0;
}
