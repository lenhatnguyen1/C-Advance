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
Compiler is a program that translates source code from a high-level language (like C) into machine code (binary code) that a computer can understand and execute. This process involves several key steps:

1. Preprocessing: Handles preprocessing directives like #include and #define.
2. Compilation: Converts C source code into assembly code.
3. Assembly: Translates assembly code into machine code (binary code).
4. Linking: Combines machine code with necessary libraries to produce the final executable file.

### Macro
In C language, a macro is a short segment of code or a sequence of commands defined using the preprocessing directive #define. Macros simplify source code and prevent repetition of identical code segments. Macros are processed before the compilation process begins.

There are two main types of macros:

Object-like Macro: Used to define constants.


`#define PI 3.14`
Function-like Macro: Used to define short functions.

`#define MAX(a, b) ((a) > (b) ? (a) : (b))`
Benefits of macros include:

- Simplifying and maintaining clean source code.
- Improving program efficiency by avoiding function call overhead.
- Drawbacks of macros include:

Lack of type checking, which can lead to unexpected errors.
Difficulties in debugging due to the absence of macro information in machine code.

### Macro and Function Comparison
#### Definition:
- Macro: Defined using the #define directive in C/C++. Macros are essentially text substitutions that occur during preprocessing.
- Function: Defined using a function prototype and implementation. Functions encapsulate a block of code that is executed when called.

#### Speed:
- Macro: Generally faster because they are expanded inline at compile time. There is no overhead of function call, as the code is inserted directly into the program where the macro is used.
- Function: May have a slight overhead due to the function call mechanism (pushing arguments onto the stack, jumping to the function, etc.). However, modern compilers can often optimize functions to inline them where appropriate, reducing this overhead.

#### Size:
- Macro: Can potentially increase code size because each use of the macro results in the actual code being inserted at multiple points in the program.
- Function: Generally results in smaller code size because the function code is stored once in memory and reused at each call point.

## Lesson 2: 
### stdarg.h
The stdarg.h library in C provides macros for handling functions with a variable number of arguments, also known as variadic functions. The main macros include:

va_list: A data type used to declare a variable that stores the list of arguments.
va_start: Initializes the list of arguments.
va_arg: Retrieves each argument in the list.
va_end: Ends the processing of the list of arguments.

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
The assert.h library provides the assert macro to check conditions during program execution. If the condition is false, the program prints an error message and terminates.

Syntax:

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
Benefits of assert include:
- Early detection of logical errors during development.
- Can be disabled in the release build by defining NDEBUG before including assert.h.

```c
#define NDEBUG
#include <assert.h>
```
## Lesson 3: Pointer
### Pointer
A pointer is a variable that stores the address of another variable. Pointers allow us to access and manipulate memory directly.

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
Void Pointer: A pointer that can point to any data type. A void pointer cannot be dereferenced directly because it does not know the size of the data it points to.

`void *ptr;`
Example:

```c
int x = 10;
void *ptr = &x;
printf("%d", *(int *)ptr);  // cần ép kiểu trước khi dereference
```
### Function Pointer
Function Pointer: A pointer that stores the address of a function. Function pointers can be used to call functions flexibly.


`return_type (*ptr)(parameter_types);`
Example:

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
Pointer to Constant: A pointer that cannot change the value it points to, but can change the address it holds.

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
Constant Pointer: A pointer that cannot change the address it holds, but can change the value it points to.

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
Constant Pointer to Constant: A pointer that cannot change either the address it holds or the value it points to.

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