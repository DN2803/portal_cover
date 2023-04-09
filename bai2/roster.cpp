#include "roster.h"

roster::roster()
{
	list;
}

int roster::size()
{
	return list.size();
}

void roster::push(Student student)
{
	list.push(student);
}

std::ostream& operator<<(std::ostream& os, const roster& src)
{
	os << src.list;
	return os;
}
