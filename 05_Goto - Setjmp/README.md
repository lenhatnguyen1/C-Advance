# Bài 5: Goto - Setjmp
## 1. Goto
goto là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm.
```c
#include <stdio.h>

int main() {
    int i = 0;

    // Đặt nhãn
    start:
        if (i >= 5) {
            goto end;  // Chuyển control đến nhãn "end"
        }

        printf("%d ", i);
        i++;

        goto start;  // Chuyển control đến nhãn "start"

    // Nhãn "end"
    end:
        printf("\n");

    return 0;
}
```
```c
#include <stdio.h>

void delay()
{
    double start;
    while (start < 60000000)
    {
        start++;
    }
    
}

char letter = 'A';

char first_sentence[] = "HELLO";
char second_sentence[] = "FASHION SUIT";
char third_sentence[] = "SUITABLE PRICE";


int letter_A[8][8] = {  {0,0,1,0,0,0,0,0},
                        {0,1,0,1,0,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,1,1,1,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},  };

int letter_H[8][8] = {  {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,1,1,1,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},
                        {1,0,0,0,1,0,0,0},  };

int letter_L[8][8] = {  {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0},
                        {1,1,1,1,1,0,0,0},  };


/*
H, e, l,o, F, a, ....
*/



int button = 0;

typedef enum
{
    FIRST,
    SECOND,
    THIRD

}   Sentence;

int main() {

    Sentence sentence = FIRST;

    while(1)
    {
        switch (sentence)
        {
        case FIRST:
            for (int index = 0; index < sizeof(first_sentence); index++)
            {
                if (first_sentence[index] == 'H')
                {
                    for (int i = 0; i < 8; i++) 
                    {    
                        for (int j = 0; j < 8; j++) 
                        {
                            if (letter_H[i][j] == 1) 
                            {
                                printf("Turn on led at [%d][%d]\n", i,j);
                                if (button == 1)
                                {
                                   goto exit_loops;
                                }
                                
                            }
                        }
                        // tat den
                    }
                }
                if (first_sentence[index] == 'e')
                {
                    // in ra chu e
                }
            }
            printf("first sentence is done\n");
            delay();
            goto logic;

        case SECOND:
            for (int index = 0; index < sizeof(second_sentence); index++)
            {
                if (second_sentence[index] == 'A')
                {
                    for (int i = 0; i < 8; i++) 
                    {    
                        for (int j = 0; j < 8; j++) 
                        {
                            if (letter_A[i][j] == 1) 
                            {
                                printf("Turn on led at [%d][%d]\n", i,j);
                                if (button == 1)
                                {
                                   goto exit_loops;
                                }
                                
                            }
                        }
                        // tat den led
                    }
                }
                if (second_sentence[index] == 'F')
                {
                    // in ra chu F
                }
            }
            printf("second sentence is done\n");
            delay();
            goto logic;

        case THIRD:
            for (int index = 0; index < sizeof(third_sentence); index++)
            {
                if (third_sentence[index] == 'L')
                {
                    for (int i = 0; i < 8; i++) 
                    {    
                        for (int j = 0; j < 8; j++) 
                        {
                            if (letter_L[i][j] == 1) 
                            {
                                printf("Turn on led at [%d][%d]\n", i,j);
                                if (button == 1)
                                {
                                   goto exit_loops;
                                }
                                
                            }
                        }
                        // tat den led
                    }
                }
                if (third_sentence[index] == 'E')
                {
                    // in ra chu H
                }
            }
            printf("third sentence is done\n");
            delay();
            //button = 1;
            goto logic;
        }

        logic:
            if (sentence == FIRST)
            {
                sentence = SECOND;
            }
            else if (sentence == SECOND)
            {
                sentence = THIRD;
            }
            else if (sentence == THIRD)
            {
                sentence = FIRST;
            }
            goto exit;
            
        exit_loops:
            printf("Stop!\n");
            break;
        
        exit:;
        
            
    }
    




    return 0;
}
```

## 2. Setjmp
setjmp.h là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.
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