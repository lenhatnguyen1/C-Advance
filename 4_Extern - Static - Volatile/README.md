# Bài 4: Extern - Static - Volatile 
## 1. Extern
Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.
```c
#include <stdio.h>
void exampleFunction() {
    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
}

int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;
}
```
## 2. Static
### a. Static local variables
Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.
```c
#include <stdio.h>

void exampleFunction() {
    static int count = 0; 
    // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
}
    
int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;
}

```
### b. Static global variables
Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.
Ứng dụng: dùng để thiết kế các file thư viện.
```c
#include <math.h>


typedef struct {
    float x1;
    float x2;
} Equation;

static int A,B,C;

void inputCoefficients(int a, int b, int c) {
A = a;
B = b;
C = c;
}

static float calculateDelta() 
{
    return B * B - 4 * A * C;
}

void result(Equation *equation) {
    float delta = calculateDelta();
    if (delta > 0) {
        equation->x1 = (-B + sqrt(delta)) / (2 * A);
        equation->x2 = (-B - sqrt(delta)) / (2 * A);
    } else if (delta == 0) {
        equation->x1 = equation->x2 = -B / (2 * A);
    } else {
        equation->x1 = equation->x2 = -1;
    }
}

```

## 3. Volatile
Từ khóa volatile trong ngôn ngữ lập trình C được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.
```c
#include "stm32f10x.h"

volatile int i = 0;
int a = 100;

int main()
{
    
    while(1)
    {
        i = *((int*) 0x20000000);
        if (i > 0)
        {
            break;
        }
        
    }
    a = 200;
}



```