#include "string.h"
#include "vector.h"
#include "Student.h"
#include "Course.h"
#include "registrar.h"
#include <iostream>
#include <fstream>



int main()
{
	vector<Student> students;
	vector<Course> courses;
	while (true)
	{
		std::cout << "1. enter list of courses" << std::endl;
		std::cout << "2. read infomation of students from file " << std::endl;
		std::cout << "3. write list student to file " << std::endl;
		std::cout << "4. print list students of course " << std::endl;
		std::cout << "5. print schedule of student " << std::endl;
		std::cout << "YOUR CHOICE: ";
		int choose;
		std::cin >> choose;
		switch (choose)
		{
		case 1: {
			std::cout << "1. enter list of courses" << std::endl;
			while (true) {
				std::cout << "enter infomation of course: " << std::endl;
				std::cout << "press 0 to exit." << std::endl;
				std::cout << "press 1 to continue" << std::endl;
				
				int key;
				std::cin >> key;
				if (key == 0) break;
				else {
					Course course;
					std::cin >> course;
					courses.push(course);
				}
			}
			break;
		}
		case 2: {
			std::cout << "2. read infomation of students from file " << std::endl;
			std::cout << "enter file's name you want to read: ";
			char filename[50];
			std::cin.ignore();
			std::cin.getline(filename, 50);
			std::ifstream fin;
			fin.open(filename, std::ios::in);
			if (!fin.is_open()) {
				std::cout << "couldn't open file" << std::endl;
				return 0;
			}
			while (!fin.eof()) {
				Student temp;
				fin >> temp;
				students.push(temp);
			}
			fin.close();
			break;
		}
		case 3: {
			std::cout << "3. write list student to file " << std::endl;

			std::cout << "enter file's name you want to write: ";
			char filename[50];
			std::cin.ignore();
			std::cin.getline(filename, 50);
			std::ofstream fout;
			fout.open(filename, std::ios::out);
			if (!fout.is_open()) {
				std::cout << "couldn't open file" << std::endl;
				return 0;
			}
			for (int i = 0; i < students.size(); i++) {
				fout << students[i];
			}
			fout.close();
			break;
		}
		case 4: {
			std::cout << "4. print list students of course " << std::endl;
			break;
		}
		case 5: {
			std::cout << "5. print schedule of student " << std::endl;
			break;
		}
		case 0: {
			/*std::cout << "register:" << std::endl;
			std::cout << "enter student's id: ";
			string id;
			std::cin >> id;
			Student regis;
			for (int i = 0; i < students.size(); i++) {
				if (students[i].getID() == id) regis = students[i];

			}*/
			
		}
		default:
			break;
		}
	}
	

	return 0;
}