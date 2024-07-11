#include <stdio.h>
#include <stdarg.h>

void display(int count, ...) {
    va_list args; // kiểu dữ liệu tự định nghĩa (typedef const *char va_list)
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        printf("Value at %d: %d\n", i, va_arg(args,int)); 
    }

    va_end(args); // Thu hồi
}

int main()
{
    display(8, 1, 2, 3, 4, 5, 6, 7, 8);

    return 0;
}



