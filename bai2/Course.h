#pragma once
#include "string.h"
#include "Date.h"
#include "roster.h"
#include <iomanip>
class Course
{
private:
	string id;
	string name;
	Date open;
	
public:
	roster Roster;
	Course();
	Course(string id, string name, Date date);
	~Course();
	//void print();
	friend std::istream& operator >> (std::istream& is, Course& src);
	friend std::ostream& operator << (std::ostream& os, const Course& src);
	
};

