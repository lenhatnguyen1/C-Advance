#include <stdio.h>

const int a = 10;
char arr[] = "Hello";
char *arr1 = "Hello";

int main() {
   

    printf("a: %d\n", a);

    arr[3] = 'W';
    printf("arr: %s", arr);

    arr1[3] = 'E';
    printf("arr1: %s", arr1);

    
    return 0;
}