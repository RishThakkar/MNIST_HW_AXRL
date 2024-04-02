#include "functions.h"

////////////////////////////////////////////////////////Weights addition function/////////////////////////////////////////////////
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
////////////////////////////////////////////////////////Biases addition function/////////////////////////////////////////////////

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

////////////////////////////////////////////////////////basic questions about weights and bias function/////////////////////////////////////////////////
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


////////////////////////////////////////////////////////Read Image function/////////////////////////////////////////////////
////Right now it is generating image not reading////////////////////////////////
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

//image is 42 x 42 so multiply 0th pixel with 1st address and 42nd pixel with 43rd address location
//////////////////////////////Conv Block//////////////////////////////////////////////////////////
void conv(float image[IMAGE_HEIGHT][IMAGE_WIDTH] , float *weights, float output[IMAGE_HEIGHT-1][IMAGE_WIDTH-1])
{

    for(int i=0;i<IMAGE_HEIGHT;i++)
    {
        for(int j =0;j<IMAGE_WIDTH;j++)
        {
            float mac_res = 0.0;

            mac_res += image[i][j] * weights[0];
            mac_res += image[i][j+1] * weights[1];
            mac_res += image[i+1][j] * weights[2];
            mac_res += image[i+1][j+1] * weights[3];

            output[i][j] = mac_res;
        }
    }
}

