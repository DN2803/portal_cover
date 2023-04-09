#include "string.h"

string::string()
{
	s = nullptr;
	sz = 0;
}

string::string(const char* src)
{
	sz = 0;
	while (src[sz] != '\0') {
		sz++;
	}
	s = new char[sz + 1];
	for (int i = 0; i < sz; i++) {
		s[i] = src[i];
	}
	s[sz] = '\0';
}

string::string(char* str, size_t n)
{
	s = str;
	sz = n;
}

string::string(const string& str)
{
	s = str.s;
	sz = str.sz;
}

string::string(const string& str, size_t pos, size_t len)
{
	s = &str.s[pos];
	sz = len;
}

string::~string()
{
	if (sz > 0) {
		delete[]s;
		s = nullptr;
		sz = 0;
	}
}
int string::size()
{
	return sz;
}

string& string::operator=(const string& str)
{
	sz = str.sz;
	s = new char[sz + 1];
	for (int i = 0; i < sz; i++) {
		s[i] = str.s[i];
	}
	s[sz] = '\0';
	return *this;
}

string& string::operator=(const char* src)
{
	sz = 0;
	while (src[sz] != '\0') {
		sz++;
	}
	s = new char[sz + 1];
	for (int i = 0; i < sz; i++) {
		s[i] = src[i];
	}
	s[sz] = '\0';
	return *this;
}

string& string::operator=(char c)
{
	sz = 1;
	s = new char;
	s[0] = c;
	return *this;
}
std::istream& operator >> (std::istream& is, string& str)
{
	char* s = nullptr;
	char c;
	int sz = 0;
	
	is.get(c);
	while (c != ' ' && c != '\n') {
		char* temp = new char[sz + 2];
		for (int i = 0; i < sz; i++) {
			temp[i] = s[i];
		}
		temp[sz] = c;
		temp[sz + 1] = '\0';
		delete[]s;
		s = temp;
		++sz;
		is.get(c);
		
	}
	string temp(s, sz);
	str = temp;
	return is;
}
std::ostream& operator<<(std::ostream& os, const string& str)
{
	// TODO: insert return statement here
	int i = 0;
	while (str.s[i] != '\0') {
		os << str.s[i];
		i++;
	}
	return os;
}
void string::getline(std::istream& is)
{
	char* s = nullptr;
	char c;
	int sz = 0;
	
	is.get(c);
	while (c != '\n') {
		char* temp = new char[sz + 2];
		for (int i = 0; i < sz; i++) {
			temp[i] = s[i];
		}
		temp[sz] = c;
		temp[sz+1] = '\0';
		delete[]s;
		s = temp;
		++sz;
		is.get(c);
	}
	string temp(s, sz);
	*this = temp;
}

void string::getline(std::istream& is, char skip)
{
	char* s = nullptr;
	char c;
	int sz = 0;

	is.get(c);
	while (c != '\n' && c != skip ) {
		char* temp = new char[sz + 2];
		for (int i = 0; i < sz; i++) {
			temp[i] = s[i];
		}
		temp[sz] = c;
		temp[sz + 1] = '\0';
		delete[]s;
		s = temp;
		++sz;
		if(!is.get(c)) break;
	}
	string temp(s, sz);
	*this = temp;
}

bool string::operator==(const string& other)
{
	if (sz != other.sz) return false;
	else {
		for (int i = 0; i < sz; i++) {
			if (s[i] != other.s[i]) return false;
		}
	}
	return true;
}
