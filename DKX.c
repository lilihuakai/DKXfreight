#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_READ_FILE_LINE 1024                         //ÎÄ¼ş¶ÁÈ¡Ê±£¬Ã¿ĞĞ×î´ó×Ö½ÚÊı
#define MAX_NUM_ROW 300                                     //Êı¾İĞĞµÄ×î´óÊıÁ¿
#define MAX_NUM_COLUMN 10                                   //Êı¾İÁĞµÄ×î´óÊıÁ¿
#define MAX_NUM_STRING 30                                   //×Ö·û´®³¤¶È
#define MAX_NUM_INT 8                                       //Êı×Ö³¤¶È
#define IF_WRITE_CSV 0                                      //ÊÇ·ñÊä³ö²âÊÔÊı¾İµ½ÎÄ¼ş

#define MAX_NUM_WAREHOUSE 50                                //¡°²Ö¿â¡±×î´óÊı
#define MAX_NUM_COUNTRY 300                                 //¡°¹ú¼Ò¡±×î´óÊı
#define MAX_NUM_TRANS 300                                   //¡°ÔËÊä·½Ê½¡±×î´óÊı
#define MAX_NUM_AREA 300                                    //¡°·ÖÇø·½°¸¡±×î´óÊı
#define MAX_NUM_AREA_COUNT 500                              //¡°·ÖÇø·½°¸-¹ú¼Ò¡±×î´óÊı
#define MAX_NUM_COST 300                                    //¡°ÎïÁ÷·ÑÓÃ¡±×î´óÊı
#define MAX_NUM_ADDRESS 300                                 //¡°¼Æ·ÑµØµã¡±×î´óÊı
#define MAX_NUM_COST_OTHER 300                              //¡°ÎïÁ÷ÔÓ·Ñ¡±×î´óÊı

#define MAX_NUM_RESULT 300                                  //¡°Êä³ö½á¹û¡±×î´óÊı


int row_warehouse;                                          //¡°²Ö¿â¡±±í
char warehouse[MAX_NUM_WAREHOUSE][MAX_NUM_STRING], head_warehouse[MAX_NUM_STRING];

int row_country;                                            //¡°¹ú¼Ò¡±±í
char country[MAX_NUM_COUNTRY][MAX_NUM_STRING], head_country[MAX_NUM_STRING];

int row_transport;                                          //¡°ÔËÊä·½Ê½¡±±í
char code_trans[MAX_NUM_TRANS][MAX_NUM_STRING], head_code_trans[MAX_NUM_STRING];
char name_trans[MAX_NUM_TRANS][MAX_NUM_STRING], head_name_trans[MAX_NUM_STRING];
char ware_trans[MAX_NUM_TRANS][MAX_NUM_STRING], head_ware_trans[MAX_NUM_STRING];

int row_area;                                               //¡°·ÖÇø·½°¸¡±±í
char name_area[MAX_NUM_AREA][MAX_NUM_STRING], head_name_area[MAX_NUM_STRING];
char code_area[MAX_NUM_AREA][MAX_NUM_STRING], head_code_area[MAX_NUM_STRING];
char area_area[MAX_NUM_AREA][MAX_NUM_INT], head_area_area[MAX_NUM_STRING];
char country_area[MAX_NUM_AREA][MAX_NUM_AREA_COUNT], head_country_area[MAX_NUM_STRING];

