/*
* File: main.cpp
* Author: Le Nhat Nguyen
* Date: 16/08/2024
* Description: This file is the main file of project
*/

#include <iostream>
#include "../Header/UI.hpp"
#include "../Header/student.hpp"

using namespace std;

int main() {
    UI ui;
    StudentManager manager;

    ui.displayHome(manager);

    return 0;
}
