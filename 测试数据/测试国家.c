#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 1024                         //文件读取时，每行最大字节数
#define MAX_NUM_ROW 300                                     //数据行的最大数量
#define MAX_NUM_COLUMN 10                                   //数据列的最大数量
#define MAX_NUM_STRING 30                                   //字符串长度
#define MAX_NUM_INT 8                                       //数字长度
#define IF_WRITE_CSV 0                                      //是否输出测试数据到文件

#define MAX_NUM_WAREHOUSE 50                                //“仓库”最大数
#define MAX_NUM_COUNTRY 300                                 //“国家”最大数
#define MAX_NUM_TRANS 300                                   //“运输方式”最大数
#define MAX_NUM_AREA 300                                    //“分区方案”最大数
#define MAX_NUM_AREA_COUNT 500                              //“分区方案-国家”最大数
#define MAX_NUM_COST 300                                    //“物流费用”最大数
#define MAX_NUM_ADDRESS 300                                 //“计费地点”最大数
#define MAX_NUM_COST_OTHER 300                              //“物流杂费”最大数

#define MAX_NUM_RESULT 300                                  //“输出结果”最大数


int row_warehouse;                                          //“仓库”表
char warehouse[MAX_NUM_WAREHOUSE][MAX_NUM_STRING], head_warehouse[MAX_NUM_STRING];

int row_country;                                            //“国家”表
char country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_country[MAX_NUM_STRING];


//读取文件
int read_file()
{
    int i;
    char filename[MAX_NUM_STRING];
    char strline[MAX_NUM_ROW][MAX_NUM_COLUMN][MAX_NUM_STRING];

    strcpy(filename, "国家副本.csv");
    if (read_csv(filename, &row_country, 1, strline))
    {
        printf("读取'%s'文件失败!", filename);
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
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //读取缓冲区

    if((fp = fopen(filename,"r")) == NULL)                  //判断文件是否存在及可读
    {
        printf("打开'%s'文件失败!", filename);
        return -1;
    }

    i = 0;
    while (1)                                               //循环读取每一行，直到文件尾
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //将fp所指向的文件一行内容读到strLine缓冲区
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //清除换行符
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

    fclose(fp);                                             //关闭文件

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
    printf("\n\n需要特殊处理的国家名称数量：%d\n", k);

    return 0;
}
