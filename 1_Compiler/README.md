Cài đặt:
    - VS Code
    - Gcc
Compiler:
    - Dịch ngôn ngữ lập trình sang ngôn ngữ máy
    - Gcc là 1 compiler miễn phí
Source file
    - file.c, file.h
    - file.cpp, file.hpp
Tiền xử lý (Preprocessor)
    - Từ file.c -> file.i -> file.s (assembly) -> file.o (object file/mã máy)
    - Cú pháp: 
        gcc -E main.c -o main.i
        gcc main.i -S -o main.s
        gcc -c main.s -o main.o
Câu hỏi phỏng vấn:
    - So sánh macro với function?

IDE cho STM32 (build main.c -> main.hex): https://developer.arm.com/