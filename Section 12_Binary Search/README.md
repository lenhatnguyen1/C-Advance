# Bài 12: Binary Search
## Các bước trong thuật toán tìm kiếm nhị phân (Binary Search)
1. Chuẩn bị:
Đảm bảo mảng dữ liệu đã được sắp xếp theo thứ tự tăng dần hoặc giảm dần.
Xác định giá trị cần tìm kiếm (x).

2. Bắt đầu tìm kiếm:
Khởi tạo hai biến đánh dấu vị trí:
left = vị trí đầu tiên của mảng.
right = vị trí cuối cùng của mảng.
Lặp:
Tính toán vị trí mid bằng cách: mid = (left + right) / 2.
So sánh x với giá trị tại mid:
Nếu x == mid:
Tìm thấy x, trả về vị trí mid.
Nếu x < mid:
Cập nhật right = mid - 1.
Tìm kiếm x trong nửa trái của mảng (từ left đến mid - 1).
Nếu x > mid:
Cập nhật left = mid + 1.
Tìm kiếm x trong nửa phải của mảng (từ mid + 1 đến right).
Kết thúc:
Nếu left > right, không tìm thấy x trong mảng.
Lưu ý:

Thuật toán chỉ hoạt động hiệu quả trên mảng đã được sắp xếp.
Cần đảm bảo left luôn nhỏ hơn hoặc bằng right trong suốt quá trình tìm kiếm.
Ví dụ:

Giả sử bạn có mảng đã sắp xếp [1, 3, 5, 7, 9] và muốn tìm kiếm giá trị 5.

Bước 1: Khởi tạo: left = 0, right = 4.

Bước 2: Lặp:

mid = (0 + 4) / 2 = 2.
So sánh 5 với mảng[2] (giá trị tại mid): 5 = 5, tìm thấy 5, trả về vị trí 2.
```c
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;

  
        if (arr[mid] == x)  return mid;

   
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

  
        return binarySearch(arr, mid + 1, r, x);
    }




    return -1;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
       
        for (j = 0; j < n - i - 1; j++)
        {
           
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main()
{
    int n, x, i;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Nhap cac phan tu cua mang: ");
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf_s("i = %d\n", arr[i]);
    }

    printf_s("Nhap gia tri can tim: ");
    scanf_s("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf_s("Khong tim thay %d trong mang.\n", x);
    else
        printf_s("Tim thay %d tai vi tri %d trong mang.\n", x, result);
    free(arr);
    return 0;
}


```