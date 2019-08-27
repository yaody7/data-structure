#include"Stack.h"
template<class Stack_entry>
Stack<Stack_entry>::Stack() {
	this->count = 0;
}
template<class Stack_entry>
Stack<Stack_entry>::~Stack() {
	;
}
template<class Stack_entry>
bool Stack<Stack_entry>::empty()const {
	return(count == 0);
}
template<class Stack_entry>
Error_code Stack<Stack_entry>::pop() {
	if (count == 0)
		return underflow;
	count--;
	return success;
}
template<class Stack_entry>
Error_code Stack<Stack_entry>::top(Stack_entry&item)const {
	if (count == 0)
		return underflow;
	item = this->entry[count - 1];
	return success;
}
template<class Stack_entry>
Error_code Stack<Stack_entry>::push(const Stack_entry&item) {
	if (count == maxstack)
		return overflow;
	this->entry[count] = item;
	count++;
	return success;
}