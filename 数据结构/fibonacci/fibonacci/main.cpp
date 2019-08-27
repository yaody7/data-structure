#include<iostream>
using namespace std;
int fibonacci(int count) {
	if (count == 0)return 0;
	if (count == 1)return 1;
	int f1 = 0;
	int f2 = 1;
	int current;
	for (int i = 0; i < count - 1; i++) {
		current = f1 + f2;
		f1 = f2;
		f2 = current;
	}
	return current;
}
int fibonaccirec(int count) {
	if (count == 0)return 0;
	if (count == 1)return 1;
	return fibonacci(count - 1) + fibonacci(count - 2);
}
int main(void) {
	for (int i = 0; i <= 10; i++) {
		cout << fibonacci(i) << ' ';
	}
	cout << endl;
	for (int i = 0; i <= 10; i++) {
		cout << fibonaccirec(i) << ' ';
	}
}