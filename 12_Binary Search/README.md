Bài 12: Binary Search
Các bước trong thuật toán tìm kiếm nhị phân (Binary Search)
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
em dùng bản visual studio community free đc ko anh