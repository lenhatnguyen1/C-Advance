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

### Pointer to Pointer
A pointer to a pointer in C is a construct that allows you to reference another pointer.
`int **ptr;`
```c
 int value = 10;    // A simple integer variable
    int *ptr1;         // A pointer to an integer
    int **ptr2;        // A pointer to a pointer to an integer

    ptr1 = &value;     // ptr1 now holds the address of value
    ptr2 = &ptr1;      // ptr2 now holds the address of ptr1

    printf("Value: %d\n", value);      // Prints the value of the integer variable
    printf("Value using ptr1: %d\n", *ptr1); // Prints the value by dereferencing ptr1
    printf("Value using ptr2: %d\n", **ptr2); // Prints the value by dereferencing ptr2
```

## Lesson 4: Memory Layout
The memory of a program is divided into different regions. Below are the main memory areas in the memory layout:

#### 1. Text Segment (Code Segment):
- Contains the program code.
- Is a read-only memory area, to prevent code modification during execution.

#### 2. Data Segment:
- Contains global variables and static variables that are initialized before the program begins executing.
Divided into two parts:
- Initialized Data Segment: Contains global and static variables initialized to a non-zero value.
- Uninitialized Data Segment (BSS - Block Started by Symbol): Contains global and static variables that are initialized with the value 0 or have not been initialized. The size of this region is set during compilation, but does not take up space in the executable.

#### 3. Heap:
- Used for dynamic memory allocation such as malloc, calloc, realloc.
- This memory area can be expanded or contracted during program execution.

#### 4. Stack:
Contains local variables and control information such as function return addresses, function parameters, and automatic variables.
Developed from the top down (address reduction direction) and automatically managed through function calls and function returns.

```c
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
```

global_var is stored in the initialized data segment.
static_var is stored in the BSS segment.
local_var is stored in the stack.
dynamic_var is allocated memory in the heap via malloc.


## Lesson 5: Goto - Setjmp
### Goto
The `goto` statement in C provides a way to transfer control to a labeled statement within the same function. It can be useful for jumping out of nested loops or for handling errors, but it should be used sparingly as it can make code harder to understand and maintain.

Syntax
```c 
oto label;
...
label:
    statement;
```

### Setjmp
setjmp.h is a library in the C programming language, providing two main functions: setjmp and longjmp. Both of these functions are commonly used to perform exception handling in C, although it is not a typical way to handle exceptions in this language.

```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        THROW(1); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error: Divide by 0!\n");
    }


    // Các xử lý khác của chương trình
    return 0;
}
```

## Lesson 6: Bitmask
- Bitmask is a technique that uses bits to store and manipulate flags or states. Bitmasks can be used to set, clear, and check the status of specific bits in a word.
- Bitmasks are often used to optimize memory, perform logical operations on a group of bits, and manage states, access rights, or other attributes of an object.
### NOT bitwise
Used to perform a bitwise NOT operation on each bit of a number. The result is the inverted bits of that number.
int result = ~num;

### AND bitwise
Used to perform a bitwise AND operation between each pair of bits of two numbers. The result is 1 if both corresponding bits are 1; otherwise, it is 0.
int result = num1 & num2;

### OR bitwise
Used to perform a bitwise OR operation between each pair of bits of two numbers. The result is 1 if at least one of the corresponding bits is 1.
int result = num1 | num2;

### XOR bitwise
Used to perform a bitwise XOR operation between each pair of bits of two numbers. The result is 1 if only one of the corresponding bits is 1.
int result = num1 ^ num2;

### Shift left and Shift right bitwise
Used to shift bits to the left or right.
In the case of <<, the bits on the right will be shifted to the left, and the leftmost bits will be set to 0.
In the case of >>, the bits on the left will be shifted to the right, and the rightmost bits will be set to 0 or 1 depending on the value of the highest bit (the sign bit).
```c 
int resultLeftShift = num << shiftAmount;
int resultRightShift = num >> shiftAmount;
```

## Lesson 7: Struct - Union
### Struct
A struct in C is a composite data type that groups together variables of different types under a single name, allowing for the organization of complex data.
```c
struct StructName {
    datatype1 member1;
    datatype2 member2;
    // ...
};

### Union
A union in C is a data type that allows different variables to share the same memory location, with the size of the union being determined by its largest member.

```c
union UnionName {
    datatype1 member1;
    datatype2 member2;
    // ...
};
```


