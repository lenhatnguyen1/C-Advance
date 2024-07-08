#include <stdio.h>

// Khai báo biến toàn cục với từ khóa extern
extern int count;

void updateCount() {
    count = 20;
    printf("Count trong updateCount: %d\n", count);
}
