# Bài 1: Compiler & Macro
## Cài đặt:
- Visual Studio Code
- Visual Studio
- GCC
## Compiler:
- Dịch ngôn ngữ lập trình sang ngôn ngữ máy
- Gcc là 1 compiler miễn phí
## Source file
- file.c, file.h
- file.cpp, file.hpp
## Tiền xử lý (Preprocessor)
Tiền xử lý (preprocessing) trong ngôn ngữ lập trình C là giai đoạn đầu tiên trong quá trình biên dịch một chương trình C.

Trong giai đoạn này, một chương trình gọi là preprocessor sẽ xử lý mã nguồn trước khi trình biên dịch chính bắt đầu làm việc.

## Tiền xử lý trong vi điều khiển
IDE cho STM32 (build main.c -> main.hex): https://developer.arm.com/

## Tiền xử lý (Preprocessor)

file.c -> file.i
```bash
  gcc -E main.c -o main.i
```

file.i -> file.s
```bash
  gcc main.i -S -o main.s
```

file.s -> file.o
```bash
  gcc -c main.s -o main.o
```

## Macro
Macro trong lập trình C là một khái niệm liên quan đến tiền xử lý, cho phép bạn định nghĩa các đoạn mã hoặc hằng số để sử dụng lại nhiều lần trong chương trình. 

Macro được định nghĩa bằng cách sử dụng chỉ thị #define. Khi chương trình được biên dịch, trình tiền xử lý sẽ thay thế tất cả các tên macro bằng nội dung mà chúng đại diện.

Lợi ích của Macro
- Tính tái sử dụng
- Tăng hiệu suất
- Dễ bảo trì
Nhược điểm của Macro
- Khó gỡ lỗi
- Thiếu kiểm tra kiểu
- Khả năng mở rộng hạn chế

## So sánh Macro và Function trong C


| Đặc điểm           | Macro                                     | Function          |
|--------------------|-------------------------------------------|-------------------|
| **Hiệu suất**      | Không có chi phí gọi hàm | Có chi phí gọi hàm|
| **Kiểm tra kiểu**  | Không                                     | Có                |
| **Gỡ lỗi**         | Khó                                       | Dễ                |
| **Khả năng mở rộng** | Hạn chế                                   | Tốt               |
| **Phạm vi hoạt động** | Không có                                 | Có                |
| **Thay thế văn bản** | Có                                       | Không             |

## Ví dụ về Macro Function
```c
#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main() {
    int num = 5;
    printf("Square of %d is %d\n", num, SQUARE(num));
    return 0;
}
```



