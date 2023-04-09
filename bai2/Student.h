#pragma once
#include <iostream>
#include <iomanip>
#include "string.h"
#include "Date.h"
#include "schedule.h"
class Student
{
private:
    string id;
    string name;
    Date birthday;
    string address;
public:
    schedule Schedule;
    // constructor 
    Student();
    Student(string id, string name, Date birth, string address);
    // destructor
    ~Student();
    // copy method 
    Student(const Student& student);
    // gettor
    string getID();
    //input a student form screen
    friend std::istream& operator>> (std::istream& is, Student& src);
    //output a student to screen
    friend std::ostream& operator<< (std::ostream& os, const Student& src);
};

