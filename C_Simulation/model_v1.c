#include <stdio.h>

#include "functions.c"



int main()
{
    int num_parameters;
    int num_weights;
    int num_biases;

    float image[IMAGE_HEIGHT][IMAGE_WIDTH];
    float conv_out[IMAGE_HEIGHT-2][IMAGE_WIDTH-2];

while(1)
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
        printf("Please enter correct number of weights or biases \n");
    }
    else
    {
        break;
    }
}
    printf("Number of biases entered: %d\n", num_biases);

    float *weights = add_weights(num_weights);
    float *biases = add_biases(num_biases);

    // printf("Weights and Biases Stored in Memory \n");

    printf("\nWeights:\n");
    for (int i = 0; i < num_weights; i++) {
        printf("%f ", weights[i]);
    }

    printf("\nStarting address for weights : %p\n", (void *)&(weights[0]));


    printf("\nBiases:\n");
    for (int i = 0; i < num_biases; i++) {
        printf("%f ", biases[i]);
    }

    printf("\nStarting address for biases: %p\n", (void *)&(biases[0]));

    //image generating
    srand(time(NULL));
    read_image(image);

//////////////////////////////   Convolution of the image with weights    ///////////////////////

    conv(image, weights, conv_out);


//last step- free the memory
    free(weights);
    free(biases);

    return 0;
}