enum Error_code
{
	success,overflow,downflow
};
template<class Queue_entry>
class Queue
{
public:
	Queue();
	~Queue();
	bool empty()const;
	Error_code append(const Queue_entry&item);
	Error_code serve();
	Error_code retrieve(Queue_entry &item)const;
	Queue(const Queue&original);
	void operator=(const Queue&original);

protected:
	struct Node
	{
		Queue_entry entry;
		Node*next;
		Node() {
			next = nullptr;
		}
		Node(Queue_entry item, Node*add_on = nullptr) {
			entry = item;
			next = add_on;
		}

	};
	Node*front, *rear;

};
template<class Queue_entry>
Queue<Queue_entry>::Queue()
{
	this->front = nullptr;
	this->rear = front;
}
template<class Queue_entry>
Queue<Queue_entry>::~Queue()
{
	while(!empty())
		this->serve();
}
template<class Queue_entry>
bool Queue<Queue_entry>::empty()const {
	return this->front == rear;
}
template<class Queue_entry>
Error_code Queue<Queue_entry>::append(const Queue_entry&item) {
	if (this->front == nullptr) {
		this->front = new Node(item);
		this->rear = this->front;
	}
	else {
		this->rear->next = new Node(item);
		this->rear = this->rear->next;
	}
	return success;
}
template<class Queue_entry>
Error_code Queue<Queue_entry>::serve() {
	if (empty())
		return downflow;
	else {
		Node*fuzhu = this->front;
		this->front = this->front->next;
		delete fuzhu;
	}
}
template<class Queue_entry>
Error_code Queue<Queue_entry>::retrieve(Queue_entry &item)const {
	if (empty())
		return downflow;
	else {
		item = *this->front;
		return success;
	}
}
template<class Queue_entry>
Queue<Queue_entry>::Queue(const Queue&original) {
	Node*old = original.front;
	if (old == nullptr) {
		this->front = nullptr;
		this->rear = nullptr;
	}
	else {
		this->front = new Node(old->entry);
		this->rear = this->front;
		Node*fuzhu = this->rear;
		while (old->next != nullptr) {
			old = old->next;
			fuzhu->next = new Node(old->entry);
			fuzhu = fuzhu->next;
		}
	}
}
template<class Queue_entry>
void Queue<Queue_entry>::operator=(const Queue&original) {
	while (!empty())
		serve();
	Node*old = original.front;
	if (old == nullptr) {
		this->front = nullptr;
		this->rear = nullptr;
	}
	else {
		this->front = new Node(old->entry);
		this->rear = this->front;
		Node*fuzhu = this->rear;
		while (old->next != nullptr) {
			old = old->next;
			fuzhu->next = new Node(old->entry);
			fuzhu = fuzhu->next;
		}
	}
}
#include<iostream>
using namespace std;
int main(void) {
	Queue<int>test;
	test.append(1);
	test.append(2);
	test.append(3);
	Queue<int>test1(test);
	Queue<int>test2;
	test2.append(11);
	test2 = test1;
}