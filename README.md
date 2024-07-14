# C/C++ Programming Advance
This is my project to learn and practice advanced programming skills in C/C++ language

## Authors
- Lê Nhật Nguyên
- Github: [@lenhatnguyen1](https://github.com/lenhatnguyen1)
- Youtube: 

## Tech Stack

**Software:** Visual Studio Code, Visual Studio

**Compiler:** GCC

## List of lessons:
- 1: Compiler - Macro
- 2: STDARG - ASSERT
- 3: Pointer
- 4: Extern - Static - Volatile
- 5: Goto - Setjmp
- 6: Bitmask
- 7: Struct - Union
- 8: JSON
- 9: Memory Layout
- 10: Linked List
- 11: Stack - Queue
- 12: Binary Search

## Lesson 1: Compiler - Macro
### Compiler
Compiler trong ngôn ngữ C là chương trình chuyển đổi mã nguồn từ ngôn ngữ lập trình cấp cao (C) sang ngôn ngữ máy (mã nhị phân) mà máy tính có thể hiểu và thực thi được. Quá trình này bao gồm nhiều bước chính:

- Preprocessing (Tiền xử lý): Xử lý các chỉ thị tiền xử lý như #include, #define.
- Compilation (Biên dịch): Chuyển đổi mã nguồn C thành mã assembly.
- Assembly (Lắp ráp): Chuyển đổi mã assembly thành mã máy (mã nhị phân).
- Linking (Liên kết): Kết hợp mã máy với các thư viện cần thiết để tạo ra tệp thực thi cuối cùng.
Các compiler phổ biến cho C bao gồm GCC (GNU Compiler Collection), Clang, và MSVC (Microsoft Visual C++).

### Macro
Trong ngôn ngữ C, macro là một đoạn mã ngắn hoặc một chuỗi lệnh được định nghĩa bằng chỉ thị tiền xử lý #define. Macro giúp đơn giản hóa mã nguồn và tránh lặp lại các đoạn mã giống nhau. Macro được xử lý trước khi quá trình biên dịch bắt đầu.

Có hai loại macro chính:

Object-like Macro: Được sử dụng để định nghĩa các hằng số.

`#define PI 3.14`
Function-like Macro: Được sử dụng để định nghĩa các hàm ngắn gọn.


`#define MAX(a, b) ((a) > (b) ? (a) : (b))`
Lợi ích của macro:

Giúp mã nguồn gọn gàng, dễ bảo trì.
Tăng hiệu suất chương trình do tránh được overhead của lời gọi hàm (function call).
Nhược điểm của macro:

Không có kiểm tra kiểu (type checking), có thể dẫn đến lỗi không mong muốn.
Khó debug do không có thông tin về macro trong mã máy.

## Lesson 2: 
### stdarg.h
Thư viện stdarg.h trong ngôn ngữ C cung cấp các macro để xử lý các hàm có số lượng tham số không cố định, còn gọi là variadic functions. Các macro chính bao gồm:

va_list: Kiểu dữ liệu dùng để khai báo một biến lưu trữ danh sách các tham số.
va_start: Khởi tạo danh sách các tham số.
va_arg: Lấy ra từng tham số trong danh sách.
va_end: Kết thúc việc xử lý danh sách các tham số.
Ví dụ về sử dụng variadic functions:

```c
#include <stdio.h>
#include <stdarg.h>

void print_numbers(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        printf("%d\n", num);
    }

    va_end(args);
}

int main() {
    print_numbers(3, 1, 2, 3);
    return 0;
}
```
### assert.h
Thư viện assert.h cung cấp macro assert để kiểm tra các điều kiện trong quá trình chạy chương trình. Nếu điều kiện không đúng (false), chương trình sẽ in ra thông báo lỗi và kết thúc.

Cú pháp:

```c
#include <assert.h>
assert(expression);
```
Ví dụ:

```c
#include <stdio.h>
#include <assert.h>

int main() {
    int x = 10;
    assert(x == 10);  // Đúng, không có gì xảy ra
    assert(x == 5);   // Sai, chương trình sẽ in thông báo lỗi và dừng lại

    printf("This will not be printed\n");
    return 0;
}
```
Lợi ích của assert:

Giúp phát hiện sớm các lỗi logic trong quá trình phát triển.
Có thể bị vô hiệu hóa (disabled) trong phiên bản phát hành (release build) bằng cách định nghĩa NDEBUG trước khi bao gồm assert.h.
```c
#define NDEBUG
#include <assert.h>
```
## Lesson 3: Pointer
### Pointer
Pointer (con trỏ) là một biến lưu trữ địa chỉ của một biến khác. Con trỏ giúp chúng ta truy cập và thao tác trực tiếp trên bộ nhớ.

Cú pháp khai báo con trỏ:

```c
int *ptr;
```
Ví dụ:

```c
int x = 10;
int *ptr = &x;  // ptr lưu địa chỉ của x
printf("%d", *ptr);  // truy cập giá trị của x thông qua ptr
```
### Void Pointer
Void pointer (con trỏ kiểu void) là con trỏ có thể trỏ tới bất kỳ kiểu dữ liệu nào. Void pointer không thể dereference trực tiếp vì không biết kích thước của dữ liệu nó trỏ tới.

Khai báo:

`void *ptr;`
Ví dụ:

```c
int x = 10;
void *ptr = &x;
printf("%d", *(int *)ptr);  // cần ép kiểu trước khi dereference
```
### Function Pointer
Function pointer (con trỏ hàm) là con trỏ lưu trữ địa chỉ của một hàm. Có thể dùng con trỏ hàm để gọi hàm một cách linh hoạt.

Khai báo:

`return_type (*ptr)(parameter_types);`
Ví dụ:

```c
#include <stdio.h>

void say_hello() {
    printf("Hello!\n");
}

int main() {
    void (*func_ptr)() = say_hello;
    func_ptr();  // gọi hàm thông qua con trỏ
    return 0;
}
```
### Pointer to Constant
Pointer to constant (con trỏ tới hằng số) là con trỏ không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó lưu.

Khai báo:

`const int *ptr;`
Ví dụ:

```c
int x = 10;
int y = 20;
const int *ptr = &x;
ptr = &y;  // hợp lệ
//*ptr = 30;  // lỗi, không thể thay đổi giá trị của x thông qua ptr
```
### Constant Pointer
Constant pointer (con trỏ hằng) là con trỏ không thể thay đổi địa chỉ mà nó lưu, nhưng có thể thay đổi giá trị mà nó trỏ tới.

Khai báo:

`int *const ptr;`
Ví dụ:

```c
int x = 10;
int y = 20;
int *const ptr = &x;
//ptr = &y;  // lỗi, không thể thay đổi địa chỉ mà ptr trỏ tới
*ptr = 30;  // hợp lệ, có thể thay đổi giá trị của x thông qua ptr
```
### Pointer to Constant
Con trỏ kết hợp cả hai tính chất trên, không thể thay đổi cả địa chỉ và giá trị mà nó trỏ tới.

Khai báo:

`const int *const ptr;`
Ví dụ:

```c
int x = 10;
const int *const ptr = &x;
//ptr = &y;  // lỗi
//*ptr = 20;  // lỗi
```
## Lesson 4: Memory Layout
Trong lập trình C, bộ nhớ của một chương trình được chia thành các vùng khác nhau. Dưới đây là các vùng bộ nhớ chính trong layout của bộ nhớ:

1. Text Segment (Code Segment):

Chứa mã lệnh của chương trình.
Là vùng bộ nhớ chỉ đọc, để ngăn chặn việc sửa đổi mã lệnh trong quá trình thực thi.
2. Data Segment:

Chứa các biến toàn cục (global) và các biến tĩnh (static) được khởi tạo trước khi chương trình bắt đầu thực thi.
Chia thành hai phần:
Initialized Data Segment: Chứa các biến toàn cục và tĩnh được khởi tạo với giá trị khác 0.
Uninitialized Data Segment (BSS - Block Started by Symbol): Chứa các biến toàn cục và tĩnh được khởi tạo với giá trị 0 hoặc chưa được khởi tạo. Kích thước của vùng này được thiết lập trong quá trình biên dịch, nhưng không chiếm dung lượng trong tệp thực thi.
Heap:

Được sử dụng cho cấp phát bộ nhớ động (dynamic memory allocation) như malloc, calloc, realloc.
Vùng bộ nhớ này có thể mở rộng hoặc thu nhỏ trong quá trình thực thi chương trình.
Stack:

Chứa các biến cục bộ (local variables) và các thông tin điều khiển như địa chỉ trả về của hàm, các tham số của hàm, và các biến tự động.
Phát triển từ trên xuống (hướng giảm địa chỉ) và tự động quản lý thông qua việc gọi hàm và trả về từ hàm.
Minh họa Layout của Bộ nhớ
css
Copy code
+----------------------+ 0xFFFFFFFF (Top of Memory)
|       Stack          |
|          |           |
|          V           |
|     (chứa các biến   |
|     cục bộ và các    |
|     thông tin điều   |
|     khiển hàm)       |
+----------------------+
|          |           |
|          V           |
|         Heap         |
|     (cấp phát động)  |
+----------------------+
| .bss (uninitialized) |   } Data Segment
| .data (initialized)  |   }
+----------------------+
|      Text Segment    | (code segment, read-only)
+----------------------+ 0x00000000 (Bottom of Memory)
Ví dụ
Giả sử có chương trình sau:

