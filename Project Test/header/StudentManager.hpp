#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.hpp"
#include <string>
#include <list>

using namespace std;


class StudentManager {
private:
    std::list<Student> students;

public:
    void addStudent();
    void updateStudentById(const std::string& id);
    void deleteStudentById(const std::string& id);
    Student* findStudentById(const std::string& id);
    void sortStudentsByName();
    void sortStudentsByAverage();
    void sortStudentsById();
    void displayAllStudents() const;
};

#endif
