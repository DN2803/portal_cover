#include "Student.h"

Student::Student()
{
	id = "";
	name = "";
	birthday;
	address = "";
	
}

Student::Student(string id, string name, Date birth, string address)
{
	this->id = id;
	this->name = name;
	this->birthday = birth;
	this->address = address;
	
}

Student::~Student()
{

}

Student::Student(const Student& student)
{
	id = student.id;
	name = student.name;
	birthday = student.birthday;
	address = student.address;
}

string Student::getID()
{
	return id;
}

std::istream& operator>>(std::istream& is, Student& src)
{
	// TODO: insert return statement here
	if (is.rdbuf() == std::cin.rdbuf()) {
		std::cout << "enter student's id: ";
		is.ignore();
		is >> src.id;
		std::cout << "enter student's name: ";
		src.name.getline(is);
		std::cout << "enter student's birthday: ";
		is >> src.birthday;
		src.birthday.checkdate(); // kiem tra tuoi
		std::cout << "enter student's address: ";
		is.ignore();
		src.address.getline(is);
	}
	else {
		src.id.getline(is, ';');
		src.name.getline(is, ';');
		is >> src.birthday;
		src.address.getline(is, ';');

	}
	

	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& src)
{
	// TODO: insert return statement here
	if (os.rdbuf() == std::cout.rdbuf()) {
		os << std::setw(10) << std::left << src.id;
		os << std::setw(30) << std::left << src.name;
		os << std::setw(15) << std::left << src.birthday;
		os << std::setw(30) << std::left << src.address << std::endl;
	}
	else {
		os << src.id << ";";
		os << src.name << ";";
		os << src.birthday << ";";
		os << src.address << std::endl;
	}
	return os;
}
