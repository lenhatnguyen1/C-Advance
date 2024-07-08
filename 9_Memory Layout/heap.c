#include <stdio.h>
#include <stdint.h>

uint32_t arr[] = {2,3,5,6,8}; 


int main() {

    for (int i = 0; i < 5; i++)
    {
        printf("Address: %p\n", arr +i);
        printf("Value: %d\n", *(arr+i));
    }
    

    
    return 0;
}