#include"Sort.h"

void Sort::RadixSort() {
	int key = 0;
	int radix = 1;
	for (int i = 0; i < 3; i++) {
		int tong[10][20];
		int count[10] = { 0 };
		for (int j = 0; j < Len; j++) {
			key = Data[j] / radix % 10;
			tong[key][count[key]++] = Data[j];
		}
		int pos = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < count[j]; k++) {
				this->Data[pos] = tong[j][k];
				pos++;
			}
		}
		Display();
		radix *= 10;
	}
}