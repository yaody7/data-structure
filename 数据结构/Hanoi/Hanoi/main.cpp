#include<iostream>
using namespace std;

void move(int count, int start, int end, int tmp) {
	if (count == 1)
		cout << start << " to " << end << endl;
	else {
		move(count - 1, start, tmp ,end);
		cout << start << " to " << end << endl;
		move(count - 1, tmp, end, start);
	}
}
int main(void) {
	move(3, 1, 3, 2);
}