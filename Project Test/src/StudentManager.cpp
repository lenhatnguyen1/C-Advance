#include "../header/StudentManager.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void StudentManager::addStudent() {
    Student newStudent;
    newStudent.inputInfo();
    students.push_back(newStudent);
}

Student* StudentManager::findStudentById(const std::string& id) {
    for (auto& student : students) {
        if (student.getId() == id) {
            return &student;
        }
    }
    return nullptr;
}

void StudentManager::updateStudentById(const std::string& id) {
    Student* student = findStudentById(id);
    if (student) {
        student->inputInfo();
    } else {
        std::cout << "Student not found!\n";
    }
}

void StudentManager::deleteStudentById(const std::string& id) {
    students.remove_if([&id](const Student& student) {
        return student.getId() == id;
    });
}

void StudentManager::sortStudentsByName() {
    students.sort([](const Student& a, const Student& b) {
        return a.getName() < b.getName();
    });
}

void StudentManager::sortStudentsByAverage() {
    students.sort([](const Student& a, const Student& b) {
        return a.getAverage() > b.getAverage(); // Từ cao đến thấp
    });
}

void StudentManager::sortStudentsById() {
    students.sort([](const Student& a, const Student& b) {
        return a.getId() < b.getId();
    });
}

void StudentManager::displayAllStudents() const {
    for (const auto& student : students) {
        student.displayInfo();
        std::cout << "----------------\n";
    }
}
