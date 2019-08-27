enum Error_code
{
	success, downflow, overflow, range_error,not_present
};
template<class List_entry>
class Ordered_List
{
public:
	Ordered_List();
	~Ordered_List();
	int size()const;
	bool full()const;
	bool empty()const;
	void clear();
	void traverse(void(*visit)(List_entry&));
	Error_code retrieve(int position, List_entry&x)const;
	Error_code replace(int position, const List_entry&x);
	Error_code remove(int position, List_entry&x);
	Error_code insert(const List_entry&x);
	Error_code insert(int position, const List_entry&x);
protected:
	int count;
	List_entry entry[10];
};
template<class List_entry>
Error_code bin(const Ordered_List<List_entry>list, int target, int bottom, int top, int&pos) {
	if (top < bottom)
		return not_present;
	int mid = (bottom + top) / 2;
	int compare;
	list.retrieve(mid, compare);
	if (target == compare) {
		pos = mid;
		return success;
	}
	if (compare < target)return bin(list, target, mid + 1, top, pos);
	return bin(list, target, bottom, mid - 1, pos);

}
template<class List_entry>
Error_code Ordered_List<List_entry>::insert(const List_entry&x) {
	if (full())
		return overflow;
	int i;
	if (x < this->entry[0]) {
		this->insert(0, x);
		return success;
	}
	else {
		for (i = 0; i < count; i++) {
			if (this->entry[i] > x)
				break;
		}
	}
	this->insert(i, x);
	return success;
}
template<class List_entry>
Ordered_List<List_entry>::Ordered_List()
{
	this->count = 0;
}
template<class List_entry>
Ordered_List<List_entry>::~Ordered_List()
{
	;
}
template<class List_entry>
int Ordered_List<List_entry>::size()const {
	return this->count;
}
template<class List_entry>
bool Ordered_List<List_entry>::full()const {
	return this->count == 10;
}
template<class List_entry>
bool Ordered_List<List_entry>::empty()const {
	return this->count == 0;
}
template<class List_entry>
void Ordered_List<List_entry>::clear() {
	this->count = 0;
}
template<class List_entry>
void Ordered_List<List_entry>::traverse(void(*visit)(List_entry&)) {
	for (int i = 0; i < count; i++)
		visit(this->entry[i]);
}
template<class List_entry>
Error_code Ordered_List<List_entry>::retrieve(int position, List_entry&x)const {
	if (position < 0)
		return range_error;
	if (position >= count)
		return range_error;
	x = this->entry[position];
	return success;
}
template<class List_entry>
Error_code Ordered_List<List_entry>::replace(int position, const List_entry&x) {
	if (position < 0)
		return range_error;
	if (position >= count)
		return range_error;
	this->entry[position] = x;
	return success;
}
template<class List_entry>
Error_code Ordered_List<List_entry>::remove(int position, List_entry&x) {
	if (position < 0)
		return range_error;
	if (position >= count)
		return range_error;
	x = this->entry[position];
	for (int i = position; i < count; i++) {
		this->entry[i] = this->entry[i + 1];
	}
	count--;
	return success;
}
template<class List_entry>
Error_code Ordered_List<List_entry>::insert(int position, const List_entry&x) {
	if (position < 0)
		return range_error;
	if (position > count)
		return range_error;
	if (position == count)
		this->entry[count] = x;
	for (int i = count; i >= position + 1; i--) {
		this->entry[i] = this->entry[i - 1];
	}
	count++;
	this->entry[position] = x;
	return success;
}
#include<iostream>
using namespace std;
int main(void) {
	Ordered_List<int>test;
	test.insert(1);
	test.insert(3);
	test.insert(5);
	test.insert(7);
	test.insert(4);
	test.insert(0);
	test.insert(3);
	int fuck;
	cout << bin(test, 3, 0, 6, fuck);
	cout << fuck;
	cout << bin(test, 2, 0, 6, fuck);
	cout << fuck;
}