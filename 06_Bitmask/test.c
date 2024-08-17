#include <stdio.h>
#include <stdint.h>

#define BITWISE_NOT(input) (~(input))
#define BITWISE_AND(input) ((input) & 1)
#define BITWISE_OR(input) ((input) | 1)
#define BITWISE_SHIFT_LEFT(input) ((input) << 1)
#define BITWISE_SHIFT_RIGHT(input) ((input) >> 1)

uint32_t bitwiseNOT(uint32_t input) {
    return ~input;
}

uint32_t bitwiseAND(uint32_t input) {
    return input & 1;
}

uint32_t bitwiseOR(uint32_t input) {
    return input | 1;
}

uint32_t bitwiseShiftLeft(uint32_t input) {
    return input << 1;
}

uint32_t bitwiseShiftRight(uint32_t input) {
    return input >> 1;
}

int main() {
    uint32_t input = 0xABCD;
    // use function
    printf("\n************* Use Function **************\n");
    printf("NOT: 0x%X\n", bitwiseNOT(input));
    printf("AND: 0x%X\n", bitwiseAND(input));
    printf("OR: 0x%X\n", bitwiseOR(input));
    printf("SHIFT LEFT: 0x%X\n", bitwiseShiftLeft(input));
    printf("SHIFT RIGHT: 0x%X\n", bitwiseShiftRight(input));

    // use macro
    printf("\n************* Use Macro **************\n");
    printf("NOT: 0x%X\n", BITWISE_NOT(input));
    printf("AND: 0x%X\n", BITWISE_AND(input));
    printf("OR: 0x%X\n", BITWISE_OR(input));
    printf("SHIFT LEFT: 0x%X\n", BITWISE_SHIFT_LEFT(input));
    printf("SHIFT RIGHT: 0x%X\n", BITWISE_SHIFT_RIGHT(input));
    return 0;
}
