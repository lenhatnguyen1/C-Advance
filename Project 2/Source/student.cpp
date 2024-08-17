/*
* File: student.cpp
* Author: Le Nhat Nguyen
* Date: 16/08/2024
* Description: This file is source code for student
*/

#include "../Header/student.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int Student::currentID = 20240000; // Khởi tạo giá trị ID ban đầu

Student::Student() {
    id = to_string(currentID);
    currentID++; // Tăng ID sau khi tạo mỗi sinh viên
}

/*
* Function: inputInfo
* Description: This function display the input screen and handle user input
* Input: None
* Output: None
*/
void Student::inputInfo() {
    cin.ignore(); // Remove '\n' remain in buffer
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap diem Toan: ";
    cin >> math;
    cout << "Nhap diem Ly: ";
    cin >> physics;
    cout << "Nhap diem Hoa: ";
    cin >> chemistry;
    calculateAverage();
    determineGrade();
}

/*
* Function: displayInfo
* Description: This function display the infomation of student
* Input: None
* Output: None
*/
void Student::displayInfo() const {
    cout << "ID: " << id << ", Ten: " << name << ", Toan: " << math
         << ", Ly: " << physics << ", Hoa: " << chemistry
         << ", Diem trung binh: " << average
         << ", Xep loai: " << grade << endl;
}

/*
* Function: calculateAverage
* Description: This function calculate the average score
* Input: None
* Output: None
*/
void Student::calculateAverage() {
    average = (math + physics + chemistry) / 3.0f;
}

/*
* Function: determineGrade
* Description: This function determine the grade
* Input: None
* Output: None
*/
void Student::determineGrade() {
    if (average >= 8.0f) {
        grade = "Gioi";
    } else if (average >= 6.5f) {
        grade = "Kha";
    } else if (average >= 5.0f) {
        grade = "Trung binh";
    } else {
        grade = "Yeu";
    }
}

/*
* Function: StudentManager (Constructor)
* Description: This function use to load from database file
* Input: None
* Output: None
*/
StudentManager::StudentManager() {
    loadFromFile();
}

/*
* Function: loadFromFile
* Description: This function use to load data from database file
* Input: None
* Output: None
*/
void StudentManager::loadFromFile() {
    studentList.clear();
    ifstream file(databaseFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Student student;
            string temp;

            try {
                // Đọc và loại bỏ khoảng trắng
                getline(ss, temp, ',');
                student.setName(temp);
                
                getline(ss, temp, ',');
                temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
                student.setMath(stof(temp));
                
                getline(ss, temp, ',');
                temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
                student.setPhysics(stof(temp));
                
                getline(ss, temp, ',');
                temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
                student.setChemistry(stof(temp));
                
                getline(ss, temp, ',');
                temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
                student.setAverage(stof(temp));
                
                getline(ss, temp, ',');
                student.setGrade(temp);

                studentList.push_back(student);
            } catch (const invalid_argument& e) {
                cerr << "Error reading line: " << line << endl;
                cerr << "Exception: " << e.what() << endl;
            }
        }
        file.close();
    } else {
        cerr << "Failed to open file!" << endl;
    }
}

/*
* Function: saveToFile
* Description: This function use to save data to database file
* Input: None
* Output: None
*/
void StudentManager::saveToFile() const {
    ofstream file(databaseFile);
    if (file.is_open()) {
        for (const auto& student : studentList) {
            file << student.getId() << "," << student.getName() << ","
                 << student.getMath() << "," << student.getPhysics() << ","
                 << student.getChemistry() << "," << student.getAverage() << ","
                 << student.getGrade() << endl;
        }
        file.close();
    } else {
        cout << "Khong the mo file de luu!" << endl;
    }
}

/*
* Function: addStudent
* Description: This function use to add new student
* Input: None
* Output: None
*/
void StudentManager::addStudent() {
    Student student;
    student.inputInfo();
    studentList.push_back(student);
    saveToFile();
    cout << "Da them sinh vien thanh cong!" << endl;
}

/*
* Function: editStudent
* Description: This function use to edit student data
* Input: None
* Output: None
*/
void StudentManager::editStudent() {
    string id;
    cout << "Nhap ID sinh vien can sua: ";
    cin >> id;
    for (auto& student : studentList) {
        if (student.getId() == id) {
            student.inputInfo();
            saveToFile();
            cout << "Da sua thong tin sinh vien thanh cong!" << endl;
            return;
        }
    }
    cout << "Sinh vien voi ID nay khong ton tai!" << endl;
}

/*
* Function: deleteStudent
* Description: This function use to delete student data
* Input: None
* Output: None
*/
void StudentManager::deleteStudent() {
    string id;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> id;
    auto it = remove_if(studentList.begin(), studentList.end(), [id](const Student& student) {
        return student.getId() == id;
    });
    if (it != studentList.end()) {
        studentList.erase(it, studentList.end());
        saveToFile();
        cout << "Da xoa sinh vien thanh cong!" << endl;
    } else {
        cout << "Sinh vien voi ID nay khong ton tai!" << endl;
    }
}

/*
* Function: searchStudent
* Description: This function use to search student data
* Input: None
* Output: None
*/
void StudentManager::searchStudent() const {
    string id;
    cout << "Nhap ID sinh vien can tim: ";
    cin >> id;
    for (const auto& student : studentList) {
        if (student.getId() == id) {
            student.displayInfo();
            return;
        }
    }
    cout << "Sinh vien voi ID nay khong ton tai!" << endl;
}

/*
* Function: sortStudents
* Description: This function use to sort student data
* Input: None
* Output: None
*/
void StudentManager::sortStudents() {
    studentList.sort([](const Student& a, const Student& b) {
        return a.getId() < b.getId();
    });
    saveToFile();
    cout << "Da sap xep sinh vien theo ID!" << endl;
}

/*
* Function: displayStudents
* Description: This function use to display all student data
* Input: None
* Output: None
*/
void StudentManager::displayStudents() const {
    if (studentList.empty()) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    for (const auto& student : studentList) {
        student.displayInfo();
    }
}

