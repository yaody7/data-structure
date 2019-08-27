enum Error_code
{
	success, downflow, overflow,range_error
};
template<class List_entry>
class List
{
public:
	List();
	~List();
	void insert_heap(List_entry x, int low, int high);
	void build_heap();
	void heap_sort(int low, int high);
	int size()const;
	bool full()const;
	bool empty()const;
	void clear();
	void traverse(void(*visit)(List_entry&));
	void quick();
	void swap(int first, int second);
	int partition(int low, int high);
	void quick_sort(int low, int high);
	void selection_sort();
	void shell_sort();
	void insert_sort(List_entry**,int size);
	int find_max(int bottom, int top);
	Error_code retrieve(int position, List_entry&x)const;
	Error_code replace(int position, const List_entry&x);
	Error_code remove(int position, List_entry&x);
	Error_code insert(int position, const List_entry&x);
protected:
	int count;
	List_entry entry[10];
};
template<class List_entry>
void List<List_entry>::insert_heap(List_entry x, int low, int high) {
	int large = 2 * low + 1;
	while (large <= high) {
		if (large<high&&this->entry[large + 1] > this->entry[large])
			large++;
		if (this->entry[large] < x) {
			this->entry[low] = x;
			return;
		}
		else {
			this->entry[low] = this->entry[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	this->entry[low] = x;
}
template<class List_entry>
void List<List_entry>::build_heap() {
	for (int i = this->count / 2 - 1; i >= 0; i--)
		this->insert_heap(this->entry[i], i, count-1);
}
template<class List_entry>
void List<List_entry>::heap_sort(int low, int high) {
	build_heap();
	for (int unsorted = high; unsorted > 0; unsorted--) {
		int current = this->entry[unsorted];
		this->entry[unsorted] = this->entry[low];
		insert_heap(current,low, unsorted-1 );
	}
}
template<class List_entry>
void List<List_entry>::swap(int first, int second) {
	List_entry tmp = this->entry[first];
	this->entry[first] = this->entry[second];
	this->entry[second] = tmp;
}
template<class List_entry>
int List<List_entry>::partition(int low, int high) {
	swap(low, (low + high) / 2);
	int lastsmall = low;
	for (int i = low + 1; i <= high; i++) {
		if (this->entry[i] < this->entry[low]) {
			lastsmall++;
			swap(lastsmall, i);
		}
	}
	swap(low, lastsmall);
	return lastsmall;
}
template<class List_entry>
void List<List_entry>::quick_sort(int low, int high) {
	if (low >= high)
		return;
	int pivot = partition(low, high);
	quick_sort(low, pivot - 1);
	quick_sort(pivot + 1, high);
}
template<class List_entry>
void List<List_entry>::quick() {
	quick_sort(0, count-1);
}
template<class List_entry>
void List<List_entry>:: insert_sort(List_entry** x, int size) {
	int sorted = 0;
	int unsort = 1;
	for (int i = unsort; i < size; i++) {
		if (*(x[unsort]) > *(x[sorted])) {
			sorted++;
			unsort++;
			continue;
		}
		for (int j = 0; j < unsort; j++) {
			if (*(x[j]) > *(x[unsort])) {
				List_entry tmp = *(x[unsort]);
				for (int k = unsort; k >= j + 1; k--) {
					*(x[k]) = *(x[k - 1]);
				}
				*(x[j]) = tmp;
				break;
			}
		}
		sorted++;
		unsort++;
	}
}
template <class List_entry>
void List<List_entry>::shell_sort() {
	int increament = this->count/3+1;
	for (1; increament >= 1; increament =increament /3+1) {
		for (int i = 0; i < increament; i++) {
			List_entry* *x= new List_entry*[this->count];
			int size = 0;
			int tmp = i;
			while (tmp < count) {
				x[size] = &(this->entry[tmp]);
				size++;
				tmp += increament;
			}
			this->insert_sort(x, size);
			delete x;
		}
		if (increament == 1)
			break;
	}
}
template <class List_entry>
int List<List_entry>::find_max(int bottom, int top) {
	int answer = this->entry[0];
	int pos = 0;
	for (int i = bottom; i <= top; i++) {
		if (answer < entry[i]) {
			answer = entry[i];
			pos = i;
		}
	}
	return pos;
}
template<class List_entry>
void List<List_entry>::selection_sort() {
	for (int i = count - 1; i > 0; i--) {
		int pos = this->find_max(0, i);
		int tmp = this->entry[i];
		this->entry[i] = this->entry[pos];
		this->entry[pos] = tmp;
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
	test.insert(0, 9);
	test.insert(1, 1);
	test.insert(2, 3);
	test.insert(3, 2);
	test.heap_sort(0, 3);
 }