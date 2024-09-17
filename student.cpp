//
//  student.cpp
//  C867 PA Class Roster
//
//  Created by Joshua Alexander on 5/21/24.
//

#include <stdio.h>
#include "student.h"
using namespace std;
Student::Student( string student_id,  string first_name, string last_name,  string email_address, int age, int course_length0, int course_length1, int course_length2, DegreeProgram degree_program) {
    Student::student_id = student_id;
    Student::first_name = first_name;
    Student::last_name = last_name;
    Student::email_address = email_address;
    Student::age = age;
    Student::course_length[0] = course_length0;
    Student::course_length[1] = course_length1;
    Student::course_length[2] = course_length2;
    Student::degree_program = degree_program;
};
string Student::getStudentId() {
        return Student::student_id;
//    }
};
void Student::setStudentId( string id) {
    Student::student_id = id;
}
 string Student::getFirstName() {
    return Student::first_name;
};
void Student::setFirstName( string first_name) {
    Student::first_name = first_name;
}
 string Student::getLastName() {
    return Student::last_name;
};
void Student::setLastName( string last_name) {
    Student::last_name = last_name;
};
 string Student::getEmailAddress() {
    return Student::email_address;
};
void Student::setEmailAddress( string email_address) {
    Student::email_address = email_address;
};
int Student::getAge () {
    return Student::age;
};
void Student::setAge (int age) {
    Student::age = age;
};
int Student::getCourseLength(int index) {
    return Student::course_length[index];
}
void Student::setCourseLength(int index, int value) {
    Student::course_length[index] = value;
}
DegreeProgram Student::getDegreeProgram() {
    return Student::degree_program;
}
void Student::setDegreeProgram(DegreeProgram degree_program) {
Student::degree_program = degree_program;
}
 string Student::degreeProgramToString(DegreeProgram degree_program) {
    switch (degree_program) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
    }
};
void Student::print() {
    cout << Student::student_id <<"   First Name: "<< Student::first_name << "  Last Name: " << Student::last_name << "    Age:" << Student::age << "  daysInCourse: {" << Student::course_length[0] <<", "<< Student::course_length[1] << ", " << Student::course_length[2] << "} " << "Degree Program:" << " " << degreeProgramToString(Student::degree_program) <<  endl;
};
