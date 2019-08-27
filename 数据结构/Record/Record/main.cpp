#include<iostream>
using namespace std;
class Key {
public:
	int const get_data() const {
		return this->data;
	}
	void set_data(int x) {
		this->data = x;
	}
private:
	int data;
};
class Record {
public:
	Record(int data) {
		this->data = data;
	}
	operator Key() {
		this->key.set_data(data);
		return key;
	}
private:
	int data;
	Key key;
};
bool operator ==(const Key&one, const Key&two) {
	return one.get_data() == two.get_data();
}
int main(void) {
	Record test(1);
	Key test1;
	Key test3;
	cout<<(test == test3);
	cout << (test3 == test);
}