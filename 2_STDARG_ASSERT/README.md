# Marco
Macro được định nghĩa bằng #define và không phải là một phần của ngôn ngữ C gốc mà là một chỉ thị tiền xử lý. Macro thực hiện thay thế văn bản trước khi chương trình được biên dịch.

## Ví dụ 1

```c
// macro_sum_example.c

#include <stdio.h>

#define sum(a, b) a+b

int cong(int a, int b) {
    return a+b;
}

int main(int argc, char const *argv[])
{
    printf("Tong a va b: %d\n", sum(5,6));
    printf("Tong a va b: %d\n", cong(5,6));
    return 0;
}
```

## Ví dụ 2

```c
// macro_function_example.c

#include <stdio.h>

#define CREATE_FUNC(name, cmd)      \
void name() {                       \
    printf(cmd);                    \
}

CREATE_FUNC(test1, "This is test1\n");
CREATE_FUNC(test2, "This is test2\n");

int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}
```

