#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 2048                         //文件读取时，每行最大字节数
#define MAX_NUM_STRING 50                                   //字符串长度
#define MAX_NUM_STRINGS 1600                                //超长字符串长度
#define MAX_NUM_DOUBLE_STRING 16                            //数字字符串长度
#define IF_WRITE_CSV 0                                      //是否输出测试数据到文件
#define IF_CHECK_INPUT 0                                    //是否输出输入的数据

#define MAX_NUM_COUNTRY 300                                 //“国家”最大数
#define MAX_NUM_AREA 1500                                   //“分区方案”最大数


int row_country;                                            //“国家”表
char country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_country[MAX_NUM_STRING];
char code_country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_code_country[MAX_NUM_STRING];

int row_area;                                               //“分区方案”表
char name_area[MAX_NUM_AREA][MAX_NUM_STRING], head_name_area[MAX_NUM_STRING];
char code_area[MAX_NUM_AREA][MAX_NUM_STRING], head_code_area[MAX_NUM_STRING];
char area_area[MAX_NUM_AREA][MAX_NUM_STRING], head_area_area[MAX_NUM_STRING];
char country_area[MAX_NUM_AREA][MAX_NUM_STRINGS], head_country_area[MAX_NUM_STRING];

char two_code[MAX_NUM_AREA][MAX_NUM_STRINGS];
char chinese_name[MAX_NUM_AREA][MAX_NUM_STRINGS];

//读取文件
int read_file()
{
    FILE *fp;
    int i;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //读取缓冲区

    /*
    获取国家
    */
    if((fp = fopen("国家副本.csv","r")) == NULL)                  //判断文件是否存在及可读
    {
        printf("打开'国家副本.csv'文件失败!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //循环读取每一行，直到文件尾
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //将fp所指向的文件一行内容读到strLine缓冲区
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //清除换行符
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
            printf("警告：“国家”表最大行数已超过限制\n");
    }
    row_country = i - 1;
    fclose(fp);                                             //关闭文件
    if (IF_WRITE_CSV == 1)
        printf("读取'国家副本.csv'文件成功!\n");

    /*
    获取分区方案
    */
    if((fp = fopen("分区方案副本.csv","r")) == NULL)                  //判断文件是否存在及可读
    {
        printf("打开'分区方案副本.csv'文件失败!\n");
        return -1;
    }
    i = 0;
    while (1)                                               //循环读取每一行，直到文件尾
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //将fp所指向的文件一行内容读到strLine缓冲区
        if(feof(fp))break;
        if (strlen(strTemp) >= MAX_NUM_STRINGS)
            printf("警告：此行数据已超过最大限制！长度为：%d\n", strlen(strTemp));
        strTemp[strlen(strTemp) - 1] = '\0';                //清除换行符
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
            printf("警告：“分区方案”表最大行数已超过限制\n");
    }
    row_area = i - 1;
    fclose(fp);                                             //关闭文件
    if (IF_WRITE_CSV == 1)
        printf("读取'分区方案副本.csv'文件成功!\n");

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
            printf("警告：'%s'分区方案,'%s'分区中的'%s'为空！\n", name_area[i], area_area[i], head_country_area);
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
                printf("基础数据中不存在此国家'%s' %d %s\n", tmp, i, country_area[i]);
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

    if((fp = fopen("分区方案副本_二位码.csv","w")) == NULL)                  //判断文件是否存在及可写
    {
        printf("打开'分区方案副本_二位码.csv'文件失败!\n");
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

    if((fp = fopen("分区方案副本_中文名.csv","w")) == NULL)                  //判断文件是否存在及可写
    {
        printf("打开'分区方案副本_中文名.csv'文件失败!\n");
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
