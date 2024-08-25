/*
* File: student.hpp
* Author: Le Nhat Nguyen
* Date: 16/08/2024
* Description: This file is header for student and student manager
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <list>
#include <string>

using namespace std;

class Student {
private:
    static int currentID;
    string id;
    string name;
    float math;
    float physics;
    float chemistry;
    float average;
    string grade;
public:
    Student(); // Constructor
    void inputInfo(); 
    void displayInfo() const;
    void calculateAverage();
    void determineGrade();

    // Getter methods for private members
    string getId() const { return id; }
    string getName() const { return name; }
    float getMath() const { return math; }
    float getPhysics() const { return physics; }
    float getChemistry() const { return chemistry; }
    float getAverage() const { return average; }
    string getGrade() const { return grade; }
    
    // Setter methods for private members
    void setId(const string& newId) { id = newId; }
    void setName(const string& newName) { name = newName; }
    void setMath(float newMath) { math = newMath; }
    void setPhysics(float newPhysics) { physics = newPhysics; }
    void setChemistry(float newChemistry) { chemistry = newChemistry; }
    void setAverage(float newAverage) { average = newAverage; }
    void setGrade(const string& newGrade) { grade = newGrade; }
};

class StudentManager : public Student {
private:
    list<Student> studentList;
    const string databaseFile = "../Database/database_sv.csv";
    
    void loadFromFile();
    void saveToFile() const;

    list<Student>::iterator binarySearch(const std::string& id);
public:
    StudentManager();
    void addStudent();
    void editStudent();
    void deleteStudent();
    void searchStudent() const;
    void sortStudents();
    void displayStudents() const;
};

#endif // STUDENT_H
