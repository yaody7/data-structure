#include<iostream>
#include<cstdlib>
#include<ctime>
#define LENGTH 20
using namespace std;

class Sort {
public:
	Sort() { Len = 0; }
	void RadixSort();
	void Display();	// 输出数值Data[0..Len-1]中的数据
	void Input(int Num);// 输入Num个待排序的正整数[0,1000]，给定的。
private:
	int Len;
	int Data[LENGTH];
};
