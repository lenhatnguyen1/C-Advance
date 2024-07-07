# Bài 7: Struct & Union
## Struct
Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.
```c
struct TenStruct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};

```
```c
struct Example {
    uint8_t a;  // 1 byte  
    uint16_t b; // 2 byte
    uint32_t c; // 4 byte
};
```
```c
struct Example1 {
    uint8_t arr1_1;
uint8_t arr1_2;
uint8_t arr1_3;
uint8_t arr1_4;
uint8_t arr1_5;
uint16_t arr2[4];    
uint32_t arr3[2];
};
```
## Union
Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ.
```c
union TenUnion {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```
## Ví dụ
```c

#include <stdio.h>
#include <stdint.h>

typedef union Data {
    uint8_t arr1[5];
    uint8_t arr2[3];
    uint8_t arr3[6];
}Data;


void display(uint8_t arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d]: %d\n",i, arr[i]);
    }
    printf("----------\n");
}


void display_address(uint8_t arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("address of arr[%d]: %p\n",i, &arr[i]);
    }
    printf("----------\n");
}

int main()
{
    Data data_test;

    data_test.arr1[0] = 11;
    data_test.arr1[1] = 12;
    data_test.arr1[2] = 13;
    data_test.arr1[3] = 14;
    data_test.arr1[4] = 15;
    display(data_test.arr1,5);

    data_test.arr2[0] = 21;
    data_test.arr2[1] = 22;
    data_test.arr2[2] = 23;
    display(data_test.arr2,3);
    display(data_test.arr1,5);

    data_test.arr3[0] = 31;
    data_test.arr3[1] = 32;
    data_test.arr3[2] = 33;
    data_test.arr3[3] = 34;
    data_test.arr3[4] = 35;
    data_test.arr3[5] = 36;
    display(data_test.arr3,6);

    display_address(data_test.arr1,5);
    display_address(data_test.arr2,3);
    display_address(data_test.arr3,6);

}
```
## Ứng dụng kết hợp struct và union
```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;


int main(int argc, char const *argv[])
{
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

        Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
    
    
    return 0;
}
```