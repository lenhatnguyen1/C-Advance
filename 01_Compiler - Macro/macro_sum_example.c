// macro_sum_example.c
#include <stdio.h>

#define sum(a, b) a+b

int cong(int a, int b) {
    return a+b;
}

int main(int argc, char const *argv[])
{
    printf("Tong a va b: %d\n", sum(5,6));
    printf("Tong a va b: %d\n", cong(5,6));
    return 0;
}