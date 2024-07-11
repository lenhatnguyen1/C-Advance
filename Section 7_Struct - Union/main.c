#include <stdio.h>
#include <string.h>

// Định nghĩa struct lưu trữ thông tin sinh viên
struct Student {
    int id;
    char name[50];
    char gender;
};

// Định nghĩa union lưu trữ điểm thi
union Grade {
    int intGrade;
    float floatGrade;
    char charGrade;
};

// Định nghĩa struct lưu trữ thông tin sinh viên và điểm thi
struct StudentGrade {
    struct Student student;
    int gradeType; // 0 = int, 1 = float, 2 = char
    union Grade grade;
};

// Hàm in thông tin sinh viên và điểm thi
void printStudentGrade(struct StudentGrade sg) {
    printf("ID: %d\n", sg.student.id);
    printf("Name: %s\n", sg.student.name);
    printf("Gender: %c\n", sg.student.gender);
    printf("Grade: ");
    switch (sg.gradeType) {
        case 0:
            printf("%d\n", sg.grade.intGrade);
            break;
        case 1:
            printf("%.2f\n", sg.grade.floatGrade);
            break;
        case 2:
            printf("%c\n", sg.grade.charGrade);
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

int main() {
    // Tạo các sinh viên và điểm thi của họ
    struct StudentGrade sg1;
    sg1.student.id = 1;
    strcpy(sg1.student.name, "John Doe");
    sg1.student.gender = 'M';
    sg1.gradeType = 0; // sử dụng điểm số nguyên
    sg1.grade.intGrade = 85;

    struct StudentGrade sg2;
    sg2.student.id = 2;
    strcpy(sg2.student.name, "Jane Smith");
    sg2.student.gender = 'F';
    sg2.gradeType = 1; // sử dụng điểm số thập phân
    sg2.grade.floatGrade = 92.5;

    struct StudentGrade sg3;
    sg3.student.id = 3;
    strcpy(sg3.student.name, "Alice Johnson");
    sg3.student.gender = 'F';
    sg3.gradeType = 2; // sử dụng điểm chữ
    sg3.grade.charGrade = 'A';

    // In thông tin sinh viên và điểm thi
    printStudentGrade(sg1);
    printStudentGrade(sg2);
    printStudentGrade(sg3);

    return 0;
}
