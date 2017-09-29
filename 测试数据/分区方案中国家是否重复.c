#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 2048                         //�ļ���ȡʱ��ÿ������ֽ���
#define MAX_NUM_STRING 50                                   //�ַ�������
#define MAX_NUM_STRINGS 1600                                //�����ַ�������
#define MAX_NUM_DOUBLE_STRING 16                            //�����ַ�������
#define IF_WRITE_CSV 0                                      //�Ƿ�����������ݵ��ļ�
#define IF_CHECK_INPUT 0                                    //�Ƿ�������������

#define MAX_NUM_COUNTRY 300                                 //�����ҡ������
#define MAX_NUM_AREA 1500                                   //�����������������


int row_country;                                            //�����ҡ���
char country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_country[MAX_NUM_STRING];
char code_country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_code_country[MAX_NUM_STRING];

int row_area;                                               //��������������
char name_area[MAX_NUM_AREA][MAX_NUM_STRING], head_name_area[MAX_NUM_STRING];
char code_area[MAX_NUM_AREA][MAX_NUM_STRING], head_code_area[MAX_NUM_STRING];
char area_area[MAX_NUM_AREA][MAX_NUM_STRING], head_area_area[MAX_NUM_STRING];
char country_area[MAX_NUM_AREA][MAX_NUM_STRINGS], head_country_area[MAX_NUM_STRING];

char two_code[MAX_NUM_AREA][MAX_NUM_STRINGS];
char chinese_name[MAX_NUM_AREA][MAX_NUM_STRINGS];

//��ȡ�ļ�
int read_file()
{
    FILE *fp;
    int i;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //��ȡ������

    /*
    ��ȡ����
    */
    if((fp = fopen("���Ҹ���.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'���Ҹ���.csv'�ļ�ʧ��!\n");
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
            strcpy(head_code_country, strtok(NULL, ","));
        }
        else
        {
            strcpy(country[i - 1], strtok(strTemp,","));
            strcpy(code_country[i - 1], strtok(NULL, ","));
        }
        i++;
        if (i >= MAX_NUM_COUNTRY)
            printf("���棺�����ҡ�����������ѳ�������\n");
    }
    row_country = i - 1;
    fclose(fp);                                             //�ر��ļ�
    if (IF_WRITE_CSV == 1)
        printf("��ȡ'���Ҹ���.csv'�ļ��ɹ�!\n");

    /*
    ��ȡ��������
    */
    if((fp = fopen("������������.csv","r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'������������.csv'�ļ�ʧ��!\n");
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
        printf("��ȡ'������������.csv'�ļ��ɹ�!\n");

    return 0;
}

int is_repeat(int area_id, int country_id)
{
    int i, num;

    num = 0;
    for (i = 0; i < row_area; i++)
    {
        if (!strcmp(code_area[i], code_area[area_id]) && 
            (strstr(country_area[i], country[country_id]) != NULL ||
                strstr(country_area[i], code_country[country_id]) != NULL))
            num++;
    }
    if (!strcmp(country[country_id], "����"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "����������С����") != NULL ||
                    strstr(country_area[i], "UM") != NULL))
                num--;
        }
    }

    if (!strcmp(country[country_id], "�յ�"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "���յ����͹�") != NULL ||
                    strstr(country_area[i], "SS") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "������"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "��������������") != NULL ||
                    strstr(country_area[i], "XG") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "������"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "�����ﹲ�͹�") != NULL ||
                    strstr(country_area[i], "XS") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "����˹"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "�׶���˹(������)") != NULL ||
                    strstr(country_area[i], "BY") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "����"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "��������(����)") != NULL ||
                    strstr(country_area[i], "XC") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "����"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "�����ﹲ�͹�") != NULL ||
                    strstr(country_area[i], "XS") != NULL ||
                    strstr(country_area[i], "������") != NULL ||
                    strstr(country_area[i], "SO") != NULL ||
                    strstr(country_area[i], "����������Ⱥ��") != NULL ||
                    strstr(country_area[i], "MP") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "ӡ��"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "Ӣ��ӡ�������(���Ⱥ��)") != NULL ||
                    strstr(country_area[i], "IO") != NULL ||
                    strstr(country_area[i], "ӡ��������") != NULL ||
                    strstr(country_area[i], "ID") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "������"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "����������") != NULL ||
                    strstr(country_area[i], "GF") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "������"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "���������") != NULL ||
                    strstr(country_area[i], "GQ") != NULL ||
                    strstr(country_area[i], "�Ͳ����¼�����") != NULL ||
                    strstr(country_area[i], "PG") != NULL ||
                    strstr(country_area[i], "�����Ǳ���") != NULL ||
                    strstr(country_area[i], "GW") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "�չ�"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "�չ��������͹�") != NULL ||
                    strstr(country_area[i], "CD") != NULL))
                num--;
        }
    }

    return num;
}

int run()
{
    int i, j, k, country_id, area_id;
    char tmp[MAX_NUM_STRING];

    for (i = 0; i < row_area; i++)
    {
        if (strlen(country_area[i]) == 0)
        {
            printf("���棺'%s'��������,'%s'�����е�'%s'Ϊ�գ�\n", name_area[i], area_area[i], head_country_area);
            system("pause");
        }
        j = 0;area_id = i;
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
                if (!strcmp(tmp, country[k]) || !strcmp(tmp, code_country[k]))
                {
                    country_id = k;
                    break;
                }
                k++;
            }
            if (k == row_country)
            {
                printf("���������в����ڴ˹���'%s' %d %s\n", tmp, i, country_area[i]);
                return -1;
            }
            k = is_repeat(area_id, country_id);
            if (k > 1)
            {
                printf("'%s'����������'%s'�ĳ��ִ����ǣ�%d\n", name_area[area_id], country[country_id], k);
            }
        }
    }

    return 0;
}

int main()
{
    if (read_file())
    {
        system("pause");
        return -1;
    }

    if (run())
        return -1;

    system("pause");

    return 0;
}
