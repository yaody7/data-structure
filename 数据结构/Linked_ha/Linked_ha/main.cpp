#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*next;
	Node() {
		this->data = 0;
		this->next = NULL;
	}
};
enum Error_code
{
	success, fail
};
int bianhua(int x) {
	return x % 5 + 1;
}
class Hash_List
{
public:
	Hash_List();
	~Hash_List();
	Error_code insert(int x);
	Error_code retrieve(int x);

private:
	Node*x[10];
};

Hash_List::Hash_List()
{
	for (int i = 0; i < 10; i++) {
		x[i] = NULL;
	}
}

Hash_List::~Hash_List()
{
	for (int i = 0; i < 10; i++) {
		Node*fuzhu = x[i];
		while (fuzhu != NULL) {
			Node*tmp = fuzhu->next;
			delete fuzhu;
			fuzhu = tmp;
		}
	}
}
Error_code Hash_List::insert(int x) {
	int pos = bianhua(x);
	Node*fuzhu = this->x[pos];
	if (fuzhu == NULL)
	{
		this->x[pos] = new Node;
		this->x[pos]->data = x;
		return success;
	}
	while (fuzhu->next != NULL) {
		if (fuzhu->data == x)
			return fail;
		fuzhu = fuzhu->next;
	}
	fuzhu->next = new Node;
	fuzhu->next->data = x;
	return success;
}
Error_code Hash_List::retrieve(int x) {
	int pos = bianhua(x);
	Node*fuzhu = this->x[pos];
	while (fuzhu != NULL) {
		if (fuzhu->data == x)
			return success;
		fuzhu = fuzhu->next;
	}
	return fail;
}
int main(void) {
	Hash_List test;
	test.insert(1);
	test.insert(6);
	test.insert(1);
	test.insert(2);
	test.retrieve(1);
	test.retrieve(3);
}