c
Copy code
#include <stdio.h>
#include <stdlib.h>

int global_var = 10;  // Biến toàn cục, nằm trong initialized data segment
static int static_var;  // Biến tĩnh, nằm trong BSS segment

void func() {
    int local_var = 5;  // Biến cục bộ, nằm trong stack
    int *dynamic_var = (int *)malloc(sizeof(int));  // Biến động, nằm trong heap
    *dynamic_var = 15;
    printf("Local: %d, Dynamic: %d\n", local_var, *dynamic_var);
    free(dynamic_var);
}

int main() {
    func();
    return 0;
}
Trong ví dụ trên:

global_var được lưu trữ trong initialized data segment.
static_var được lưu trữ trong BSS segment.
local_var được lưu trữ trong stack.
dynamic_var được cấp phát bộ nhớ trong heap thông qua malloc.
Tổng kết
Layout bộ nhớ của một chương trình C bao gồm các vùng riêng biệt để quản lý mã lệnh, dữ liệu tĩnh, dữ liệu động và dữ liệu tạm thời. Việc hiểu rõ layout bộ nhớ giúp lập trình viên quản lý bộ nhớ hiệu quả và tránh các lỗi liên quan đến bộ nhớ như tràn stack, tràn heap, hay sử dụng bộ nhớ chưa được cấp phát.