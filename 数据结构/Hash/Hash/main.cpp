#include<iostream>
using namespace std;
int bianhua(int x) {
	return x % 5 + 1;
}
enum Error_code
{
	success, fail
};
class Hash_table{
public:
	Hash_table();
	void clear();
	Error_code insert(int);
	Error_code retrieve(int);
private:
	int table[10];
};
Hash_table::Hash_table() {
	for (int i = 0; i < 10; i++) {
		this->table[i] = -1;
	}
}
void Hash_table::clear() {
	for (int i = 0; i < 10; i++){
		this->table[i] = -1;
	}
}
Error_code Hash_table::retrieve(int x) {
	int probecount = 0;
	int probe = bianhua(x);
	while (table[probe] != x && probecount < (10 + 1 / 2)) {
		probe += 2;
		probecount++;
	}
	if (table[probe] == x)
		return success;
	return fail;
}
Error_code Hash_table::insert(int x) {

	int probecount = 0;
	int probe= bianhua(x);
	while (table[probe] != -1 && table[probe] != x && probecount < (10+ 1 / 2)) {
		probecount++;
		probe += 2;
	}
	if (table[probe] == -1) {
		table[probe] = x;
		return success;
	}
	return fail;

}
int main(void) {
	Hash_table test;
	test.insert(1);
	test.insert(6);
	test.insert(11);
	test.insert(12);
	test.insert(1231);
	test.retrieve(1);
	test.retrieve(3);
}