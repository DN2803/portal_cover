#include "schedule.h"
schedule::schedule()
{
	list;
}
int schedule::size()
{
	return list.size();
}

void schedule::push(Course course)
{
	list.push(course);
}

std::ostream& operator<<(std::ostream& os, const schedule& src)
{
	// TODO: insert return statement here
	return os;
}
