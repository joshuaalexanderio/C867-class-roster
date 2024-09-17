//
//  roster.cpp
//  C867 PA Class Roster
//
//  Created by Joshua Alexander on 5/21/24.
//

#include <stdio.h>
#include<iostream>
#include "roster.h"
using namespace std;

Roster::Roster() {
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}
void Roster::parse (string row) {
    
    int course_length[3];
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    DegreeProgram degree_program{};
    
    size_t rhs = row.find(",");
    student_id = row.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = row.find(",", lhs);
    first_name = row.substr(lhs, rhs-lhs);
    
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    last_name = row.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    
    
    
    
    rhs = row.find(",", lhs);
    email_address = row.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    age = stoi(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    course_length[0] = stoi(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    course_length[1] = stoi(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    course_length[2] = stoi(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    if (row.substr(lhs, rhs-lhs) == "SECURITY") {
        degree_program = SECURITY;
        
    }
    else if (row.substr(lhs, rhs-lhs) == "NETWORK") {
        degree_program = NETWORK;
    }
    else if (row.substr(lhs, rhs-lhs) == "SOFTWARE") {
        degree_program = SOFTWARE;
    }
    add(student_id, first_name, last_name, email_address, age, course_length[0], course_length[1], course_length[2], degree_program);
}
void Roster::add(string student_id, string first_name, string last_name, string email_address, int age, int course_length1, int course_length2, int course_length3, DegreeProgram degree_program) {
    for (int i=0; i < 5; i++) {
        if (classRosterArray[i] == NULL) {
            classRosterArray[i] = new Student(student_id, first_name, last_name, email_address, age, course_length1, course_length2, course_length3, degree_program);
            break;
        }
    }

}
void Roster::remove (string student_id) {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(Student *); i++) {
        if (classRosterArray[i] != nullptr and classRosterArray[i]->getStudentId() == student_id) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            break;
        }
        // if not found after last iteration display not found message
        else if (i == sizeof(classRosterArray) / sizeof(Student *) - 1) {
            cout << "The student with the ID: " << student_id << " was not found." << endl;

        }
    }
}
// Iterate through classRosterArray and print each student array element
void Roster::printAll() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(Student *); i++) {
        if (classRosterArray[i] != nullptr){
            classRosterArray[i]->print();
        }
    }
}
void Roster::printAverageDaysInCourse(string student_id) {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(Student *); i++) {
        if (classRosterArray[i]->getStudentId() == student_id){
            int course_length0 = classRosterArray[i]->getCourseLength(0);
            int course_length1 = classRosterArray[i]->getCourseLength(1);
            int course_length2 = classRosterArray[i]->getCourseLength(2);
            int average_course_length = (course_length0 + course_length1 + course_length2) / 3;
            cout << average_course_length << endl;
        }
    }
}
void Roster::printInvalidEmails() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(Student *); i++) {
//         check that email exists
        if (classRosterArray[i]->getEmailAddress() == "") {
            break;
        }
//             check if email at current index has @ or . or whitespace
        else if (classRosterArray[i]->getEmailAddress().find("@") == string::npos || classRosterArray[i]->getEmailAddress().find(".") == string::npos || classRosterArray[i]->getEmailAddress().find(" ") != string::npos) {
            cout << classRosterArray[i]->getEmailAddress() << " - is invalid." <<endl;
            
        }
    }
}
void Roster::printByDegreeProgram(DegreeProgram degree_program) {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(Student *); i++) {
        if (classRosterArray[i]->getDegreeProgram() == degree_program) {
            classRosterArray[i]->print();
        }
    }
}
