//
//  student.h
//  C867 PA Class Roster
//
//  Created by Joshua Alexander on 5/21/24.
//
#include <iostream>
#include "degree.h"
#ifndef student_h
#define student_h
using namespace std;
    class Student {
public:
    Student( string student_id,  string first_name, string last_name,  string email_address, int age, int course_length0, int course_length1, int course_length2, DegreeProgram degree_program);
    
     string getStudentId();
    
    void setStudentId( string id);
    
     string getFirstName();
    
    void setFirstName( string first_name);

     string getLastName();
    
    void setLastName( string last_name);
    
     string getEmailAddress();
    
    void setEmailAddress( string email_address);
    
    int getAge ();
    
    void setAge (int age);
    
    int getCourseLength(int index);
    
    void setCourseLength(int index, int value);
    
    DegreeProgram getDegreeProgram();
    
    void setDegreeProgram(DegreeProgram degree_program);
    
    string degreeProgramToString(DegreeProgram degree_program);
    
    void print();
private:
    
     string student_id;
     string first_name;
     string last_name;
     string email_address;
    int age;
    int course_length[3];
    DegreeProgram degree_program;


};

#endif /* student_h */
