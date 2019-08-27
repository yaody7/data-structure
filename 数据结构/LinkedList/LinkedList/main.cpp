enum Error_code
{
	success,overflow,downflow,range_error
};
template<class Node_entry>
struct Node
{
	Node_entry entry;
	Node<Node_entry>*back, *next;
	Node() {
		this->back = nullptr;
		this->next = nullptr;
	}
	Node(Node_entry item, Node<Node_entry>*link_back = nullptr,
		Node<Node_entry>*link_next = nullptr) {
		this->entry = item;
		this->back = link_back;
		this->next = link_next;
	}
};
template<class List_entry>
class List {
public:
	List();
	List(const List&other);
	~List();
	Error_code clear();
	Error_code insert(int position, const List_entry&item);
	Error_code remove(int position, List_entry&item);
	Error_code retrieve(int position, List_entry&item);
	Error_code replace(int position, const List_entry&item);
	void big_merge();
	void insert_sort();
	void shell_sort();
	Node<List_entry>* merge_sort(Node<List_entry>*x);
	Node<List_entry>* merge(Node<List_entry>*first, Node<List_entry>*second);
	void insert_sort(Node<List_entry>**, int size);
	Node<List_entry>* find_max(Node<List_entry>*end);
	void selection_sort();
	bool empty()const;
	bool full()const;
	int size()const;
	void operator=(const List&other);
protected:
	int count;
	void set_position(int pos)const;
	mutable int current_position;
	mutable Node<List_entry>*current;
};
template<class List_entry>
void List<List_entry>::big_merge() {
	this->set_position(0);
	this->merge_sort(this->current);
}
template<class List_entry>
Node<List_entry>* List<List_entry>::merge(Node<List_entry>*first, Node<List_entry>*second) {
	if (first ==nullptr)
		return second;
	if (second == nullptr)
		return first;
	Node<List_entry>*answer = first;
	Node<List_entry>*fuzhu = second;
	Node<List_entry>*tmp = fuzhu->next;
	while (fuzhu != nullptr) {
		Node<List_entry>*pos = first;
		if (pos->entry > fuzhu->entry) {
			fuzhu->next = first;
			first->back = fuzhu;
			fuzhu->back = nullptr;
			first = fuzhu;
			answer = first;
			fuzhu = tmp;
			if (fuzhu != nullptr)
				tmp = tmp->next;
			continue;
		}
		else {
			while (pos != nullptr) {
				if (pos->entry > fuzhu->entry) {
					fuzhu->back = pos->back;
					pos->back->next = fuzhu;
					fuzhu->next = pos;
					pos->back = fuzhu;
					fuzhu = tmp;
					if (fuzhu != nullptr)
						tmp = tmp->next;
					break;
				}
				if (pos->next == nullptr) {
					pos->next = fuzhu;
					fuzhu->next = nullptr;
					fuzhu->back = pos;
					fuzhu = tmp;
					if (fuzhu != nullptr)
						tmp = tmp->next;
					break;
				}
				pos = pos->next;
			}

		}
	}
	return answer;
}
template <class List_entry>
Node<List_entry>* List<List_entry>::merge_sort(Node<List_entry>*x) {
	if (x == nullptr || x->next == nullptr)
		return x;
	else {
		Node<List_entry>*fuzhu = x;
		Node<List_entry>*fuzhu1 = x->next;
		while (fuzhu1!=nullptr&&fuzhu1->next != nullptr) {
			fuzhu = fuzhu->next;
			fuzhu1 = fuzhu1->next->next;
		}
		Node<List_entry>*first = x;
		Node<List_entry>*second = fuzhu->next;
		fuzhu->next = nullptr;
		first=merge_sort(first);
		second=merge_sort(second);
		x=merge(first, second);
	}
	current = x;
	this->current_position = 0;
	return x;
}
template<class List_entry>
void List<List_entry>::shell_sort() {
	int increament = this->count / 3 + 1;
	for (; increament >= 1; increament = increament / 3 + 1) {
		for (int i = 0; i < increament; i++) {
			Node<List_entry>**x = new Node<List_entry>*[this->count];
			int size = 0;
			int tmp = i;
			while (tmp < this->count) {
				this->set_position(tmp);
				x[size] = current;
				tmp += increament;
				size++;
			}
			insert_sort(x, size);
			delete x;
		}
		if (increament == 1)
			break;
	}
}
template<class List_entry>
void List<List_entry>::insert_sort(Node<List_entry>**x, int size) {
	int sorted = 0;
	int unsort = 1;
	for (; unsort < size; unsort++) {
		if (x[unsort]->entry > x[sorted]->entry) {
			sorted++;
			continue;
		}
		else {
			for (int i = 0; i <= sorted; i++) {
				if (x[i]->entry > x[unsort]->entry) {
					List_entry tmp = x[unsort]->entry;
					for (int j = unsort; j >= i + 1; j--) {
						x[j]->entry = x[j - 1]->entry;
					}
					x[i]->entry = tmp;
					sorted++;
					break;
				}
			}
		}
	}
}
template <class List_entry>
Node<List_entry>* List<List_entry>::find_max(Node<List_entry>*end) {
	this->set_position(0);
	Node<List_entry>*pos = current;
	Node<List_entry>*answer = current;
	while (pos != end->next) {
		if (pos->entry > answer->entry) {
			answer = pos;
		}
		pos = pos->next;
	}
	return answer;
}
template <class List_entry>
void List<List_entry>::selection_sort() {
	set_position(count - 1);
	Node<List_entry>*fuzhu = current;
	while (fuzhu->back != nullptr) {
		Node<List_entry>*max = this->find_max(fuzhu);
		int tmp = fuzhu->entry;
		fuzhu->entry = max->entry;
		max->entry = tmp;
		fuzhu = fuzhu->back;
	}
}
template<class List_entry>
void List<List_entry>::insert_sort() {
	this->set_position ( 0);
	Node<List_entry>*unsort = current->next;
	Node<List_entry>*sorted = current;
	Node<List_entry>*head = current;
	for (int i = 1; i < count; i++) {
		if (unsort->entry > sorted->entry)
			continue;
		else {
			Node<List_entry>*pos = head;
			while (pos->entry < unsort->entry) {
				pos = pos->next;
			}
			unsort->back->next = unsort->next;
			if (unsort->next != nullptr)
				unsort->next->back = unsort->back;
			if (pos == head) {
				head->back = unsort;
				unsort->next = head;
				unsort->back = nullptr;
				head = unsort;
			}
			else {
				pos->back->next = unsort;
				unsort->next = pos;
				unsort->back = pos->back;
				pos->back = unsort;
			}

		}
		this->current = head;
		this->current_position = 0;
		unsort = sorted->next;
	}
}
template<class List_entry>
void List<List_entry>::operator=(const List&other) {
	this->clear();
	this->count = 0;
	this->current_position = 0;
	this->current = nullptr;
	other.set_position(0);
	Node<List_entry>*fuzhu = other.current;
	while (fuzhu != nullptr) {
		this->insert(count, fuzhu->entry);
		fuzhu = fuzhu->next;
	}
}
template<class List_entry>
List<List_entry>::List(const List&other) {
	this->count = 0;
	this->current_position = 0;
	this->current = nullptr;
	other.set_position(0);
	Node<List_entry>*fuzhu = other.current;
	while (fuzhu != nullptr) {
		this->insert(count, fuzhu->entry);
		fuzhu = fuzhu->next;
	}
}
template<class List_entry>
List<List_entry>::List() {
	this->count = 0;
	this->current = nullptr;
	this->current_position = 0;
}
template<class List_entry>
List<List_entry>::~List() {
	while (!empty())
		this->clear();
}
template<class List_entry>
Error_code List<List_entry>::clear() {
	List_entry fuzhu;
	while (!empty())
		remove(0, fuzhu);
	return success;
}
template<class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry&item) {
	if (position<0 || position>count)
		return range_error;
	if (position == 0) {
		set_position(0);
		Node<List_entry>*fuzhu = new Node<List_entry>(item,nullptr, current);
		if (current != nullptr)
			current->back = fuzhu;
		count++;
		current = fuzhu;
		return success;
	}
	if (position == count) {
		set_position(count - 1);
		Node<List_entry>*fuzhu = new Node<List_entry>(item, current, nullptr);
		current->next = fuzhu;
		count++;
		return success;
	}
	set_position(position);
	Node<List_entry>*fuzhu = new Node<List_entry>(item,current,current->next);
	current->next = fuzhu;
	fuzhu->next->back = fuzhu;
	count++;
	return success;
}
template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry&item) {
	if (position < 0 || position >= count)
		return range_error;
	if (this->count == 1) {
		delete current;
		current = nullptr;
		count = 0;
		this->current_position = 0;
		return success;
	}
	set_position(position);
	if (current->back != nullptr)
		current->back->next = current->next;
	if (current->next != nullptr)
		current->next->back = current->back;
	Node<List_entry>*fuzhu = current;
	if (position == 0) {
		set_position(1);
		current_position = 0;
	}
	else
		set_position(0);
	item = fuzhu->entry;
	delete fuzhu;
	count--;
	return success;
}
template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry&item) {
	if (position < 0 || position >= count)
		return range_error;
	set_position(position);
	item = current->entry;
	return success;
}
template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry&item) {
	if (position < 0 || position >= count)
		return range_error;
	set_position(position);
	current->entry = item;
	return success;
}
template<class List_entry>
bool List<List_entry>::empty()const {
	return count == 0;
}
template<class List_entry>
bool List<List_entry>::full()const {
	return false;
}
template<class List_entry>
int List<List_entry>::size()const {
	return count;
}
template<class List_entry>
void List<List_entry> ::set_position(int pos)const {
	if (pos == current_position)
		return;
	if(pos<current_position)
		for (int i = 0; i < current_position - pos; i++) {
			current = current->back;
		}
	if(pos>current_position)
		for (int i = 0; i <  pos-current_position; i++) {
			current = current->next;
		}
	current_position = pos;
}
#include<iostream>
using namespace std;
int main(void) {
	List <int>test;
	test.insert(0, 9);
	test.insert(1, 1);
	test.insert(2, 3);
	test.insert(3, 2);
	test.big_merge();
}

