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

                    // mac_res = (mac_res >> 4);  // Shift right by 4
                    mac_res += weights[weights_address + i + 36] << 4;   //Bias

                    mac_res = mac_res>>7;  


                    out[out_index] = (mac_res > 0x0000) ? mac_res : 0b0000000000000000;

                    // if (out_index == 408) 
                    // {
                    //     FILE *file = fopen("test.txt", "w");

                    //     print_binary_8_to_file(file,data[data_address + j     ]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i     ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j     +1]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i   +4  ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j     +2]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i   +8  ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j  +42   ]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i   +12  ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j   +43  ]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i +16    ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j   +44  ]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i +20    ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j    +84 ]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i +24    ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j   +85  ]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i +28     ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,data[data_address + j  +86   ]);
                    //     fprintf(file, "\n");
                    //     print_binary_8_to_file(file,weights[weights_address + i  +32    ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file,weights[weights_address + i  +36    ]);
                    //     fprintf(file, "\n");
                    //     fprintf(file, "\n");

                    //     print_binary_8_to_file(file, out[out_index]);
                    // }
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
                        
                        // mac_res = (mac_res >> 4);  // Shift right by 4
                        // mac_res = mac_res>>3;  //Divide by 8

                    }
                    mac_res += weights[weights_address + i + 144] << 4;
                    mac_res = mac_res>>7;  //Divide by 8
                    // mac_res = clip_value(mac_res);  //Gives 8 bit out

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

            // mac_res = (mac_res >> 4);  // Shift right by 4
            mac_res += weights[weights_address + 3240 + i] << 4;

            mac_res = mac_res >> 7;
            // mac_res = clip_value(mac_res);  //Gives 8 bit out

            out[i] = (mac_res > 0x0000) ? mac_res : 0b0000000000000000;
    
        }
    }
}

int main()
{    

        // HW_FP(binary_weights_bias_FP, 0, 40, images[1], 0, 1764, 0, conv1out_FP);
        // HW_FP(binary_weights_bias_FP, 0, 0, conv1out_FP, 0, 0, 1, max1out_real_FP);
        // HW_FP(binary_weights_bias_FP, 40, 148, max1out_real_FP, 0, 1600, 2, conv2out_FP);
        // HW_FP(binary_weights_bias_FP, 0, 0, conv2out_FP, 0, 0, 3, max2out_real_FP);
        // HW_FP(binary_weights_bias_FP, 188, 0, max2out_real_FP, 0, 0, 4, dense_out_FP);

        // saveBinaryFeatureMaps(conv1out_FP, 40, 40, 4, "Binary_C_conv1_out.txt");    
        // saveBinaryFeatureMaps(max1out_real_FP, 20, 20, 4, "Binary_C_max1_out.txt");    
        // saveBinaryFeatureMaps(conv2out_FP, 18, 18, 4, "Binary_C_conv2_out.txt");    
        // saveBinaryFeatureMaps(max2out_real_FP, 9, 9, 4, "Binary_C_max2_out.txt"); 
        // saveBinaryFeatureMaps(dense_out_FP, 10, 1, 1, "Binary_C_dense_out.txt"); 

    int correct_count = 0;
    int label;
    int predicted_label;
    char buffer[100000];
    int max_value, value;
    FILE *label_file, *output_file;
    
    label_file = fopen("mnist_labels.txt", "r");
    if (label_file == NULL) {
        perror("Failed to open label file");
        return 1;
    }


    for (int i = 0; i < 1; i++)
    {
        HW_FP(binary_weights_bias_FP_scaled, 0, 40, images[i], 0, 1764, 0, conv1out_FP);
        HW_FP(binary_weights_bias_FP_scaled, 0, 0, conv1out_FP, 0, 0, 1, max1out_real_FP);
        HW_FP(binary_weights_bias_FP_scaled, 40, 148, max1out_real_FP, 0, 1600, 2, conv2out_FP);
        HW_FP(binary_weights_bias_FP_scaled, 0, 0, conv2out_FP, 0, 0, 3, max2out_real_FP);
        HW_FP(binary_weights_bias_FP_scaled, 188, 0, max2out_real_FP, 0, 0, 4, dense_out_FP);

        saveBinaryFeatureMaps(conv1out_FP, 40, 40, 4, "Binary_C_conv1_out.txt");    
        saveBinaryFeatureMaps(max1out_real_FP, 20, 20, 4, "Binary_C_max1_out.txt");    
        saveBinaryFeatureMaps(conv2out_FP, 18, 18, 4, "Binary_C_conv2_out.txt");    
        saveBinaryFeatureMaps(max2out_real_FP, 9, 9, 4, "Binary_C_max2_out.txt"); 
        saveBinaryFeatureMaps(dense_out_FP, 10, 1, 1, "Binary_C_dense_out.txt"); 

        output_file = fopen("Binary_C_dense_out.txt", "r");
        if (output_file == NULL) {
            perror("Failed to open output file");
            continue;
        }

        max_value = -1;
        predicted_label = -1;
        for (int j = -1; fgets(buffer, sizeof(buffer), output_file) != NULL; j++) {
            sscanf(buffer, "%d", &value); // Assuming the value can be read directly
            if (value > max_value) {
                max_value = value;
                predicted_label = j;
            }
        }
        fclose(output_file);

        // Read the correct label from mnist_labels.txt
        if (fscanf(label_file, "%d", &label) != 1) {
            perror("Failed to read label");
            break;
        }

        // Compare and update correct count
        if (label == predicted_label) {
            correct_count++;
        }

        printf("Actual Label %d \n", label);
        printf("Predicted Label %d \n\n", predicted_label);
    }

    fclose(label_file);

    printf("Accuracy: %f%%\n", (double)correct_count/1.0);

    return 0;
}