int row_cost;                                               //¡°ÎïÁ÷·ÑÓÃ¡±±í
char name_cost[MAX_NUM_COST][MAX_NUM_STRING], head_name_cost[MAX_NUM_STRING];
char area_cost[MAX_NUM_COST][MAX_NUM_INT], head_area_cost[MAX_NUM_STRING];
char type_cost[MAX_NUM_COST][MAX_NUM_STRING], head_type_cost[MAX_NUM_STRING];
char weight_start_cost[MAX_NUM_COST][MAX_NUM_INT], head_weight_start_cost[MAX_NUM_STRING];
char weight_end_cost[MAX_NUM_COST][MAX_NUM_INT], head_weight_end_cost[MAX_NUM_STRING];
char weight_average_cost[MAX_NUM_COST][MAX_NUM_INT], head_weight_average_cost[MAX_NUM_STRING];
char price_cost[MAX_NUM_COST][MAX_NUM_INT], head_price_cost[MAX_NUM_STRING];
char discount_cost[MAX_NUM_COST][MAX_NUM_INT], head_discount_cost[MAX_NUM_STRING];
double weight_start_cost_lf[MAX_NUM_COST];
double weight_end_cost_lf[MAX_NUM_COST];
double weight_average_cost_lf[MAX_NUM_COST];
double price_cost_lf[MAX_NUM_COST];
double discount_cost_lf[MAX_NUM_COST];

int row_address;                                            //¡°¼Æ·ÑµØµã¡±±í
char name_address[MAX_NUM_ADDRESS][MAX_NUM_STRING], head_name_address[MAX_NUM_STRING];
char ware_address[MAX_NUM_ADDRESS][MAX_NUM_STRING], head_ware_address[MAX_NUM_STRING];

int row_cost_other;                                         //¡°ÎïÁ÷ÔÓ·Ñ¡±±í
char name_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_STRING], head_name_cost_other[MAX_NUM_STRING];
char area_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_INT], head_area_cost_other[MAX_NUM_STRING];
char type_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_STRING], head_type_cost_other[MAX_NUM_STRING];
char weight_start_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_INT], head_weight_start_cost_other[MAX_NUM_STRING];
char weight_end_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_INT], head_weight_end_cost_other[MAX_NUM_STRING];
char price_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_INT], head_price_cost_other[MAX_NUM_STRING];
char discount_cost_other[MAX_NUM_COST_OTHER][MAX_NUM_INT], head_discount_cost_other[MAX_NUM_STRING];
double weight_start_cost_other_lf[MAX_NUM_COST_OTHER];
double weight_end_cost_other_lf[MAX_NUM_COST_OTHER];
double price_cost_other_lf[MAX_NUM_COST_OTHER];
double discount_cost_other_lf[MAX_NUM_COST_OTHER];


<<<<<<< HEAD
int warehose_input,num_result;                              //ÓÃ»§²Ù×÷
char country_input[30];
double sum[MAX_NUM_RESULT];
=======
int warehouse_input_id, country_input_id, num_result;                                //ÓÃ»§²Ù×÷
char name_area_id_result[MAX_NUM_RESULT];                                           //·ÖÇø·½°¸Ãû³Æ
char name_trans_id_result[MAX_NUM_RESULT];                                          //ÔËÊä·½Ê½Ãû³Æ
char code_trans_id_result[MAX_NUM_RESULT];
char area_area_id_result[MAX_NUM_RESULT];
double weight_input;
double price_cost_lf_result[MAX_NUM_RESULT];
double price_cost_other_lf_result[MAX_NUM_RESULT];
double sum_result[MAX_NUM_RESULT];

>>>>>>> 1.ä¿®æ”¹äº†æ‚è´¹è®¡ç®—é”™è¯¯çš„é—®é¢˜;2.æ·»åŠ äº†æ‚è´¹çš„è®¡è´¹åœ°ç‚¹çš„éªŒè¯;3.ä¿®æ”¹äº†åç§°é”™è¯¯çš„é—®é¢˜

