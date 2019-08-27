
#include"Stack.h"
#include<iostream>
using namespace std;

int main(void) {
	Stack<int> test;
	test.push(1);
	int fuck;
	test.top(fuck);
	cout << fuck;
	test.pop();
	test.push(2);
	test.top(fuck);
	cout << fuck;
	test.pop();
	cout << test.pop();
}
