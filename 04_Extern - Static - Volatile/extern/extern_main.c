#include <stdio.h>

// Khai báo các hàm từ file khác
void display();
void updateCount();

int main() {
    extern int count; // Khai báo biến toàn cục

    printf("Count trong main: %d\n", count);
    display();
    updateCount();
    display();

    return 0;
}
