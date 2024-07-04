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
