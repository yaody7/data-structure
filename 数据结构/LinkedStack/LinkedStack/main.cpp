enum Error_code
{
	success, overflow, downflow
};
template<class Stack_entry>
class Stack
{
public:
	Stack();
	~Stack();
	bool empty()const;
	Error_code push(const Stack_entry &item);
	Error_code pop();
	Error_code top(Stack_entry &item)const;
	Stack(const Stack&original);
	void operator=(const Stack&original);

protected:
	struct Node
	{
		Stack_entry entry;
		Node*next;
		Node() {
			next = nullptr;
		}
		Node(Stack_entry item, Node*add_on = nullptr) {
			entry = item;
			next = add_on;
		}
		
	};
	Node*top_node;
	
};
template<class Stack_entry>
Stack<Stack_entry>::Stack()
{
	this->top_node = nullptr;
}
template<class Stack_entry>
Stack<Stack_entry>::~Stack()
{
	while (this->top_node != nullptr) {
		Node*fuzhu=this->top_node->next;
		delete this->top_node;
		top_node = fuzhu;
	}
}
template<class Stack_entry>
bool Stack<Stack_entry>::empty()const {
	return (this->top_node == nullptr);
}
template<class Stack_entry>
Error_code Stack<Stack_entry>::push(const Stack_entry &item) {
	Node*charu = new Node(item, top_node);
	this->top_node = charu;
	return success;
}
template<class Stack_entry>
Error_code Stack<Stack_entry>::pop() {
	if (empty())
		return downflow;
	Node*fuzhu = this->top_node;
	this->top_node = this->top_node->next;
	delete fuzhu;
	return success;
}
template<class Stack_entry>
Error_code Stack<Stack_entry>::top(Stack_entry &item)const {
	if (empty())
		return downflow;
	item = this->top_node->entry;
	return success;
}
template<class Stack_entry>
Stack<Stack_entry>::Stack(const Stack&original) {
	Node*old = original.top_node;
	if (old == nullptr)
		this->top_node = nullptr;
	else {
		this->top_node = new Node(old->entry);
		Node*fuzhu = top_node;
		while (old->next != nullptr) {
			old = old->next;
			fuzhu->next = new Node(old->entry);
			fuzhu = fuzhu->next;
		}
	}
}
template<class Stack_entry>
void Stack<Stack_entry>::operator=(const Stack&original) {
	while (!empty())
		pop();
	Node*old = original.top_node;
	if (old == nullptr)
		this->top_node = nullptr;
	else {
		this->top_node = new Node(old->entry);
		Node*fuzhu = top_node;
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
	Stack<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	Stack<int> test1(test);
	Stack<int> test2;
	test2.push(11);
	test2 = test1;
	test.pop();
	test.pop();
	int fuck;
	test.top(fuck);
	cout << fuck;
	test.pop();
	cout << test.pop();

}