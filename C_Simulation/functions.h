#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define IMAGE_HEIGHT 42
#define IMAGE_WIDTH  42

int current_height = IMAGE_HEIGHT;
int current_width = IMAGE_WIDTH;



float* add_weights(int num_weights);
float* add_biases(int num_biases);

void read_image(float image[IMAGE_HEIGHT][IMAGE_WIDTH]);

void conv(float image[IMAGE_HEIGHT][IMAGE_WIDTH] , float *weights, float output[IMAGE_HEIGHT-2][IMAGE_WIDTH-2]);


void relu(float input[IMAGE_HEIGHT-2][IMAGE_WIDTH-2], float output[IMAGE_HEIGHT-2][IMAGE_WIDTH-2]);

void max_pool(float input[IMAGE_HEIGHT-2][IMAGE_WIDTH-2], float output[(IMAGE_HEIGHT-2)/2][(IMAGE_WIDTH-2)/2]);

// void conv(float, float *, float);
// void basic_ques(int num_parameters, int num_weights, int num_biases);


#endif
