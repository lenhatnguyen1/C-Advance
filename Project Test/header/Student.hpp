#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string id;
    string name;
    float math;
    float physics;
    float chemistry;
    float average;
    std::string grade;

public:
    void inputInfo();
    void displayInfo() const;
    void calculateAverage();
    void determineGrade();

    std::string getId() const;
    std::string getName() const;
    float getAverage() const;
};

#endif
