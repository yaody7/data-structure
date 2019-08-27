/*三种实现循环列表方法：
1.	空位
2.	标志
3.	特殊值
*/
enum Error_code
{
	overflow,downflow,success
};
template<class Queue_entry>
class Queue
{
public:
	Queue();
	~Queue();
	Error_code append(const Queue_entry &x);
	Error_code serve();
	Error_code retrieve(Queue_entry &x);
	bool isFull();
	bool isEmpty();
private:
	Queue_entry entry[10];
	int front;
	int rear;
};
template<class Queue_entry>
bool Queue<Queue_entry>::isEmpty() {
	if (this->front - this->rear == 1)
		return true;
	if (this->front - this->rear == -9)
		return true;
	return false;
}
template<class Queue_entry>
bool Queue<Queue_entry>::isFull() {
	if (this->front - this->rear == 2)
		return true;
	if (this->front - this->rear == -8)
		return true;
	return false;
}
template<class Queue_entry>
Queue<Queue_entry>::Queue()
{
	this->rear = -1;
	this->front = 0;
}
template<class Queue_entry>
Queue<Queue_entry>::~Queue()
{
	;
}
template<class Queue_entry>
Error_code Queue<Queue_entry>::append(const Queue_entry &x) {
	if (isFull())
		return overflow;
	rear++;
	if (rear >= 10)
		rear -= 10;
	this->entry[rear] = x;
	return success;
}
template<class Queue_entry>
Error_code Queue<Queue_entry>::serve() {
	if (isEmpty())
		return downflow;
	front++;
	if (front >= 10)
		front -= 10;
	return success;

}
template<class Queue_entry>
Error_code Queue<Queue_entry>::retrieve(Queue_entry&x) {
	if (isEmpty())
		return downflow;
	x = this->entry[front];
	return success;
}
#include<iostream>
using namespace std;
int main(void) {
	Queue<int>test;
	for (int i = 0; i < 9; i++)
		test.append(i);
	cout << test.append(3);
	cout << test.serve();
	int fuck;
	cout << test.retrieve(fuck);
	cout << fuck;
	cout << test.append(11);
	cout << test.append(12);
	cout << test.serve();
	cout << test.append(13);
	for (int i = 0; i < 9; i++)
		test.serve();
	cout << test.isEmpty();
}