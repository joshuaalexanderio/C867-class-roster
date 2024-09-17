//
//  main.cpp
//  C867 PA Class Roster
//
//  Created by Joshua Alexander on 5/21/24.
//

#include <iostream>
#include "student.h"
#include "roster.h"
//#include "student.cpp"
#include <array>
#include <cstring>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    
    // insert code here...
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Joshua,Alexander,jale468@wgu.edu,23,30,31,30,SECURITY"};
    //    Student student1("A1","John","Smith","John1989@gm ail.com", 20,30,35,40,SECURITY);
    //    student1.setDegreeProgram(SOFTWARE);
    //    student1.print();
    
    //    Print project info
    cout << "C867-Scripting & Programming: Applications" << endl << "Language: C++" << endl << "Student ID: 010979158" << endl << "Name: Joshua Alexander" << endl;
    //    Create instance of Roster class
    Roster classRoster;
    //    Loop over each string in studentData and call parse
    for (int i = 0; i < sizeof(studentData) / sizeof(string); i++){
        classRoster.parse(studentData[i]);
    }
    //   print all students in class roster array
    classRoster.printAll();
    //   print all invalid email addresses
    classRoster.printInvalidEmails();
    //   print average days in course for each student
    for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(Student *); i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
}
