#include <stdio.h>
#include <stdint.h>
#include "functions.c"

int main()
{   
    // Correctly defining binary values
    int8_t a = 0b00111000;  // 3.5 
    int8_t b = 0b01000000;  // -4
    int8_t c = 0b00000000;  // 1
    
    int16_t mul; 
    int8_t mul2;
    
    mul = a*b;
    
    print_binary_16(mul);
    mul = (mul>>4);
    print_binary_16(mul);


    print_binary_8(mul);
    mul = mul + c;
    print_binary_16(mul);
    
    mul = clip_value(mul);

    print_binary_8(mul);

    return 0;
}
