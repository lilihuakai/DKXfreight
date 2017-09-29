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

int run()
{
    int i, j, k;
    char tmp[MAX_NUM_STRING];

    memset(two_code, 0, sizeof(two_code));
    memset(chinese_name, 0, sizeof(chinese_name));
    for (i = 0; i < row_area; i++)
    {
        if (strlen(country_area[i]) == 0)
        {
            printf("���棺'%s'��������,'%s'�����е�'%s'Ϊ�գ�\n", name_area[i], area_area[i], head_country_area);
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
                if (!strcmp(tmp, country[k]) || !strcmp(tmp, code_country[k]))
                {
                    if (strlen(two_code[i]))
                        strcat(two_code[i], "|");
                    strcat(two_code[i], code_country[k]);
                    if (strlen(chinese_name[i]))
                        strcat(chinese_name[i], "|");
                    strcat(chinese_name[i], country[k]);
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

    return 0;
}

int write_file()
{
    FILE *fp;
    int i;

    if((fp = fopen("������������_��λ��.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'������������_��λ��.csv'�ļ�ʧ��!\n");
        return -1;
    }
    fprintf(fp, "%s,%s,%s,%s\n", 
        head_name_area, 
        head_code_area, 
        head_area_area, 
        head_country_area);
    for(i = 0; i < row_area; i++)
        fprintf(fp, "%s,%s,%s,%s\n", 
            name_area[i], 
            code_area[i], 
            area_area[i], 
            two_code[i]);
    fclose(fp);

    if((fp = fopen("������������_������.csv","w")) == NULL)                  //�ж��ļ��Ƿ���ڼ���д
    {
        printf("��'������������_������.csv'�ļ�ʧ��!\n");
        return -1;
    }
    fprintf(fp, "%s,%s,%s,%s\n", 
        head_name_area, 
        head_code_area, 
        head_area_area, 
        head_country_area);
    for(i = 0; i < row_area; i++)
        fprintf(fp, "%s,%s,%s,%s\n", 
            name_area[i], 
            code_area[i], 
            area_area[i], 
            chinese_name[i]);
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

    if (run())
        return -1;

    if (write_file())
        return -1;

    return 0;
}
