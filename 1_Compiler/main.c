#include<stdio.h>
#include"test.c"

void display(char a) {
    printf(a);
}

int main(int argc, char const *argv[])
{  
    char word = "Hello";
    display(word);
    return 0;
}
