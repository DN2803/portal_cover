#pragma once
#include <iostream>
class string
{
private:
	char* s;
	int sz;
public:
	// constructor
	string();
	string(const string& str);
	string(const string& str, size_t pos, size_t len);
	string(const char* s);
	string(char* s, size_t n);


	// desstructor 
	~string();
	// gettor 
	int size();
	// operator =
	string& operator= (const string& str);
	string& operator= (const char* s);
	string& operator= (char c);
	// operator >>
	friend std:: istream& operator>> (std::istream& is, string& str);
	// getline 
	void getline(std::istream& is);
	void getline(std::istream& is, char skip);

	// operator <<
	friend std::ostream& operator<< (std::ostream& os, const string& str);
	bool operator== (const string& other);
};

