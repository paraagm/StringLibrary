#pragma once

//#ifdef MSC_VER
//
//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996)
//
//#endif // MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include <cstdlib>
#include <cstring>
#include <locale>

class string
{
	char* _str;
	size_t _len;
public:
	string();
	string(const char* c);
	string(const string& s);
	~string();

	const char* get_str () const { return _str; };

	//operators
	string& operator += (const char* rhs);
	const char operator [] (const int index);
	string& operator= (const char* rhs);
	string& operator= (string& rhs);
	
	
	//conditional operations
	bool operator == (const char* rhs);
	bool operator != (const char* rhs);

	//conversion operator
	operator const char* () const;

	//utility functions
	size_t length() const { return _len; }
	void trim_whitespace();
	void to_upper();
	void to_lower();
	void reverse(size_t start, size_t end);
	void reverse_words();

	//find and replace
	size_t find(const char* str, size_t pos = 0) const;
	size_t char_find(const char* chr, size_t pos = 0) const;
	size_t char_find(char chr, size_t pos = 0) const;
	string substr(size_t pos = 0, size_t len = -1) const;

	//modifiers
	void swap(string& swap_str);

private:
	void reset();
	void copy_str(const char* c);
	void allocate_str(size_t len);
	void shift_left_at(size_t pos);
};


