#include<iostream>
#include<cstdlib>
#include<ctime>
#define LENGTH 20
using namespace std;

class Sort {
public:
	Sort() { Len = 0; }
	void RadixSort();
	void Display();	// �����ֵData[0..Len-1]�е�����
	void Input(int Num);// ����Num���������������[0,1000]�������ġ�
private:
	int Len;
	int Data[LENGTH];
};
