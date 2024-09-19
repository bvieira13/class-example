
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "main.h"

#define CONST 3 
//#define TEST

void println(const char* format, ...){
    va_list args;
    va_start(args, format);
    const char *p = format;

    while (*p != '\0') {
        if (*p == '%' && *(p + 1) != '\0') {
            p++;
            if (*p == 'd') { // Handle integer
                int i = va_arg(args, int);
                printf("%d", i);
            } else if (*p == 's') { // Handle string
                char* s = va_arg(args, char*);
                printf("%s", s);
            } else {
                putchar('%');
                putchar(*p);
            }
        } else {
            putchar(*p); // Print regular characters
        }
        p++;
    }

    va_end(args);
    putchar('\n'); // Automatically adds a newline
}

void main(void){
    char value = 0;
#ifdef TEST
    prebuild_directive();
    multiply(2);
    repeat_char('A');
#else
    variable_type();
    logical_and_bitwise();
#endif
    return;
}

void prebuild_directive(void){
    println("-------- Prebuild directives --------");
    println("Value using define: %d", CONST*3);
    println("Value direct data: %d", 15*3);
    println("-------- End Prebuild directives --------");
    println("");
    return;
}

void multiply(uint16_t num){
    println("-------- Multiply --------");
    println("Power value: %d", num*CONST);
    println("-------- End multiply --------");
    println("");
    return;
}

void repeat_char(char letter){
    println("-------- Repeat character --------");
    for (uint8_t i = 0; i < CONST; i++){
        printf("%c", letter);
    }
    printf("\n");
    println("-------- End repeat character --------");
    println("");
    return;
}

void variable_type(void){
    println("-------- Variable types --------");
    printf("UINT8 data: %d\n", UINT8_MAX);
    printf("UINT16 data: %d\n", UINT16_MAX);
    printf("UINT32 data: %u\n", UINT32_MAX);
    printf("UINT64 data: %llu\n", UINT64_MAX);
    printf("INT8 data max: %d\tINT8 data min: %d\n", INT8_MAX, INT8_MIN);
    printf("INT16 data max: %d\tINT16 data min: %d\n", INT16_MAX, INT16_MIN);
    printf("INT32 data max: %ld\tINT32 data min: %ld\n", INT32_MAX, INT32_MIN);
    printf("INT64 data max: %lld\tINT64 data min: %lld\n", INT64_MAX, INT64_MIN);
    float float_data =  pow(8.235896,3);
    double double_data = pow(8.2358961475512,3);
    printf("Data float: %.10f\tData double: %.10lf\n", float_data, double_data);
    println("-------- End variable types --------");
}

void logical_and_bitwise(void){
    println("-------- Logical expression and bitwise --------");
    char A = 8;
    char B = 5;
    char r = 0;
    
    printf("NOT - Logical: 0x%x\tBitwise: 0x%x\n",!A, (~A & 0xff));
    printf("AND - Logical: 0x%x\tBitwise: 0x%x\n",A && B, A & B);
    printf("OR - Logical: 0x%x\tBitwise: 0x%x\n",A || B, A | B);
    A = 9;
    printf("XOR - Bitwise: 0x%x\n", A ^ B);

    uint8_t before = 0xb9;
    uint8_t after;
    int8_t before_sig = 0xb9;

    after = before << 1;
    printf("Left Shif UNSIG: 0x%x\n", after);
    after = before_sig >> 1;
    printf("Right Shif SIG: 0x%x\n", after);
    after = before >> 1;
    printf("Right Shif UNSIG: 0x%x\n", after);
    
    uint8_t bit = 2;
    uint8_t arg = 0xb9;
    uint8_t mask = 1 << bit;
    arg |= mask;
    printf("Bit set: 0x%x\n", arg);
    arg &= ~mask;
    printf("Bit clear: 0x%x\n", arg);
    arg ^= mask;
    printf("Bit toggle: 0x%x\n", arg);
    arg ^= mask;
    printf("Bit toggle: 0x%x\n", arg);
    if(arg & mask){
        printf("Bit %d is one\n", bit);
    } else {
       printf("Bit %d is zero\n", bit); 
    }
    println("-------- End logical expression and bitwise --------");
}