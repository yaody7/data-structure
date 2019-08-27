enum Error_code
{
	success, downflow, overflow, range_error
};
template<class List_entry>
class List
{
public:
	List();
	~List();
	int size()const;
	bool full()const;
	bool empty()const;
	void clear();
	void traverse(void(*visit)(List_entry&));
	void insert_sort();
	Error_code retrieve(int position, List_entry&x)const;
	Error_code replace(int position, const List_entry&x);
	Error_code remove(int position, List_entry&x);
	Error_code insert(int position, const List_entry&x);
protected:
	int count;
	List_entry entry[10];
};
template<class List_entry>
void List<List_entry>::insert_sort() {
	for (int unsorted = 1; unsorted < count; unsorted++) {
		int tmp = entry[unsorted];
		int pos;
		if (this->entry[unsorted] > this->entry[unsorted - 1])
			continue;
		else {
			for (int i = 0; i < unsorted; i++) {
				if (entry[i] > tmp) {
					pos = i;
					for (int j = unsorted; j >= i + 1; j--) {
						this->entry[j] = this->entry[j - 1];
					}
					break;
				}
			}
			this->entry[pos] = tmp;
		}
	}
}
template<class List_entry>
List<List_entry>::List()
{
	this->count = 0;
}
template<class List_entry>
List<List_entry>::~List()
{
	;
}
template<class List_entry>
int List<List_entry>::size()const {
	return this->count;
}
template<class List_entry>
bool List<List_entry>::full()const {
	return this->count == 10;
}
template<class List_entry>
bool List<List_entry>::empty()const {
	return this->count == 0;
}
template<class List_entry>
void List<List_entry>::clear() {
	this->count = 0;
}
template<class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry&)) {
	for (int i = 0; i < count; i++)
		visit(this->entry[i]);
}
template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry&x)const {
	if (position < 0)
		return range_error;
	if (position >= count)
		return range_error;
	x = this->entry[position];
	return success;
}
template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry&x) {
	if (position < 0)
		return range_error;
	if (position >= count)
		return range_error;
	this->entry[position] = x;
	return success;
}
template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry&x) {
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
Error_code List<List_entry>::insert(int position, const List_entry&x) {
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
	List<int>test;
	test.insert(0, 1);
	test.insert(0, 3);
	test.insert(1, 2);
	test.insert(2, 9);
	test.insert_sort();
}