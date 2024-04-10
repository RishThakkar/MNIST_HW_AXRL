#include <stdio.h>
#include "functions.c"


void HW(float *weights, int weights_address, int weights_size, float *data, int data_address, int data_size,  int layer_index, float *out)
{
    if (layer_index == 0)    // Convolution & ReLU
    {
        int out_index = 0;

        for (int i = 0 ; i < 4 ; i++)  
        {
            for (int j = 0 ; j < 42 * 42; j++)  //output size will be 40x40
            {
                if ((j % 40 != 0) && (j % 41 != 0))
                { 
                    float mac_res = 0.0;

                    mac_res += data[data_address + j     ] * weights[weights_address + i     ];            
                    mac_res += data[data_address + j +  1] * weights[weights_address + i +  4];        
                    mac_res += data[data_address + j +  2] * weights[weights_address + i +  8];        
                    mac_res += data[data_address + j + 42] * weights[weights_address + i + 12];       
                    mac_res += data[data_address + j + 43] * weights[weights_address + i + 16];         
                    mac_res += data[data_address + j + 44] * weights[weights_address + i + 20];
                    mac_res += data[data_address + j + 84] * weights[weights_address + i + 24];       
                    mac_res += data[data_address + j + 85] * weights[weights_address + i + 28];
                    mac_res += data[data_address + j + 86] * weights[weights_address + i + 32];

                    mac_res += weights[weights_address + i + 36];

                    out[out_index] = (mac_res > 0) ? mac_res : 0;
                    out_index++;
                }
            } 
        }
    }

    else if (layer_index == 1)       // Max Pool 1
    {   
        int out_index = 0;

        for (int i = 0; i < 4; i++)          //Now here the image is the out of the previous layer
        {
            for (int j = 0; j < 40 * 38; j += 2)
            {
                float max;

                max =  data[data_address + (j % 40) + (j / 40 + 1) * 40     ];
                max = (data[data_address + (j % 40) + (j / 40 + 1) * 40 +  1] > max) ? data[data_address + (j % 40) + (j / 40 + 1) * 40 +  1 +  1] : max;
                max = (data[data_address + (j % 40) + (j / 40 + 1) * 40 + 40] > max) ? data[data_address + (j % 40) + (j / 40 + 1) * 40 +  1 + 40] : max;
                max = (data[data_address + (j % 40) + (j / 40 + 1) * 40 + 41] > max) ? data[data_address + (j % 40) + (j / 40 + 1) * 40 +  1 + 41] : max;

                out[out_index + i * 20 * 20] = max;
                out_index++;
            }
        }
    }

    else if (layer_index == 2)       //Conv 2 and ReLU
    {
        int out_index = 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 20 * 20; j++)
            {
                if ((j % 18 != 0) && (j % 19 != 0))
                {  
                    float mac_res = 0.0;

                    for (int k = 0; k < 4; k++) 
                    {

                        mac_res += data[data_address + j      + k * 20 * 20] * weights[weights_address + i + (k * 4)      ];            
                        mac_res += data[data_address + j +  1 + k * 20 * 20] * weights[weights_address + i + (k * 4) +  16];        
                        mac_res += data[data_address + j +  2 + k * 20 * 20] * weights[weights_address + i + (k * 4) +  32];        
                        mac_res += data[data_address + j + 20 + k * 20 * 20] * weights[weights_address + i + (k * 4) +  48];       
                        mac_res += data[data_address + j + 21 + k * 20 * 20] * weights[weights_address + i + (k * 4) +  64];         
                        mac_res += data[data_address + j + 22 + k * 20 * 20] * weights[weights_address + i + (k * 4) +  80];
                        mac_res += data[data_address + j + 40 + k * 20 * 20] * weights[weights_address + i + (k * 4) +  96];       
                        mac_res += data[data_address + j + 41 + k * 20 * 20] * weights[weights_address + i + (k * 4) + 112];
                        mac_res += data[data_address + j + 42 + k * 20 * 20] * weights[weights_address + i + (k * 4) + 128];

                        mac_res += weights[weights_address + i + 144];

                    }

                    out[out_index] = (mac_res > 0) ? mac_res : 0;
                    out_index++;
                }
            }
        }
    }

    else if (layer_index == 3)       // Max Pool 2
    {   
        int out_index = 0;

        for (int i = 0; i < 4; i++)          //Now here the image is the out of the previous layer
        {
            for (int j = 0; j < 18 * 18; j += 2)
            {
                float max;

                max =  data[data_address + (j % 18) + (j / 18 + 1) * 18     ];
                max = (data[data_address + (j % 18) + (j / 18 + 1) * 18 +  1] > max) ? data[data_address + (j % 18) + (j / 18 + 1) * 18 +  1 +  1] : max;
                max = (data[data_address + (j % 18) + (j / 18 + 1) * 18 + 18] > max) ? data[data_address + (j % 18) + (j / 18 + 1) * 18 +  1 + 18] : max;
                max = (data[data_address + (j % 18) + (j / 18 + 1) * 18 + 19] > max) ? data[data_address + (j % 18) + (j / 18 + 1) * 18 +  1 + 19] : max;

                out[out_index + i * 9 * 9] = max;
                out_index++;
            }
        }
    }

    else if (layer_index == 4)       // Dense Layer
    {

        for (int i = 0; i < 10; i++)
        {
            float mac_res = 0.0;

            for (int j = 0; j < 4; j++)
            {

                for (int k = 0; k < 9 * 9; k++){

                    mac_res += data[data_address + k + (j * 9 * 9)] * weights[weights_address + (k + (j * 9 * 9)) * 10 + i];   

                }

                         
            }

            mac_res += weights[weights_address + i ];

            out[i] = (mac_res > 0) ? mac_res : 0;
    
        }
    }
}

int main()
{
    HW(weights_bias, 0, 40, image, 0, 1764, 0 , out);
    printFeatureMaps(out, 40, 40 , 4);
    saveFeatureMaps(out, 40, 40, 4, "C_program_out_conv.txt");

    return 0;
}