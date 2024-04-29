#include <stdio.h>
#include <stdint.h>

// Function to print a number in binary
void print_binary_16(int16_t num) {
    for (int i = 15; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}
void print_binary_32(int32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}
void print_binary_8(int8_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

void print_array_binary_8(int8_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        print_binary_8(arr[i]);
    }
}


int main()
{   
    // Correctly defining binary values
    int8_t a = 0b00111000;  // 3.5 
    int8_t b = 0b11110000;  // 
    // int8_t c = 0b01111111;  // 
    
    int32_t mul ; // Multiplication result stored in a 16-bit integer
    int8_t mul2;
    
    mul = a*b;
    
    print_binary_16(mul);
    // print_binary_32(a);
    // print_binary_32(b);
    // mul = mul ^ 0b11111111111111111111111111111111;
    // print_binary_32(mul);
    mul2 = (mul>>4);
    print_binary_8(mul2);
    return 0;
}
