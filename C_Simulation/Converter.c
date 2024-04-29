#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "functions.h"

void converter(float num)
{
    // if(num >= -4)
    // {
        int int_part = (int) num;
        // printf("Integer Part = %d ", int_part);

        float frac_part = num - int_part;

        frac_part = fabs(frac_part);

        if((num < 0 && num > -1) || (num < -1 && num > -2) || (num < -2 && num > -3) || (num < -3 && num > -4) || (num < -4 && num > -5) || (num < -5 && num > -6) || (num < -7 && num > -8))
            frac_part = 1 - frac_part;
            

        // printf("Frac_part = %f\n", frac_part);
        printf("0b");   //C format for binary
        
        if(num < 0)
        {
            printf("1");
            num = num + 8;
            if(num >= 4)
            {
                printf("1");
                num = num - 4;
            }
            else
                printf("0");
            
            if(num >= 2)
            {
                printf("1");
                num = num - 2;
            }
            else    
                printf("0");
            
            if(num >= 1)
            {
                printf("1");
                num = num - 1;
            }
            else    
                printf("0");
        }

        else if(num >= 0)
        {
            printf("0");

            if(num >= 4)
            {
                printf("1");
                num = num - 4;
            }
            else    
                printf("0");

            if(num >= 2)
            {
                printf("1");
                num = num - 2;
            }
            else
                printf("0");
            
            if(num >= 1)
            {
                printf("1");
                num = num - 1;
            }
            else    
                printf("0");
        }

        if(frac_part >= 0.5)
        {
            printf("1");
            frac_part = frac_part - 0.5;
        }   
        else    
            printf("0");
        
        if(frac_part >= 0.25)
        {
            printf("1");
            frac_part = frac_part - 0.25;
        }
        else    
            printf("0");

        if(frac_part >= 0.125)
        {
            printf("1");
            frac_part = frac_part - 0.125;
        }
        else    
            printf("0");

        if(frac_part >= 0.0625)
        {
            printf("1");
            frac_part = frac_part - 0.0625;
        }
        else    
            printf("0");
 
    // }
}


void weightarray(float arr[], int len) 
{
   FILE *file = fopen("binary_weights_new.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }

    freopen("binary_weights_new.txt", "w", stdout);

    for (int i = 0; i < len; i++) 
    {
        // printf("Converting %f: ", arr[i]);
        converter(arr[i]);
        printf("\n");
    }

    freopen("/dev/tty", "w", stdout);
    fclose(file); 
}

void imagearray(float arr[], int len) 
{
   FILE *file = fopen("binary_image.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }

    freopen("binary_image.txt", "w", stdout);

    for (int i = 0; i < len; i++) 
    {
        // printf("Converting %f: ", arr[i]);
        converter(arr[i]);
        printf("\n");
    }

    freopen("/dev/tty", "w", stdout);
    fclose(file); 
}

// void converter(float num)
// {
//     // if(num >= -4)
//     // {
//         int int_part = (int) num;
//         // printf("Integer Part = %d ", int_part);

//         float frac_part = num - int_part;

//         frac_part = fabs(frac_part);

//         if((num < 0 && num > -1) || (num < -1 && num > -2) || (num < -2 && num > -3) || (num < -3 && num > -4) || (num < -4 && num > -5) || (num < -5 && num > -6) || (num < -7 && num > -8))
//             frac_part = 1 - frac_part;
            

//         // printf("Frac_part = %f\n", frac_part);
//         printf("0b");   //C format for binary
        
//         if(num < 0)
//         {
//             printf("1");
//             num = num + 4;
//             if(num >= 2)
//             {
//                 printf("1");
//                 num = num - 2;
//             }
//             else
//                 printf("0");
            
//             if(num >= 1)
//             {
//                 printf("1");
//                 num = num - 1;
//             }
//             else    
//                 printf("0");
//         }

//         else if(num >= 0)
//         {
//             printf("0");

//             if(num >= 2)
//             {
//                 printf("1");
//                 num = num - 2;
//             }
//             else    
//                 printf("0");

//             if(num >= 1)
//             {
//                 printf("1");
//                 num = num - 1;
//             }
//             else
//                 printf("0");
//         }

//         if(frac_part >= 0.5)
//         {
//             printf("1");
//             frac_part = frac_part - 0.5;
//         }   
//         else    
//             printf("0");
        
//         if(frac_part >= 0.25)
//         {
//             printf("1");
//             frac_part = frac_part - 0.25;
//         }
//         else    
//             printf("0");

//         if(frac_part >= 0.125)
//         {
//             printf("1");
//             frac_part = frac_part - 0.125;
//         }
//         else    
//             printf("0");

//         if(frac_part >= 0.0625)
//         {
//             printf("1");
//             frac_part = frac_part - 0.0625;
//         }
//         else    
//             printf("0");

//         if(frac_part >= 0.03125)
//         {
//             printf("1");
//             frac_part = frac_part - 0.03125;
//         }
//         else    
//             printf("0");
 
//     // }
// }


// void weightarray(float arr[], int len) 
// {
//    FILE *file = fopen("binary_weights.txt", "w");
//     if (file == NULL) 
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     freopen("binary_weights.txt", "w", stdout);

//     for (int i = 0; i < len; i++) 
//     {
//         // printf("Converting %f: ", arr[i]);
//         converter(arr[i]);
//         printf("\n");
//     }

//     freopen("/dev/tty", "w", stdout);
//     fclose(file); 
// }

// void imagearray(float arr[], int len) 
// {
//    FILE *file = fopen("binary_image.txt", "w");
//     if (file == NULL) 
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     freopen("binary_image.txt", "w", stdout);

//     for (int i = 0; i < len; i++) 
//     {
//         // printf("Converting %f: ", arr[i]);
//         converter(arr[i]);
//         printf("\n");
//     }

//     freopen("/dev/tty", "w", stdout);
//     fclose(file); 
// }


int main()
{
    converter(2.53);
    printf("\n");
    converter(1.66113);
    printf("\n");

    converter(-4);
    printf("\n");
    converter(-3);
    printf("\n");
    converter(-2);
    printf("\n");
    converter(-1);
    printf("\n");
    converter(0);
    printf("\n");
    converter(1);
    printf("\n");
    converter(2);
    printf("\n");
    converter(3);
    printf("\n");
    printf("\n");

    converter(0.5);
    printf("\n");
    converter(-0.5);
    printf("\n");
    converter(-1.5);
    printf("\n");
    converter(-0.125);
    printf("\n");
    converter(-1.25);
    printf("\n");
    converter(-0.25);
    printf("\n");
    converter(-1.25);
    printf("\n");
    converter(-2.25);
    printf("\n");
    converter(-3.25);
    printf("\n");
    printf("\n");

    converter(1.8748094);
    printf("\n");
    converter(-1.8748094);
    printf("\n");

    printf("Below values are from actual weights\n");
    converter(0.14475057);
    printf("\n");
    converter(-0.21379876);
    printf("\n");
    converter(0.2594401);
    printf("\n");
    converter(-3.3419926);
    printf("\n");
    converter(0.8656526);
    printf("\n");
    converter(2.022736);
    printf("\n");
    
    // int len = sizeof(weights_bias) / sizeof(weights_bias[0]);
    // weightarray(weights_bias, len);

    int imglen = sizeof(image) / sizeof(image[0]);
    imagearray(image, imglen);

    int len = sizeof(weights_bias2) / sizeof(weights_bias2[0]);
    weightarray(weights_bias2, len);

    return 0;
}