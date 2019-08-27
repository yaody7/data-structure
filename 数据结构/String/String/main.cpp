#include<iostream>
#include<list>
using namespace std;
class String
{
public:
	String();
	~String();
	String(const String&copy);
	String(const char*copy);
	String(list<char>&copy);
	void operator=(const String &copy);
	const char*c_str()const;
private:
	char*entries;
	int length;
};

String::String()
{
	this->entries = NULL;
	this->length = 0;
}

String::~String()
{
	delete this->entries;
	this->length = 0;
	this->entries = NULL;
}
String ::String(const String&copy) {
	this->length = copy.length;
	this->entries = new char[this->length+1];
	for (int i = 0; i < this->length; i++)
		this->entries[i] = copy.entries[i];
	this->entries[this->length] = 0;
}
String::String(const char*copy) {
	this->length = strlen(copy);
	this->entries = new char[this->length+1];
	for (int i = 0; i < this->length; i++) {
		this->entries[i] = copy[i];
	}
	this->entries[this->length] = 0;
}
String::String(list<char>&copy) {
	this->length = copy.size();
	this->entries = new char[this->length+1];
	int i = 0;
	for (list<char>::iterator ite = copy.begin(); ite != copy.end(); ite++) {
		this->entries[i] = *ite;
		i++;
	}
	this->entries[this->length] = 0;
}
void String::operator=(const String &copy) {
	this->length = copy.length;
	this->entries = new char[this->length+1];
	for (int i = 0; i < this->length; i++) {
		this->entries[i] = copy.entries[i];
	}
	this->entries[this->length] = 0;
}
const char*String::c_str()const {
	char*answer = new char[this->length];
	for (int i = 0; i < this->length; i++) {
		answer[i] = this->entries[i];
	}
	return answer;
}
bool operator==(const String &first, const String&second) {
	if (strlen(first.c_str()) != strlen(second.c_str()))
		return false;
	for (int i = 0; i < strlen(first.c_str()); i++) {
		if (first.c_str()[i] != second.c_str()[i])
			return false;
	}
	return true;
}
bool operator>(const String &first, const String&second) {
	int count = 0;
	if (strlen(first.c_str()) > strlen(second.c_str())) {
		count = strlen(second.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] > second.c_str()[i])
				return true;
		}
		return false;
	}
	else {
		count = strlen(first.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] < second.c_str()[i])
				return false;
		}
		return true;
	}
	
}
bool operator<(const String &first, const String&second) {
	int count = 0;
	if (strlen(first.c_str()) > strlen(second.c_str())) {
		count = strlen(second.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] > second.c_str()[i])
				return true;
		}
		return false;
	}
	else {
		count = strlen(first.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] < second.c_str()[i])
				return false;
		}
		return true;
	}
}
bool operator>=(const String &first, const String&second) {
	if (first == second)
		return true;
	int count = 0;
	if (strlen(first.c_str()) > strlen(second.c_str())) {
		count = strlen(second.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] > second.c_str()[i])
				return true;
		}
		return false;
	}
	else {
		count = strlen(first.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] < second.c_str()[i])
				return false;
		}
		return true;
	}
}
bool operator<=(const String &first, const String&second) {
	if (first == second)
		return true;
	int count = 0;
	if (strlen(first.c_str()) > strlen(second.c_str())) {
		count = strlen(second.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] > second.c_str()[i])
				return true;
		}
		return false;
	}
	else {
		count = strlen(first.c_str());
		for (int i = 0; i < count; i++) {
			if (first.c_str()[i] < second.c_str()[i])
				return false;
		}
		return true;
	}
}
bool operator!=(const String &first, const String&second) {
	return (!(first == second));
}
int main(void) {
	String test("fuck");
	String test1(test);
	String test3 = test1;
	list<char>fuzhu;
	fuzhu.insert(fuzhu.begin(), 'a');
	String test4(fuzhu);
	cout << (test > test4);
}