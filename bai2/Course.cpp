#include "Course.h"

std::istream& operator>>(std::istream& is, Course& src)
{
    if (is.rdbuf() == std::cin.rdbuf()) {
        std::cout << "enter course's id: ";
        is.ignore();
        is >> src.id;
        std::cout << "enter course's name: ";
        src.name.getline(is);
        std::cout << "enter course's opening: ";
        is >> src.open;
        return is;
    }
    else {
        src.id.getline(is);
        src.name.getline(is);
        is >> src.open;
    }
    

}

std::ostream& operator<<(std::ostream& os, const Course& src)
{
    // TODO: insert return statement here
    if (os.rdbuf() == std::cout.rdbuf()) {
        os << std::setw(10) << std::left << src.id;
        os << std::setw(30) << std::left << src.name;
        os << std::setw(15) << std::left << src.open << std::endl;
    }
    else {
        os << src.id << std::endl;
        os << src.name << std::endl;
        os << src.open << std::endl;
    }
    return os;
}

Course::Course()
{
}

Course::Course(string id, string name, Date date)
{ 
    this->id = id;
    this->name = name;
    this->open = date;
}

Course::~Course()
{
}

//void Course::print()
//{
//    std::cout << "student list of the course " << name << std::endl;
//    std::cout << info;
//}

