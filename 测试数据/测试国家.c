#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 1024                         //�ļ���ȡʱ��ÿ������ֽ���
#define MAX_NUM_ROW 300                                     //�����е��������
#define MAX_NUM_COLUMN 10                                   //�����е��������
#define MAX_NUM_STRING 30                                   //�ַ�������
#define MAX_NUM_INT 8                                       //���ֳ���
#define IF_WRITE_CSV 0                                      //�Ƿ�����������ݵ��ļ�

#define MAX_NUM_WAREHOUSE 50                                //���ֿ⡱�����
#define MAX_NUM_COUNTRY 300                                 //�����ҡ������
#define MAX_NUM_TRANS 300                                   //�����䷽ʽ�������
#define MAX_NUM_AREA 300                                    //�����������������
#define MAX_NUM_AREA_COUNT 500                              //����������-���ҡ������
#define MAX_NUM_COST 300                                    //���������á������
#define MAX_NUM_ADDRESS 300                                 //���Ʒѵص㡱�����
#define MAX_NUM_COST_OTHER 300                              //�������ӷѡ������

#define MAX_NUM_RESULT 300                                  //���������������


int row_warehouse;                                          //���ֿ⡱��
char warehouse[MAX_NUM_WAREHOUSE][MAX_NUM_STRING], head_warehouse[MAX_NUM_STRING];

int row_country;                                            //�����ҡ���
char country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_country[MAX_NUM_STRING];


//��ȡ�ļ�
int read_file()
{
    int i;
    char filename[MAX_NUM_STRING];
    char strline[MAX_NUM_ROW][MAX_NUM_COLUMN][MAX_NUM_STRING];

    strcpy(filename, "���Ҹ���.csv");
    if (read_csv(filename, &row_country, 1, strline))
    {
        printf("��ȡ'%s'�ļ�ʧ��!", filename);
        return -1;
    }
    strcpy(head_country, strline[0][0]);
    for (i = 0; i < row_country; i++)
    {
        strcpy(country[i], strline[i + 1][0]);
    }

    return 0;
}

int read_csv(char *filename, int *row, int column, char strline[MAX_NUM_ROW][MAX_NUM_COLUMN][MAX_NUM_STRING])
{
    FILE *fp;
    int i, j;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //��ȡ������

    if((fp = fopen(filename,"r")) == NULL)                  //�ж��ļ��Ƿ���ڼ��ɶ�
    {
        printf("��'%s'�ļ�ʧ��!", filename);
        return -1;
    }

    i = 0;
    while (1)                                               //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //��fp��ָ����ļ�һ�����ݶ���strLine������
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //������з�
        strcpy(strline[i][0], strtok(strTemp,","));
        for (j = 1; j < column; j++)
        {
            strcpy(strline[i][j], strtok(NULL,","));
        }
        i++;
    }
    *row = i - 1;

    // for (i = 0; i < *row; i++)
    // {
    //     for (j = 0; j < column; j++)
    //         printf("%s ", strline[i][j]);
    //     printf("\n");
    // }

    fclose(fp);                                             //�ر��ļ�

    return 0;
}

int main()
{
    if (read_file())
        return -1;

    int i, j, k = 0;
    for (i = 0; i < row_country; i++)
    {
        for (j = 0; j < row_country; j++)
            if (i != j && strstr(country[j], country[i]) != NULL)
            {
                printf("%s  %s\n", country[i], country[j]);
                k++;break;
            }
    }
    printf("\n\n��Ҫ���⴦��Ĺ�������������%d\n", k);

    return 0;
}
