#include "functions.h"

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

