#include <stdio.h>
#include "functions.c"
#include <time.h>

void HW(float *weights, int weights_address, int weights_size, float *data, int data_address, int data_size,  int layer_index, float *out)
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
            for (int j = 0; j < 40 * 20; j += 2)
            {
                float max;

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


                    }

                    mac_res += weights[weights_address + i + 144];

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
            for (int j = 0; j < 18 * 9; j += 2)
            {
                float max;

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
            float mac_res = 0.0;
           
                for (int k = 0; k < 9 * 9 * 4; k++)
                {
                    mac_res += data[data_address + k] * weights[weights_address + (k * 10) + i];   
                }        

            mac_res += weights[weights_address + 3240 + i];

            out[i] = (mac_res > 0) ? mac_res : 0;
    
        }
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    // HW(float *weights, int weights_address, int weights_size, float *data, int data_address, int data_size,  int layer_index, float *out)
    HW(weights_bias_FP_scaled, 0, 40, image_real, 0, 1764, 0 , conv1out);
    HW(weights_bias_FP_scaled, 0, 0, conv1out, 0, 0, 1 , max1out_real);
    HW(weights_bias_FP_scaled, 40, 148, max1out_real, 0, 1600, 2, conv2out);
    HW(weights_bias_FP_scaled, 0, 0, conv2out, 0, 0, 3 , max2out_real);
    HW(weights_bias_FP_scaled, 188, 0, max2out_real, 0, 0, 4, dense_out);
    
    saveFeatureMaps(conv1out, 40, 40, 4, "C_program_out_conv1.txt");
    saveFeatureMaps(max1out_real, 20, 20, 4, "C_program_out_max1.txt");
    saveFeatureMaps(conv2out, 18, 18, 4, "C_program_out_conv2.txt");
    saveFeatureMaps(max2out_real, 9, 9, 4, "C_program_out_max2.txt");
    saveFeatureMaps(dense_out, 10, 1, 1, "C_program_out_dense.txt");

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for running one inference: %f seconds\n", cpu_time_used);
    
    // int correct_count = 0;
    // int label;
    // int predicted_label;
    // char buffer[100000];
    // int max_value, value;
    // FILE *label_file, *output_file;
    
    // label_file = fopen("mnist_labels.txt", "r");
    // if (label_file == NULL) {
    //     perror("Failed to open label file");
    //     return 1;
    // }


    // for (int i = 0; i < 10000; i++)
    // {
    //     HW(weights_bias_FP_scaled, 0, 40, fl_images[i], 0, 1764, 0 , conv1out);
    //     HW(weights_bias_FP_scaled, 0, 0, conv1out, 0, 0, 1 , max1out_real);
    //     HW(weights_bias_FP_scaled, 40, 148, max1out_real, 0, 1600, 2, conv2out);
    //     HW(weights_bias_FP_scaled, 0, 0, conv2out, 0, 0, 3 , max2out_real);
    //     HW(weights_bias_FP_scaled, 188, 0, max2out_real, 0, 0, 4, dense_out);
        
    //     saveFeatureMaps(conv1out, 40, 40, 4, "C_program_out_conv1.txt");
    //     saveFeatureMaps(max1out_real, 20, 20, 4, "C_program_out_max1.txt");
    //     saveFeatureMaps(conv2out, 18, 18, 4, "C_program_out_conv2.txt");
    //     saveFeatureMaps(max2out_real, 9, 9, 4, "C_program_out_max2.txt");
    //     saveFeatureMaps(dense_out, 10, 1, 1, "C_program_out_dense.txt");

    //     output_file = fopen("C_program_out_dense.txt", "r");
    //     if (output_file == NULL) {
    //         perror("Failed to open output file");
    //         continue;
    //     }

    //     max_value = -1;
    //     predicted_label = -1;
    //     for (int j = -1; fgets(buffer, sizeof(buffer), output_file) != NULL; j++) {
    //         sscanf(buffer, "%d", &value); // Assuming the value can be read directly
    //         if (value > max_value) {
    //             max_value = value;
    //             predicted_label = j;
    //         }
    //     }
    //     fclose(output_file);

    //     // Read the correct label from mnist_labels.txt
    //     if (fscanf(label_file, "%d", &label) != 1) {
    //         perror("Failed to read label");
    //         break;
    //     }

    //     // Compare and update correct count
    //     if (label == predicted_label) {
    //         correct_count++;
    //     }

    //     printf("Actual label %d \n", label);
    //     printf("Predicted Label %d \n\n", predicted_label);
    // }

    // fclose(label_file);

    // printf("Accuracy: %f%%\n", (double)correct_count/10000.0);

    return 0;
}