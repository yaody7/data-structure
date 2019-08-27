#include"Sort.h"

void Sort::Display() {
	for (int i = 0; i < Len; i++) {
		cout << Data[i] << " ";
	}
	cout << endl;
}

void Sort::Input(int Num) {
	if (Num > LENGTH - 1 || Num < 1) return;
	Len = Num;
	for (int i = 0; i < Num; i++) cin >> Data[i];
}

int main() {
	int Num;
	Sort Test;
	cin >> Num;
	Test.Input(Num);
	Test.Display();
	Test.RadixSort();
	return 0;
}