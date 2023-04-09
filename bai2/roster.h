#pragma once
#include "vector.h"
#include "Student.h"
class roster
{
private:
	vector<Student> list;
	
public:
	roster();
	int MAX = 40;
	int size();
	void push(Student student);
	friend std::ostream& operator << (std::ostream& os, const roster& src);

};

