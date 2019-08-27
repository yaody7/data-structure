#ifndef STACK_H
#define STACK_H
const int maxstack = 10;
enum Error_code
{
	success, overflow, underflow
};
template<class Stack_entry>
class Stack
{
public:
	Stack();
	~Stack();
	bool empty()const;
	Error_code pop();
	Error_code top(Stack_entry &item)const;
	Error_code push(const Stack_entry & item);
private:
	int count;
	Stack_entry entry[maxstack];

};
#endif // !1

