#include "string.h"

string::string()
{
	reset();
}

string::~string()
{
	reset();
}

string::string(const char* str)
{
	this->copy_str(str);
}

string::string(const string& str)
{
	copy_str(str);
}

void string::copy_str(const char* source_str)
{
	size_t len = strlen(source_str);
	allocate_str(len);
	strcpy(_str, source_str);
}

void string::allocate_str(size_t len)
{
	if (_str != nullptr) delete _str;
	_str = new char[len + 1]();
	_len = len;
}

void string::reset()
{
	if (_str != nullptr) delete _str ;
	_str = nullptr;
	_len = 0;
}

string& string::operator+= (const char* rhs)
{
	if (rhs) {
		size_t rhs_len = strlen(rhs);
		size_t new_len = _len + rhs_len;
		char* buf = new char[new_len + 1]();
		memcpy(buf, _str, _len);
		memcpy(buf + _len, rhs, rhs_len);
		copy_str(buf);
		delete buf;
	}
	return *this;
}

const char string::operator[] (const int index)
{
	if (index < 0) return 0;
	if (index > _len) return 0;
	return _str[index];
}

string& string::operator= (const char*  rhs)
{
	copy_str(rhs);
	return *this;
}

string& string::operator= (string&  rhs)
{
	copy_str(rhs);
	return *this;
}

string::operator const char* () const
{
	return this->get_str();
}

bool string::operator==(const char* rhs)
{
	if (rhs) {
		if(strcmp(this->_str, rhs)==0) return 1;
		else return 0;
	}
	return 0;
}

bool string::operator!=(const char* rhs)
{
	if (rhs) {
		if (strcmp(this->_str, rhs) != 0) return 1;
		else return 0;
	}
	return 0;
}

void string::trim_whitespace()
{
	const char* whitespaces = "\t\r\v\x20\x1b";
	if (!_len) return;
	const char* c = strchr(_str, whitespaces[0]);
	for(int i=0; whitespaces[i]!='\0';i++)
		while (c) {
			shift_left_at(c - _str);
			c = strchr(_str, whitespaces[i]);
		}
}

void string::to_upper()
{
	if (!_len) return;
	char* c = _str;
	while (*c = toupper(*c)) c++;
}

void string::to_lower()
{
	if (!_len) return;
	char* c = _str;
	while (*c = tolower(*c)) c++;
}

void string::reverse_words()
{
	const char* whitespaces = "\t ";
	const char* wpos;
	size_t start = 0;
	size_t i;
	for ( i = 0; _str[i]; i++) {
		if (isalpha(_str[i])) {
			start = i;
			break;
		}
	}
	for (; _str[i]; i++) {
		if (!isalpha(_str[i])) {
			reverse(start, i);
			start = i+1;
		}
	}
}

void string::reverse(size_t start, size_t end)
{
	char temp;
	while (start < --end) {
		temp = _str[start];
		_str[start] = _str[end];
		_str[end] = temp;
		start++;
	}
}

void string::shift_left_at(size_t pos)
{
	char* start = _str;
	start = start + pos;
	while (*start = *(start + 1)) start++;
	_len--;
}

size_t string::find(const char* str, size_t pos) const
{
	if (str) {
		const char* p_str = _str;
		const char* s_str = str;
		const char* a;
		p_str += pos;
		for (; *p_str; p_str++) {
			if (*p_str == *s_str) {
				a = p_str;
				while (1)
				{
					p_str++; s_str++;
					if (!*s_str) return a-_str;
					if (*p_str != *s_str) break;
				}
				s_str = str;
			}
		}
	}
	return -1;
}

size_t string::char_find(const char* chr, size_t pos) const
{
	if (chr) {
		const char* c = strchr((_str + pos), *chr);
		if (*c) return c - _str + 1;
	}
	return -1;
}

size_t string::char_find(char chr, size_t pos) const
{
	if (chr) {
		return this->char_find(&chr);
	}
	return -1;
}

string string::substr(size_t pos, size_t len) const
{
	size_t strlen = _len - pos;
	if (len != -1) {
		if (pos + len < _len) strlen = len;
		else strlen = len;
	}
	string retstr;
	if (!_str) return retstr;
	char* buf = new char[strlen + 1]();
	memcpy(buf, _str + pos, strlen);
	retstr = buf;
	delete buf;
	return retstr;
}

void string::swap(string& swap_str)
{
	if (!_len) return;
	if (!swap_str) return;
	string temp = *this;
	*this = swap_str;
	swap_str = temp;
}