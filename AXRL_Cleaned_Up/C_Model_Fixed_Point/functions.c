#include "functions.h"



void printArray(float *arr, int size) 
{
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%.2f", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

// Function to print a number in binary
void print_binary_16(int16_t num) 
{
    for (int i = 15; i >= 0; i--) 
    {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}
void print_binary_32(int32_t num) 
{
    for (int i = 31; i >= 0; i--) 
    {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}
void print_binary_8(int8_t num) 
{
    for (int i = 7; i >= 0; i--) 
    {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

void print_array_binary_8(int8_t arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        print_binary_8(arr[i]);
    }
}


void printFeatureMaps(float *arr, int height, int width, int channels) 
{
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


void saveFeatureMaps(float *arr, int height, int width, int channels, const char *filename) 
{
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
                fprintf(file, "%0.6f", arr[index]);
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


void print_binary_8_to_file(FILE *file, int8_t num) {
    for (int i = 7; i >= 0; i--) {
        fprintf(file, "%c", (num & (1 << i)) ? '1' : '0');
    }
}


// Function to save binary data in a 2D grid format per channel
void saveBinaryFeatureMaps(int8_t *arr, int height, int width, int channels, const char *filename) {
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
                print_binary_8_to_file(file, arr[index]);
                // fprintf(file, "\n");
                if (j != width - 1) {
                   fprintf(file, " "); // Space between binary numbers in the same row
               }
            }
           fprintf(file, "\n"); // New line at the end of each row
        }
        fprintf(file, "\n"); // Extra new line to separate channels
    }

    fclose(file);
}


int8_t clip_value(int16_t value) 
{
    if (value > 0x007F) 
    {
        return 0b01111111;  
    } else if (value < -0x0080) 
    {
        return 0b10000000;  
    }
    return (int8_t)value;
}




