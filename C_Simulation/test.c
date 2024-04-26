#include <stdio.h>
#include <stdint.h>

// Function to print a number in binary
void print_binary(int16_t num) {
    for (int i = 15; i >= 0; i--) {
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
    int8_t a[2] = {0b00100000, 0b00000000}; // 
    int8_t b[2] = {0b00111011, 0b00110000}; //
    
    int16_t mul ; // Multiplication result stored in a 16-bit integer
    int8_t mul2;
    
    for(int i=0; i<2 ;i++)
    {
        int16_t mul = 0b0000000000000000; 
        mul += a[i]*b[i];
        mul  = mul >>5;
    }
    mul2 = mul;
    // printf("Decimal: %d\n", mul);
    // printf("Binary: ");
    print_array_binary_8(a, 2);
    print_binary(mul);
    mul2 = (mul>>5);
    print_binary_8(mul2);
    return 0;
}
