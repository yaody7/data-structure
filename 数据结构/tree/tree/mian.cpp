#include<queue>
#include<iostream>
using namespace std;
enum Error_code
{
	success, fail
};
template<class Entry>
struct Binary_node
{
	Entry data;
	Binary_node<Entry>*left, *right;
	Binary_node() {
		this->left = nullptr;
		this->right = nullptr;
		this->data = -1;
	}
	Binary_node(const Entry&x) {
		this->left = nullptr;
		this->right = nullptr;
		this->data = x;
	}
};
template <class Entry>
class tree
{
public:
	tree();
	void clear();
	bool emptry();
	void preorder(void(*visit)(Entry));
	void inorder(void(*visit)(Entry));
	void postorder(void(*visit)(Entry));
	void insert(Entry x);
	int height()const;
	Error_code search(Entry);
	~tree();

private:
	Binary_node<Entry>*root;
};
template<class Entry>
Error_code rec_search(Binary_node<Entry>*x,Entry y) {
	if (x == nullptr)
		return fail;
	if (x->data == y)
		return success;
	if (rec_search(x->left,y) == fail && rec_search(x->right,y) == fail)
		return fail;
	return success;
}
template<class Entry>
Error_code tree<Entry>::search(Entry x) {
	return rec_search(this->root, x);
}
template <class Entry>
int rec_height(Binary_node<Entry>* x) {
	if (x == NULL)
		return 0;
	int left=rec_height(x->left);
	int right=rec_height(x->right);
	if (left > right)
		return left + 1;
	return right + 1;
}
template <class Entry>
int tree<Entry>::height() const{
	return rec_height(this->root);
}
template <class Entry>
Error_code rec_insert(Binary_node<Entry>*x, Entry y) {
	if (x->data == y)
		return fail;
	if (x->data > y) {
		if (x->left == NULL) {
			x->left = new Binary_node<Entry>;
			x->left->data = y;
			return success;
		}
		rec_insert(x->left, y);
	}
	if (x->right == NULL) {
		x->right = new Binary_node<Entry>;
		x->right->data = y;
		return success;
	}
	rec_insert(x->right, y);
}
template <class Entry>
void tree<Entry>::insert(Entry x) {
	if (this->root == NULL) {
		this->root = new Binary_node<Entry>;
		this->root->data = x;
		return;
	}
	rec_insert(this->root, x);
}
template<class Entry>
tree<Entry>::tree()
{
	this->root = nullptr;
}
template<class Entry>
tree<Entry>::~tree()
{
	this->clear();
}
template<class Entry>
void tree<Entry>::clear() {
	queue<Binary_node<Entry>*>test;
	test.push(this->root);
	while (!test.empty()) {
		if (test.front()->left != nullptr)
			test.push((test.front()->left));
		if (test.front()->right != nullptr)
			test.push((test.front()->right));
		delete test.front();
		test.pop();
	}
}
template<class Entry>
bool tree<Entry>::emptry() {
	return this->root == nullptr;
}
template<class Entry>
void visit(Entry x) {
	cout << x;
}
template<class Entry>
void rec_pre(Binary_node<Entry>*x, void(*visit)(Entry)) {
	if (x == NULL)
		return;
	visit(x->data);
	rec_pre(x->left,visit);
	rec_pre(x->right,visit);
}
template<class Entry>
void rec_in(Binary_node<Entry>*x, void(*visit)(Entry)) {
	if (x == NULL)
		return;
	rec_in(x->left,visit);
	visit(x->data);
	rec_in(x->right,visit);
}
template<class Entry>
void rec_post(Binary_node<Entry>*x, void(*visit)(Entry)) {
	if (x == NULL)
		return;
	rec_post(x->left,visit);
	rec_post(x->right,visit);
	visit(x->data);
}
template<class Entry>
void tree<Entry>::preorder(void (*visit) (Entry)) {
	rec_pre(this->root,visit);
}
template<class Entry>
void tree<Entry>::inorder(void(*visit)(Entry)) {
	rec_in(this->root,visit);
}
template<class Entry>
void tree<Entry>:: postorder(void(*visit)(Entry)) {
	rec_post(this->root,visit);
}
int main(void) {
	tree<int>test;
	test.insert(1);
	test.insert(0);
	test.insert(3);
	test.insert(4);
	cout << test.search(0);
	cout << test.search(9);
	cout << test.height();
	test.inorder(visit);
	cout << endl;
	test.preorder(visit);
	cout << endl;
	test.postorder(visit);
	cout << endl;
}