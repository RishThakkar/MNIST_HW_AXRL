#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define IMAGE_HEIGHT 42
#define IMAGE_WIDTH 42

float* add_weights(int num_weights);
float* add_biases(int num_biases);

void read_image(float image[IMAGE_HEIGHT][IMAGE_WIDTH]);

void conv(float image[IMAGE_HEIGHT][IMAGE_WIDTH] , float *weights, float output[IMAGE_HEIGHT-1][IMAGE_WIDTH-1]);

// void basic_ques(int num_parameters, int num_weights, int num_biases);


#endif
