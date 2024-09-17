//
//  roster.h
//  C867 PA Class Roster
//
//  Created by Joshua Alexander on 5/21/24.
//

#ifndef roster_h
#define roster_h
#include <string>
#include <cstring>
#include "student.h"
#include "degree.h"
class Roster {
public:
    Roster();
    //Roster class instantiated statically in main
    ~Roster(){
        for (int i = 0; i < sizeof(classRosterArray) / sizeof(Student *); i++) {
            delete classRosterArray[i];
    
        }
    };
    Student* classRosterArray[5];
    void parse( string row);
    void add( string student_id,  string first_name,  string last_name,  string email_address, int age, int course_length1, int course_length2, int course_length3, DegreeProgram degree_program);
    void remove (string student_id);
    void printAverageDaysInCourse(string student_id);
    void printAll();
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    private:

};

#endif /* roster_h */
