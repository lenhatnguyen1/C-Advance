#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 10, b = 20;
    swap(&a, &b);
    
    printf("value a is: %d\n", a);
    printf("value b is: %d\n", b);
    
    printf("Address of a: %p\n", (void*)&a);
    printf("Address of b: %p\n", (void*)&b);
    return 0;
}
