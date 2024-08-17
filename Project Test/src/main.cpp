/*
* File: main.c
* Author: Le Nhat Nguyen
* Date: 12/08/2024
* Description: This is the main file in project. Handle the menu and user choice.
*/

#include "../header/StudentManager.hpp"
#include "../header/Student.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    StudentManager manager;
    int choice;

    do {
        std::cout << "1. Add student\n"
                  << "2. Update student by ID\n"
                  << "3. Delete student by ID\n"
                  << "4. Display all students\n"
                  << "5. Sort students by name\n"
                  << "6. Sort students by average\n"
                  << "7. Sort students by ID\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2: {
                std::string id;
                std::cout << "Enter student ID: ";
                std::getline(std::cin, id);
                manager.updateStudentById(id);
                break;
            }
            case 3: {
                std::string id;
                std::cout << "Enter student ID: ";
                std::getline(std::cin, id);
                manager.deleteStudentById(id);
                break;
            }
            case 4:
                manager.displayAllStudents();
                break;
            case 5:
                manager.sortStudentsByName();
                break;
            case 6:
                manager.sortStudentsByAverage();
                break;
            case 7:
                manager.sortStudentsById();
                break;
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
