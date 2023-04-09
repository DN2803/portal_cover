#pragma once
#include"string.h"
#include"vector.h"
#include"Course.h"
class schedule
{
private:
	vector<Course> list;
	
public:
	schedule();
	int MAX = 5;
	int size();
	void push(Course course);
	friend std::ostream& operator << (std::ostream& os, const schedule& src);
	
};

