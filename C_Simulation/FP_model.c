#include <stdio.h>
#include "functions.c"


void HW_FP(int8_t *weights, int weights_address, int weights_size, int8_t *data, int data_address, int data_size,  int layer_index, int8_t *out)
{
    if (layer_index == 0)    // Convolution & ReLU
    {
        int out_index = 0;

        for (int i = 0 ; i < 4 ; i++)  
        {
            int count = 0;
            for (int j = 0 ; j < 42 * 42; j++)  //output size will be 40x40
            {
                if ((j - 42*count) / 42 == 1) count++;

                if ((((j % (42*count + 40) != 0) && (j % (42*count + 41) != 0)) || (j == 0)) && (count < 40)) 
                { 
                    int16_t mac_res = 0b0000000000000000;

                    mac_res += data[data_address + j     ] * weights[weights_address + i     ];            
                    mac_res += data[data_address + j +  1] * weights[weights_address + i +  4];        
                    mac_res += data[data_address + j +  2] * weights[weights_address + i +  8];        
                    mac_res += data[data_address + j + 42] * weights[weights_address + i + 12];       
                    mac_res += data[data_address + j + 43] * weights[weights_address + i + 16];         
                    mac_res += data[data_address + j + 44] * weights[weights_address + i + 20];
                    mac_res += data[data_address + j + 84] * weights[weights_address + i + 24];       
                    mac_res += data[data_address + j + 85] * weights[weights_address + i + 28];
                    mac_res += data[data_address + j + 86] * weights[weights_address + i + 32];

                    mac_res = (mac_res >> 4);  // Shift right by 4

                    mac_res += weights[weights_address + i + 36];   //Bias

                    mac_res = mac_res>>3;   //Divide by 8
                    // mac_res = clip_value(mac_res);  //Gives 8 bit out

                    out[out_index] = (mac_res > 0x0000) ? mac_res : 0b0000000000000000;
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
            for (int j = 0; j < 40 * 20; j += 2)
            {
                int8_t max;

                max =  data[data_address + i * 40 * 40 + (j % 40) + (j - (j % 40)) * 2     ];
                max = (data[data_address + i * 40 * 40 + (j % 40) + (j - (j % 40)) * 2 +  1] > max) ? data[data_address + i * 40 * 40 + (j % 40) + (j - (j % 40)) * 2 +  1] : max;
                max = (data[data_address + i * 40 * 40 + (j % 40) + (j - (j % 40)) * 2 + 40] > max) ? data[data_address + i * 40 * 40 + (j % 40) + (j - (j % 40)) * 2 + 40] : max;
                max = (data[data_address + i * 40 * 40 + (j % 40) + (j - (j % 40)) * 2 + 41] > max) ? data[data_address + i * 40 * 40 + (j % 40) + (j - (j % 40)) * 2 + 41] : max;

                out[out_index] = max;
                out_index++;
            }
        }
    }

    else if (layer_index == 2)       //Conv 2 and ReLU
    {
        int out_index = 0;

        for (int i = 0; i < 4; i++)
        {
            int count = 0;
            for (int j = 0; j < 20 * 20; j++)
            {
                if ((j - 20*count) / 20 == 1) count++;

                if ((((j % (20*count + 18) != 0) && (j % (20*count + 19) != 0)) || (j == 0)) && (count < 18))
                {  
                    int16_t mac_res = 0b0000000000000000;

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
                        
                        mac_res = (mac_res >> 4);  // Shift right by 4

                        mac_res += weights[weights_address + i + 144];

                    }
                    mac_res = mac_res>>3;  //Divide by 8

                    out[out_index] = (mac_res > 0x0000) ? mac_res : 0b0000000000000000;
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
            for (int j = 0; j < 18 * 9; j += 2)
            {
                int8_t max;

                max =  data[data_address + i * 18 * 18 + (j % 18) + (j - (j % 18)) * 2     ];
                max = (data[data_address + i * 18 * 18 + (j % 18) + (j - (j % 18)) * 2 +  1] > max) ? data[data_address + i * 18 * 18 + (j % 18) + (j - (j % 18)) * 2 +  1] : max;
                max = (data[data_address + i * 18 * 18 + (j % 18) + (j - (j % 18)) * 2 + 18] > max) ? data[data_address + i * 18 * 18 + (j % 18) + (j - (j % 18)) * 2 + 18] : max;
                max = (data[data_address + i * 18 * 18 + (j % 18) + (j - (j % 18)) * 2 + 19] > max) ? data[data_address + i * 18 * 18 + (j % 18) + (j - (j % 18)) * 2 + 19] : max;

                out[out_index] = max;
                out_index++;
            }
        }
    }

    else if (layer_index == 4)       // Dense Layer
    {

        for (int i = 0; i < 10; i++)
        {
            int16_t mac_res = 0b0000000000000000;

            // for (int j = 0; j < 4; j++)
            // {
                for (int k = 0; k < 9 * 9 * 4; k++)
                {
                    mac_res += data[data_address + k] * weights[weights_address + (k * 10) + i];   
                }        
            // }

            mac_res = (mac_res >> 4);  // Shift right by 4

            mac_res += weights[weights_address + 3240 + i];

            mac_res = mac_res >> 3;

            out[i] = (mac_res > 0x0000) ? mac_res : 0b0000000000000000;
    
        }
    }
}

int main()
{    
    HW_FP(binary_weights_bias2, 0, 40, binary_image_4, 0, 1764, 0, conv1out_FP);
    HW_FP(binary_weights_bias2, 0, 0, conv1out_FP, 0, 0, 1, max1out_real_FP);
    HW_FP(binary_weights_bias2, 40, 148, max1out_real_FP, 0, 1600, 2, conv2out_FP);
    HW_FP(binary_weights_bias2, 0, 0, conv2out_FP, 0, 0, 3, max2out_real_FP);
    HW_FP(binary_weights_bias2, 188, 0, max2out_real_FP, 0, 0, 4, dense_out_FP);

    saveBinaryFeatureMaps(conv1out_FP, 40, 40, 4, "Binary_C_conv1_out.txt");    
    saveBinaryFeatureMaps(max1out_real_FP, 20, 20, 4, "Binary_C_max1_out.txt");    
    saveBinaryFeatureMaps(conv2out_FP, 18, 18, 4, "Binary_C_conv2_out.txt");    
    saveBinaryFeatureMaps(max2out_real_FP, 9, 9, 4, "Binary_C_max2_out.txt"); 
    saveBinaryFeatureMaps(dense_out_FP, 10, 1, 1, "Binary_C_dense_out.txt"); 

    return 0;
}