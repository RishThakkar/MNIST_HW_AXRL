#include <stdio.h>
#include <functions.c>

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

                    mac_res += image[data_address + j     ] * weights[weights_address + i     ];            
                    mac_res += image[data_address + j +  1] * weights[weights_address + i +  4];        
                    mac_res += image[data_address + j +  2] * weights[weights_address + i +  8];        
                    mac_res += image[data_address + j + 42] * weights[weights_address + i + 12];       
                    mac_res += image[data_address + j + 43] * weights[weights_address + i + 16];         
                    mac_res += image[data_address + j + 44] * weights[weights_address + i + 20];
                    mac_res += image[data_address + j + 84] * weights[weights_address + i + 24];       
                    mac_res += image[data_address + j + 85] * weights[weights_address + i + 28];
                    mac_res += image[data_address + j + 86] * weights[weights_address + i + 32];

                    mac_res += weights[weights_address + i + 36];

                    out[out_index + i * 42 * 42] = (mac_res > 0) ? mac_res : 0;
                    out_index++;
                }
            } 
        }
    }

    else if (layer_index == 1)       // Max Pool 1
    {   
        for (int i = 0; i < 4; i++)          //Now here the image is the out of the previous layer
        {
            for (int j = 0; j < data_size ; j += 2)
            {
                float max;

                max =  data[data_address + j + (j / 40 + 1) * 40     ];
                max = (data[data_address + j + (j / 40 + 1) * 40 +  1] > max) ? data[data_address + j + (j / 40 + 1) * 40 +  1 +  1] : max;
                max = (data[data_address + j + (j / 40 + 1) * 40 + 40] > max) ? data[data_address + j + (j / 40 + 1) * 40 +  1 + 40] : max;
                max = (data[data_address + j + (j / 40 + 1) * 40 + 41] > max) ? data[data_address + j + (j / 40 + 1) * 40 +  1 + 41] : max;

                out[(j+i)*data_size] = max;
            }
        }
    }

    else if (layer_index == 2)       //Conv 2 and ReLU
    {
        for (int i = 0; i < 4; i++)
        {
            for (int k = 0; k < 4; k++) 
            {
                float mac_res = 0.0;

                for (int j = 0; j < 18 * 18; j++)
                {
                    
                    mac_res += image[data_address + j      + k * 18 * 18] * weights[weights_address + i     ];            
                    mac_res += image[data_address + j +  1 + k * 18 * 18] * weights[weights_address + i +  4];        
                    mac_res += image[data_address + j +  2 + k * 18 * 18] * weights[weights_address + i +  8];        
                    mac_res += image[data_address + j + 18 + k * 18 * 18] * weights[weights_address + i + 12];       
                    mac_res += image[data_address + j + 19 + k * 18 * 18] * weights[weights_address + i + 16];         
                    mac_res += image[data_address + j + 20 + k * 18 * 18] * weights[weights_address + i + 20];
                    mac_res += image[data_address + j + 36 + k * 18 * 18] * weights[weights_address + i + 24];       
                    mac_res += image[data_address + j + 37 + k * 18 * 18] * weights[weights_address + i + 28];
                    mac_res += image[data_address + j + 38 + k * 18 * 18] * weights[weights_address + i + 32];

                    mac_res += weights[weights_address + i + 36];

                    out[j + i * data_size] = (mac_res > 0) ? mac_res : 0;
                }
            }
        }
    }
}

int main()
{
    read_image(image);
    return 0;
}