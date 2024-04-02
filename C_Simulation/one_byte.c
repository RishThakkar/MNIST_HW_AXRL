#include <stdio.h>
#include <stdlib.h>

typedef unsigned char fixed_point_t;

#define INT_BITS 2
#define FRAC_BITS 6

#define FIXED_POINT_MAX ((1 << (INT_BITS + FRAC_BITS - 1)) - 1)
#define FIXED_POINT_MIN (-(1 << (INT_BITS + FRAC_BITS - 1)))

fixed_point_t float_to_fixed(float value) {
    int scaled_value = value * (1 << FRAC_BITS);
    if (scaled_value > FIXED_POINT_MAX) {
        return FIXED_POINT_MAX;
    } else if (scaled_value < FIXED_POINT_MIN) {
        return FIXED_POINT_MIN;
    } else {
        return (fixed_point_t)scaled_value;
    }
}

float fixed_to_float(fixed_point_t value) {
    return (float)value / (1 << FRAC_BITS);
}

int main() {
    float input_float = 3.14;
    printf("Input float: %f\n", input_float);

    fixed_point_t fixed_value = float_to_fixed(input_float);
    printf("Fixed-point value: %d\n", fixed_value);

    float output_float = fixed_to_float(fixed_value);
    printf("Output float: %f\n", output_float);

    return 0;
}
