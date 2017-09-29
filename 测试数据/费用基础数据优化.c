#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 2048                         //文件读取时，每行最大字节数
#define MAX_NUM_STRING 50                                   //字符串长度
#define MAX_NUM_STRINGS 1600                                //超长字符串长度
#define MAX_NUM_DOUBLE_STRING 16                            //数字字符串长度
#define IF_WRITE_CSV 0                                      //是否输出测试数据到文件

#define MAX_NUM_COST 10000                                  //“物流费用”最大数
#define MAX_NUM_COST_OTHER 10000                            //“物流杂费”最大数


int row_cost;                                               //“物流费用”表
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

int row_cost_other;                                         //“物流杂费”表
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

//读取文件
int read_file()
{
    FILE *fp;
    int i;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //读取缓冲区

    /*
    获取物流费用
    */
    if((fp = fopen("物流费用副本.csv","r")) == NULL)                  //判断文件是否存在及可读
    {
        printf("打开'物流费用副本.csv'文件失败!\n");
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
            printf("警告：“物流费用”表最大行数已超过限制\n");
    }
    row_cost = i - 1;
    fclose(fp);                                             //关闭文件
    if (IF_WRITE_CSV == 1)
        printf("读取'物流费用副本.csv'文件成功!\n");

    /*
    获取物流杂费
    */
    if((fp = fopen("物流杂费副本.csv","r")) == NULL)                  //判断文件是否存在及可读
    {
        printf("打开'物流杂费副本.csv'文件失败!\n");
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
            printf("警告：“物流杂费”表最大行数已超过限制\n");
    }
    row_cost_other = i - 1;
    fclose(fp);                                             //关闭文件
    if (IF_WRITE_CSV == 1)
        printf("读取'物流杂费副本.csv'文件成功!\n");

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

    printf("价格判断参数有误！\n");
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
    for (i = 0; i < row_cost; i++)                                                      //将价格相等的邻近区段结合
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

    for (i = 0; i < row_cost_other; i++)                                                //将价格相等的邻近区段结合
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

    if((fp = fopen("物流费用副本_优化版.csv","w")) == NULL)                  //判断文件是否存在及可写
    {
        printf("打开'物流费用副本_优化版.csv'文件失败!\n");
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

    if((fp = fopen("物流杂费副本_优化版.csv","w")) == NULL)                  //判断文件是否存在及可写
    {
        printf("打开'物流杂费副本_优化版.csv'文件失败!\n");
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
