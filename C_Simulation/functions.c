#include "functions.h"

////   Weights addition function            ///////////////////////////////////////////////////////////////////
float* add_weights(int num_weights)
{
    float *weight = (float *)malloc(num_weights * sizeof(float));
    for(int i = 0;i < num_weights;i++)
    {
        printf("Enter weight %d: \n", i + 1);
        scanf("%f", &weight[i]);
    }
    return weight;
}
/////    Biases addition function       ////////////////////////////////////////////////////////////////////////////////////////////////////

float* add_biases(int num_biases) 
{
    float *bias = (float *)malloc(num_biases * sizeof(float));
    for(int i = 0; i < num_biases; i++) 
    {
        printf("Enter bias %d: \n", i + 1);
        scanf("%f", &bias[i]);
    }
    return bias;
}

/////    basic questions about weights and bias function            //////////////////////////////////////////////////////////////
void basic_ques(int num_parameters, int num_weights, int num_biases)
{
    printf("How many trainable parameters do you have: ");
    scanf("%d", &num_parameters);
    printf("Number of parameters entered: %d\n", num_parameters);


    printf("How many weights do you have: ");
    scanf("%d", &num_weights);
    printf("Number of weights entered: %d\n", num_weights);


    printf("How many biases do you have: ");
    scanf("%d", &num_biases);
    if(num_biases + num_weights != num_parameters)
    {
        printf("Please enter correct number of weights or biases");
    }
    else
    {printf("Number of biases entered: %d\n", num_biases);}

}


///////    Read Image function          ////////////////////////////////////////////////////////////////
////     Right now it is generating image not reading           ////////////////////////////////
void read_image(float image[IMAGE_HEIGHT][IMAGE_WIDTH])
{
    srand(time(NULL));

    for (int i = 0;i < IMAGE_HEIGHT;i++) 
    {
        for (int j = 0;j < IMAGE_WIDTH;j++)
        {
            image[i][j] = (float)rand() / RAND_MAX;
        }
    }
    printf("Image generated \n");
}

//image is 42 x 42 so multiply 0th pixel with 0th address and 42nd pixel with 42nd address location
//////////////////////////////Conv Block//////////////////////////////////////////////////////////
void conv(float image[IMAGE_HEIGHT][IMAGE_WIDTH] , float *weights, float output[IMAGE_HEIGHT-2][IMAGE_WIDTH-2])
{

    for(int i=0;i<IMAGE_HEIGHT;i++)
    {
        for(int j =0;j<IMAGE_WIDTH;j++)
        {
            float mac_res = 0.0;

            mac_res += image[i][j] * weights[0];            
            mac_res += image[i][j+1] * weights[1];        
            mac_res += image[i][j+2] * weights[2];        
            mac_res += image[i+1][j] * weights[3];       
            mac_res += image[i+1][j+1] * weights[4];         
            mac_res += image[i+1][j+2] * weights[5];
            mac_res += image[i+2][j] * weights[6];       
            mac_res += image[i+2][j+1] * weights[7];
            mac_res += image[i+2][j+2] * weights[8];

            output[i][j] = mac_res;
        }
    }
    printf("Convolution done\n");

    // printf("Convolution Output:\n");
    printf("Conv output Size: %dx%d\n", IMAGE_HEIGHT-2, IMAGE_WIDTH - 2); 

    // for (int i=0; i<IMAGE_HEIGHT-2; i++) 
    // {
    //     for (int j=0; j<IMAGE_WIDTH - 2; j++) 
    //     {
    //         printf("%2.6f\t", output[i][j]); 
    //     }
    //     printf("\n");
    // }
}



////////////////////////// ReLU ///////////////////////////////////

void relu(float input[IMAGE_HEIGHT-2][IMAGE_WIDTH-2], float output[IMAGE_HEIGHT-2][IMAGE_WIDTH-2]) 
{
    for (int i=0; i<IMAGE_HEIGHT-2; i++) 
    {
        for (int j=0; j<IMAGE_WIDTH-2; j++) 
        {
            output[i][j] = input[i][j] > 0 ? input[i][j] : 0; // ReLU 
        }
    }

    printf("ReLU Done\n");
    // printf("ReLU output \n");
    printf("ReLU output Size: %dx%d\n", IMAGE_HEIGHT-2, IMAGE_WIDTH-2); 
    // for(int i=0;i<IMAGE_HEIGHT-2;i++)
    // {
    //     for (int j=0;j<IMAGE_WIDTH-2;j++)
    //     {
    //         printf("%2.6f\t", output[i][j]);
    //     }
    // }
    // printf("\n");
}

/////  Max Pooling   //////////////////////////////////////////


void max_pool(float input[IMAGE_HEIGHT-2][IMAGE_WIDTH-2], float output[(IMAGE_HEIGHT-2)/2][(IMAGE_WIDTH-2)/2])
{
    for (int i=0; i<IMAGE_HEIGHT-2;i++)
    {
        for (int j=0;j<IMAGE_WIDTH-2;j++)
        {
            float max = input[i][j];
            max = (input[i][j+1] > max)? input[i][j+1] : max;
            max = (input[i+1][j] > max)? input[i+1][j] : max;
            max = (input[i+1][j+1] > max)? input[i+1][j+1] : max;

            output[i][j] = max;
        }
    }

    printf("Max Pool Done\n");
    // printf("Max Pool output \n");
    // printf("Max Pool output Size: %dx%d\n", (IMAGE_HEIGHT-2)/2, (IMAGE_WIDTH-2)/2); 
    // for(int i=0;i<(IMAGE_HEIGHT-2)/2;i++)
    // {
    //     for (int j=0;j<(IMAGE_WIDTH-2)/2;j++)
    //     {
    //         printf("%2.6f\t", output[i][j]);
    //     }
    // }
    // printf("\n");

}

//////////////////   HARDWARE MODULE    ///////////////////////////////



void printArray(float *arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%.2f", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void printFeatureMaps(float *arr, int height, int width, int channels) {
    for (int c = 0; c < channels; ++c) {
        printf("Channel %d:\n", c + 1);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int index = c * height * width + i * width + j;
                printf("%f", arr[index]);
                if (j != width - 1) {
                    printf(", ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}




void saveFeatureMaps(float *arr, int height, int width, int channels, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int c = 0; c < channels; ++c) {
        fprintf(file, "Channel %d:\n", c + 1);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int index = c * height * width + i * width + j;
                fprintf(file, "%0.2f", arr[index]);
                if (j != width - 1) {
                    fprintf(file, ", ");
                }
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