//¶ÁÈ¡ÎÄ¼ş
int read_file()
{
    int i;
    char filename[MAX_NUM_STRING];
    char strline[MAX_NUM_ROW][MAX_NUM_COLUMN][MAX_NUM_STRING];

    strcpy(filename, "./»ù´¡Êı¾İ/²Ö¿â.csv");
    if (read_csv(filename, &row_warehouse, 1, strline))
    {
        printf("¶ÁÈ¡'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }
    strcpy(head_warehouse, strline[0][0]);
    for (i = 0; i < row_warehouse; i++)
    {
        strcpy(warehouse[i], strline[i + 1][0]);
    }

    strcpy(filename, "./»ù´¡Êı¾İ/¹ú¼Ò.csv");
    if (read_csv(filename, &row_country, 1, strline))
    {
        printf("¶ÁÈ¡'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }
    strcpy(head_country, strline[0][0]);
    for (i = 0; i < row_country; i++)
    {
        strcpy(country[i], strline[i + 1][0]);
    }

    strcpy(filename, "./»ù´¡Êı¾İ/ÔËÊä·½Ê½.csv");
    if (read_csv(filename, &row_transport, 3, strline))
    {
        printf("¶ÁÈ¡'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }
    strcpy(head_code_trans, strline[0][0]);
    strcpy(head_name_trans, strline[0][1]);
    strcpy(head_ware_trans, strline[0][2]);
    for (i = 0; i < row_transport; i++)
    {
        strcpy(code_trans[i], strline[i + 1][0]);
        strcpy(name_trans[i], strline[i + 1][1]);
        strcpy(ware_trans[i], strline[i + 1][2]);
    }

    strcpy(filename, "./»ù´¡Êı¾İ/·ÖÇø·½°¸.csv");
    if (read_csv(filename, &row_area, 4, strline))
    {
        printf("¶ÁÈ¡'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }
    strcpy(head_name_area, strline[0][0]);
    strcpy(head_code_area, strline[0][1]);
    strcpy(head_area_area, strline[0][2]);
    strcpy(head_country_area, strline[0][3]);
    for (i = 0; i < row_area; i++)
    {
        strcpy(name_area[i], strline[i + 1][0]);
        strcpy(code_area[i], strline[i + 1][1]);
        strcpy(area_area[i], strline[i + 1][2]);
        strcpy(country_area[i], strline[i + 1][3]);
    }

    strcpy(filename, "./»ù´¡Êı¾İ/ÎïÁ÷·ÑÓÃ.csv");
    if (read_csv(filename, &row_cost, 8, strline))
    {
        printf("¶ÁÈ¡'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }
    strcpy(head_name_cost, strline[0][0]);
    strcpy(head_area_cost, strline[0][1]);
    strcpy(head_type_cost, strline[0][2]);
    strcpy(head_weight_start_cost, strline[0][3]);
    strcpy(head_weight_end_cost, strline[0][4]);
    strcpy(head_weight_average_cost, strline[0][5]);
    strcpy(head_price_cost, strline[0][6]);
    strcpy(head_discount_cost, strline[0][7]);
    for (i = 0; i < row_cost; i++)
    {
        strcpy(name_cost[i], strline[i + 1][0]);
        strcpy(area_cost[i], strline[i + 1][1]);
        strcpy(type_cost[i], strline[i + 1][2]);
        strcpy(weight_start_cost[i], strline[i + 1][3]);
        strcpy(weight_end_cost[i], strline[i + 1][4]);
        strcpy(weight_average_cost[i], strline[i + 1][5]);
        strcpy(price_cost[i], strline[i + 1][6]);
        strcpy(discount_cost[i], strline[i + 1][7]);
    }

    strcpy(filename, "./»ù´¡Êı¾İ/¼Æ·ÑµØµã.csv");
    if (read_csv(filename, &row_address, 2, strline))
    {
        printf("¶ÁÈ¡'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }
    strcpy(head_name_address, strline[0][0]);
    strcpy(head_ware_address, strline[0][1]);
    for (i = 0; i < row_address; i++)
    {
        strcpy(name_address[i], strline[i + 1][0]);
        strcpy(ware_address[i], strline[i + 1][1]);
    }

    strcpy(filename, "./»ù´¡Êı¾İ/ÎïÁ÷ÔÓ·Ñ.csv");
    if (read_csv(filename, &row_cost_other, 7, strline))
    {
        printf("¶ÁÈ¡'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }
    strcpy(head_name_cost_other, strline[0][0]);
    strcpy(head_area_cost_other, strline[0][1]);
    strcpy(head_type_cost_other, strline[0][2]);
    strcpy(head_weight_start_cost_other, strline[0][3]);
    strcpy(head_weight_end_cost_other, strline[0][4]);
    strcpy(head_price_cost_other, strline[0][5]);
    strcpy(head_discount_cost_other, strline[0][6]);
    for (i = 0; i < row_cost_other; i++)
    {
        strcpy(name_cost_other[i], strline[i + 1][0]);
        strcpy(area_cost_other[i], strline[i + 1][1]);
        strcpy(type_cost_other[i], strline[i + 1][2]);
        strcpy(weight_start_cost_other[i], strline[i + 1][3]);
        strcpy(weight_end_cost_other[i], strline[i + 1][4]);
        strcpy(price_cost_other[i], strline[i + 1][5]);
        strcpy(discount_cost_other[i], strline[i + 1][6]);
    }

    if (check_file())                                        //¼ì²â¶ÁÈ¡Êı¾İÊÇ·ñÕıÈ·
        return -1;

    return 0;
}

int read_csv(char *filename, int *row, int column, char strline[MAX_NUM_ROW][MAX_NUM_COLUMN][MAX_NUM_STRING])
{
    FILE *fp;
    int i, j;
    char strTemp[MAX_NUM_READ_FILE_LINE];                   //¶ÁÈ¡»º³åÇø

    if((fp = fopen(filename,"r")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿É¶Á
    {
        printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
        return -1;
    }

    i = 0;
    while (1)                                               //Ñ­»·¶ÁÈ¡Ã¿Ò»ĞĞ£¬Ö±µ½ÎÄ¼şÎ²
    {
        fgets(strTemp,MAX_NUM_READ_FILE_LINE,fp);           //½«fpËùÖ¸ÏòµÄÎÄ¼şÒ»ĞĞÄÚÈİ¶Áµ½strLine»º³åÇø
        if(feof(fp))break;
        strTemp[strlen(strTemp) - 1] = '\0';                //Çå³ı»»ĞĞ·û
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

    fclose(fp);                                             //¹Ø±ÕÎÄ¼ş

    return 0;
}

//µ¼³öÊı¾İµ½ÎÄ±¾£¬·½±ã¼ì²â
int check_file()
{
    if (IF_WRITE_CSV == 0)return 0;
    if (write_csv("²Ö¿â¸±±¾.csv", row_warehouse))
        return -1;

    if (write_csv("¹ú¼Ò¸±±¾.csv", row_country))
        return -1;

    if (write_csv("ÔËÊä·½Ê½¸±±¾.csv", row_transport))
        return -1;

    if (write_csv("·ÖÇø·½°¸¸±±¾.csv", row_area))
        return -1;

    if (write_csv("ÎïÁ÷·ÑÓÃ¸±±¾.csv", row_cost))
        return -1;

    if (write_csv("¼Æ·ÑµØµã¸±±¾.csv", row_address))
        return -1;

    if (write_csv("ÎïÁ÷ÔÓ·Ñ¸±±¾.csv", row_cost_other))
        return -1;
    return 0;
}

int write_csv(char *filename, int row)
{
    FILE *fp;
    int i;

    if(!strcmp(filename, "²Ö¿â¸±±¾.csv"))
    {
        if((fp = fopen("./²âÊÔÊı¾İ/²Ö¿â¸±±¾.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
        {
            printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
            return -1;
        }

        fprintf(fp, "%s\n", head_warehouse);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s\n", warehouse[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "¹ú¼Ò¸±±¾.csv"))
    {
        if((fp = fopen("./²âÊÔÊı¾İ/¹ú¼Ò¸±±¾.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
        {
            printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
            return -1;
        }

        fprintf(fp, "%s\n", head_country);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s\n", country[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "ÔËÊä·½Ê½¸±±¾.csv"))
    {
        if((fp = fopen("./²âÊÔÊı¾İ/ÔËÊä·½Ê½¸±±¾.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
        {
            printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
            return -1;
        }

        fprintf(fp, "%s,%s,%s\n", head_code_trans, head_name_trans, head_ware_trans);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s,%s\n", code_trans[i], name_trans[i], ware_trans[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "·ÖÇø·½°¸¸±±¾.csv"))
    {
        if((fp = fopen("./²âÊÔÊı¾İ/·ÖÇø·½°¸¸±±¾.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
        {
            printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
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

    if(!strcmp(filename, "ÎïÁ÷·ÑÓÃ¸±±¾.csv"))
    {
        if((fp = fopen("./²âÊÔÊı¾İ/ÎïÁ÷·ÑÓÃ¸±±¾.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
        {
            printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
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

    if(!strcmp(filename, "¼Æ·ÑµØµã¸±±¾.csv"))
    {
        if((fp = fopen("./²âÊÔÊı¾İ/¼Æ·ÑµØµã¸±±¾.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
        {
            printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
            return -1;
        }

        fprintf(fp, "%s,%s\n", head_name_address, head_ware_address);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s\n", name_address[i], ware_address[i]);

        fclose(fp);
    }

    if(!strcmp(filename, "ÎïÁ÷ÔÓ·Ñ¸±±¾.csv"))
    {
        if((fp = fopen("./²âÊÔÊı¾İ/ÎïÁ÷ÔÓ·Ñ¸±±¾.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
        {
            printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", filename);
            return -1;
        }

        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s\n", 
            head_name_cost_other, 
            head_area_cost_other, 
            head_type_cost_other, 
            head_weight_start_cost_other, 
            head_weight_end_cost_other, 
            head_price_cost_other, 
            head_discount_cost_other);
        for(i = 0; i < row; i++)
            fprintf(fp, "%s,%s,%s,%s,%s,%s,%s\n", 
                name_cost_other[i], 
                area_cost_other[i], 
                type_cost_other[i], 
                weight_start_cost_other[i], 
                weight_end_cost_other[i], 
                price_cost_other[i], 
                discount_cost_other[i]);

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
        printf("ÏÖÓĞ²Ö¿âÈçÏÂ£º\n\n");
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
        printf("ÇëÊäÈë²Ö¿â¼òÂë»ò²Ö¿âÃû³Æ£¨Ö§³ÖÄ£ºıÊäÈë£©£º");
        gets(tmp);
        j = 0;
        for (i = 0; i < row_warehouse; i++)
            if (strstr(warehouse[i], tmp) != NULL)
            {
                j++;
                warehouse_input_id = i;
            }
        if (j == 0)
            printf("²»´æÔÚ´Ë²Ö¿â£¬ÇëÖØĞÂÊäÈë£¡\n\n\n");
        if (j > 1)
            printf("ÊäÈëÄÚÈİ¹ıÉÙ£¬ÇëÖØĞÂÊäÈë£¡\n\n\n");
        if (j == 1)
        {
            printf("ÄãÑ¡ÔñµÄ²Ö¿âÊÇ'%s'\n\n\n", warehouse[warehouse_input_id]);
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
        printf("ÇëÊäÈë¹ú¼ÒÃû³Æ£¨Ö§³ÖÄ£ºıÊäÈë£©£º");
        gets(tmp);
        j = 0;
        if (!strcmp(tmp, "ÃÀ¹ú") ||                                                   //ÌØÊâ´¦Àí£¬ÓÃÓÚÄ£ºıËÑË÷
            !strcmp(tmp, "ËÕµ¤") || 
            !strcmp(tmp, "Î÷°àÑÀ") || 
            !strcmp(tmp, "Ë÷ÂíÀï") || 
            !strcmp(tmp, "¶íÂŞË¹") || 
            !strcmp(tmp, "ºÉÀ¼") || 
            !strcmp(tmp, "ÂíÀï") || 
            !strcmp(tmp, "Ó¡¶È") || 
            !strcmp(tmp, "¹çÑÇÄÇ") || 
            !strcmp(tmp, "¼¸ÄÚÑÇ") || 
            !strcmp(tmp, "¸Õ¹û"))
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
                printf("²»´æÔÚ´Ë¹ú¼Ò£¬ÇëÖØĞÂÊäÈë£¡\n\n");
            if (j > 1)
                printf("ÊäÈëÄÚÈİ¹ıÉÙ£¬ÇëÖØĞÂÊäÈë£¡\n\n");
        }
        if (j == 1)
            break;
    }
    printf("ÄãÊäÈëµÄ¹ú¼ÒÊÇ'%s'\n\n\n", country[country_input_id]);

    return 0;
}

int get_input_weight()
{
    char tmp[MAX_NUM_STRING];

    while (1)
    {
        printf("ÇëÊäÈëÖØÁ¿£º");
        gets(tmp);
        weight_input = atof(tmp);
        if (weight_input >= 0.000000 && weight_input <= 0.000001)
        {
            printf("ÊäÈëÓĞÎó£¡\n");
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

    if((fp = fopen("·ÑÓÃ.csv","w")) == NULL)                  //ÅĞ¶ÏÎÄ¼şÊÇ·ñ´æÔÚ¼°¿ÉĞ´
    {
        printf("´ò¿ª'%s'ÎÄ¼şÊ§°Ü!", "·ÑÓÃ.csv");
        return -1;
    }

    fprintf(fp, "·¢»õ²Ö£º,Ä¿µÄµØ¹ú¼Ò£º,ÖØÁ¿£º\n");
    fprintf(fp, "%s,%s,%lf\n\n", warehouse[warehouse_input_id], country[country_input_id], weight_input);
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s\n", 
        head_name_trans, 
        head_code_trans, 
        head_area_area, 
        "ÖØÁ¿", 
        "ÔË·Ñ", 
        "ÔÓ·Ñ", 
        "×Ü·ÑÓÃ");
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
                "¸ÃÅÉËÍ·½Ê½²»Ö§³Ö¸Ã¹ú¼Ò");
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
    int i, j;

    for (i = 0; i < num_result; i++)
    {
        for (j = 0; j < row_cost; j++)
            if (!strcmp(name_cost[j], name_area[name_area_id_result[i]]) && 
                !strcmp(area_cost[j], area_area[area_area_id_result[i]]))
            {
                if (!strcmp(type_cost[j], "µ¥¼Û") && 
                    weight_input > weight_start_cost_lf[j] && 
                    weight_input <=weight_end_cost_lf[j])
                {
                    price_cost_lf_result[i] = weight_input * price_cost_lf[j] / weight_average_cost_lf[j] * discount_cost_lf[j];
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
                if (flag == 0)                                                                      //Èç¹ûÔÓ·ÑÃ»ÓĞ°ó¶¨¸Ã²Ö¿â£¬ÔòÔÓ·ÑÎª0
                    break;
                if (!strcmp(type_cost_other[j], "Æ±") && 
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

    if (get_sum())
        return -1;

    if (write_csv_result())
        return -1;

    printf("·¢»õ²Ö£º%s\n", warehouse[warehouse_input_id]);
    printf("Ä¿µÄµØ¹ú¼Ò£º%s\n", country[country_input_id]);
    printf("ÖØÁ¿£º%lf\n\n", weight_input);
    printf("%s,%s,%s,%s,%s,%s,%s\n", 
        head_name_trans, 
        head_code_trans, 
        head_area_area, 
        "ÖØÁ¿", 
        "ÔË·Ñ", 
        "ÔÓ·Ñ", 
        "×Ü·ÑÓÃ");
    for (i = 0; i < num_result; i++)
    {
        if (sum_result[i] < 99999999)
            printf("%s,%s,%s,%lf,%lf,%lf,%lf\n", 
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
                "¸ÃÅÉËÍ·½Ê½²»Ö§³Ö¸Ã¹ú¼Ò");
    }

    printf("\n");
>>>>>>> 1.ä¿®æ”¹äº†æ‚è´¹è®¡ç®—é”™è¯¯çš„é—®é¢˜;2.æ·»åŠ äº†æ‚è´¹çš„è®¡è´¹åœ°ç‚¹çš„éªŒè¯;3.ä¿®æ”¹äº†åç§°é”™è¯¯çš„é—®é¢˜

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
