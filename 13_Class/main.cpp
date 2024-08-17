#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        int id;
        string name;
        double grade;
        void display();
    private:
        string Classification();
};

void Student::display() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Classification: " << Classification() << endl;
}

string Student::Classification() {
    if (grade >= 9) return "A";
    else if (grade >= 7) return "B";
    else if (grade >= 5) return "C";
    else return "F";
}
int main()
{
    Student student1, student2;
    student1.id = 1; 
    student1.name = "Nguyen"; 
    student1.grade = 7.0; 
    student1.display();

    student2.id = 2; 
    student2.name = "Ngoc"; 
    student2.grade = 10.0; 
    student2.display();
    return 0;
}
