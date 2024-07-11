#include <stdio.h>

// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}
    
    // Hàm mẫu 2
    void greetFrench() {
        printf("Bonjour!\n");
    }
    
    int main() {
        // Khai báo con trỏ hàm
        void (*ptrToGreet)();
        
        // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
        
        ptrToGreet = greetEnglish;
        
        // Gọi hàm thông qua con trỏ hàm
        (*ptrToGreet)();  // In ra: Hello!
        
        // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
        
        ptrToGreet = greetFrench;
        
        // Gọi hàm thông qua con trỏ hàm
        
        (*ptrToGreet)();  // In ra: Bonjour!
        
        return 0;
    }
