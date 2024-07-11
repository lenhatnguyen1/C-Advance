// main.c
#include <stdio.h>

#define CREATE_FUNC(name, cmd)      \
void name() {                       \
    printf(cmd);                    \
}

CREATE_FUNC(test1, "This is test1\n");
CREATE_FUNC(test2, "This is test2\n");

#define display(...)                                \
void test() {                                       \
    char* items[] = {__VA_ARGS__};                  \
        int n = sizeof(items) / sizeof(items[0]);   \
        for (int i = 0; i < n; i++) {               \
            printf("test: %s\n", items[i]);         \
        }                                           \
}

int main(int argc, char const *argv[])
{
    display("hello", "123", "hi", "what your name");
    test();
    return 0;
}
