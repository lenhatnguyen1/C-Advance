/*
* File: Student.c
* Author: Le Nhat Nguyen
* Date: 12/08/2024
* Description: This file 
*/

#include "../header/Student.hpp"
#include <iostream>
#include <string>

using namespace std;

void Student::inputInfo() {
    std::cout << "Enter student ID: ";
    std::getline(std::cin, id);
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter math score: ";
    std::cin >> math;
    std::cout << "Enter physics score: ";
    std::cin >> physics;
    std::cout << "Enter chemistry score: ";
    std::cin >> chemistry;
    std::cin.ignore(); // Ignore newline character

    calculateAverage();
    determineGrade();
}

void Student::displayInfo() const {
    std::cout << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Math: " << math << "\n"
              << "Physics: " << physics << "\n"
              << "Chemistry: " << chemistry << "\n"
              << "Average: " << average << "\n"
              << "Grade: " << grade << "\n";
}

void Student::calculateAverage() {
    average = (math + physics + chemistry) / 3;
}

void Student::determineGrade() {
    if (average >= 9) {
        grade = "Gioi";
    } else if (average >= 7) {
        grade = "Kha";
    } else if (average >= 5) {
        grade = "Trung binh";
    } else {
        grade = "Yeu";
    }
}

std::string Student::getId() const { return id; }
std::string Student::getName() const { return name; }
float Student::getAverage() const { return average; }
