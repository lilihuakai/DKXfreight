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
    if (!strcmp(country[country_id], "美国"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "美国本土外小岛屿") != NULL ||
                    strstr(country_area[i], "UM") != NULL))
                num--;
        }
    }

    if (!strcmp(country[country_id], "苏丹"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "南苏丹共和国") != NULL ||
                    strstr(country_area[i], "SS") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "西班牙"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "北非西班牙属土") != NULL ||
                    strstr(country_area[i], "XG") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "索马里"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "索马里共和国") != NULL ||
                    strstr(country_area[i], "XS") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "俄罗斯"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "白俄罗斯(独联体)") != NULL ||
                    strstr(country_area[i], "BY") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "荷兰"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "库拉索岛(荷兰)") != NULL ||
                    strstr(country_area[i], "XC") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "马里"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "索马里共和国") != NULL ||
                    strstr(country_area[i], "XS") != NULL ||
                    strstr(country_area[i], "索马里") != NULL ||
                    strstr(country_area[i], "SO") != NULL ||
                    strstr(country_area[i], "北马里亚纳群岛") != NULL ||
                    strstr(country_area[i], "MP") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "印度"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "英属印度洋地区(查各群岛)") != NULL ||
                    strstr(country_area[i], "IO") != NULL ||
                    strstr(country_area[i], "印度尼西亚") != NULL ||
                    strstr(country_area[i], "ID") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "圭亚那"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "法属圭亚那") != NULL ||
                    strstr(country_area[i], "GF") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "几内亚"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "赤道几内亚") != NULL ||
                    strstr(country_area[i], "GQ") != NULL ||
                    strstr(country_area[i], "巴布亚新几内亚") != NULL ||
                    strstr(country_area[i], "PG") != NULL ||
                    strstr(country_area[i], "几内亚比绍") != NULL ||
                    strstr(country_area[i], "GW") != NULL))
                num--;
        }
    }
    if (!strcmp(country[country_id], "刚果"))
    {
        for (i = 0; i < row_area; i++)
        {
            if (!strcmp(code_area[i], code_area[area_id]) && 
                (strstr(country_area[i], "刚果民主共和国") != NULL ||
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
            printf("警告：'%s'分区方案,'%s'分区中的'%s'为空！\n", name_area[i], area_area[i], head_country_area);
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
                printf("基础数据中不存在此国家'%s' %d %s\n", tmp, i, country_area[i]);
                return -1;
            }
            k = is_repeat(area_id, country_id);
            if (k > 1)
            {
                printf("'%s'分区方案中'%s'的出现次数是：%d\n", name_area[area_id], country[country_id], k);
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
