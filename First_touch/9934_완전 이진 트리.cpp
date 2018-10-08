#include <iostream>
#include <queue>
#include <cmath>
#include <math.h>
using namespace std;

template <class T>
class Tree {
private:
	Tree<T>* parent;
	Tree<T>* left_child;
	Tree<T>* right_child;
	T element;
	int level;

public:
	Tree();
	Tree(Tree<T>* new_parent, Tree<T>* new_left, Tree<T>* new_right, T n);
	Tree(Tree<T>* new_parent, Tree<T>* new_left, Tree<T>* new_right, T n, int level);
	~Tree();
	T get_element();
	void set_element(T n);
	Tree<T>* get_parent();
	void set_parent(Tree<T>* new_parent);
	Tree<T>* get_left();
	Tree<T>* get_right();
	void set_left(Tree* new_child);
	void set_right(Tree* new_child);
	void set_children(Tree* left_child, Tree* right_child);
	void clear();
	bool is_leaf();
	bool is_root();
	bool is_left();
	bool is_right();
	int get_level();
	void set_level(int n);

};

template <class T>
Tree<T>::Tree() {
	parent = NULL;
	left_child = NULL;
	right_child = NULL;
}

template <class T>
Tree<T>::Tree(Tree<T>* new_parent, Tree<T>* new_left, Tree<T>* new_right, T n) :
	parent(new_parent),
	left_child(new_left),
	right_child(new_right),
	element(n)
{}

template<class T>
Tree<T>::Tree(Tree<T>* new_parent, Tree<T>* new_left, Tree<T>* new_right, T n, int level) :
	parent(new_parent),
	left_child(new_left),
	right_child(new_right),
	element(n),
	level(level)
{}

template <class T>
Tree<T>::~Tree() {
}
template <class T>
T Tree<T>::get_element() {
	return element;
}
template <class T>
void Tree<T>::set_element(T n) {
	element = n;
}
template <class T>
Tree<T>* Tree<T>::get_parent() {
	return parent;
}
template <class T>
void Tree<T>::set_parent(Tree<T>* new_parent) {
	parent = new_parent;
}
template <class T>
Tree<T>* Tree<T>::get_left() {
	return left_child;
}
template <class T>
Tree<T>* Tree<T>::get_right() {
	return right_child;
}
template <class T>
void Tree<T>::set_left(Tree* new_child) {
	left_child = new_child;
}
template <class T>
void Tree<T>::set_right(Tree* new_child) {
	right_child = new_child;
}
template <class T>
void Tree<T>::set_children(Tree* left_child, Tree* right_child) {
	this->left_child = left_child;
	this->right_child = right_child;
}
template <class T>
void Tree<T>::clear() {
	if (this->is_left())
		this->get_left()->clear();
	
	if (this->is_right())
		this->get_right()->clear();
	
	if(!is_root())
		delete this;

}

template <class T>
bool Tree<T>::is_leaf() {
	return (left_child == NULL && right_child == NULL);
}

template <class T>
bool Tree<T>::is_root() {
	return (parent == NULL);
}
template <class T>
bool Tree<T>::is_left() {
	return left_child != NULL;
}
template <class T>
bool Tree<T>::is_right() {
	return right_child != NULL;
}
template <class T>
int Tree<T>::get_level() {
	return level;
}
template <class T>
void Tree<T>::set_level(int n) {
	level = n;
}

template <class T>
void BFS(Tree<T>* root);

template <class T>
void preorder_left_tree(int arr[], int size, Tree<T>* parent);

template <class T>
void preorder_right_tree(int arr[], int size, Tree<T>* parent);


int main() {
	int K,input[1024], size;
	bool check = true;
	int END;
	cin >> K;
	END = pow(2.0, K);
	
	for (int i = 0; i < END; i++) {
		cin >> input[i];
	}
	size = END - 1;
	Tree<int> root(NULL, NULL, NULL, input[size/2], 0);
	preorder_left_tree(input, size / 2, &root);
	preorder_right_tree(input + size / 2 + 1, size / 2, &root);

	BFS(&root);
	root.clear();
	return 0;
}

template <class T>
void BFS(Tree<T>* root) {
	
	queue<Tree<T>*> BFS_find;
	BFS_find.push(root);
	cout << root->get_element() << '\n';
	int tmp_level = 0;
	Tree<T>* ptr;
	while (1) {

		if (BFS_find.empty())
			break;

		ptr = BFS_find.front();
		BFS_find.pop();

		if (ptr->get_level() > tmp_level) {
			cout << '\n';
			tmp_level = ptr->get_level();
		}
		if (ptr->is_leaf())
			break;
			
		if (ptr->is_left()) {
			BFS_find.push(ptr->get_left());
			cout << ptr->get_left()->get_element() << " ";
		}
		
		if (ptr->is_right()) {
			BFS_find.push(ptr->get_right());
			cout << ptr->get_right()->get_element() << " ";
		}

		
		
	}
	return;
}

template <class T>
void preorder_left_tree(int arr[], int size, Tree<T>* parent) {

	Tree<int>* tmp = new Tree<int>(parent, NULL, NULL, arr[size / 2], parent->get_level()+1);
	parent->set_left(tmp);

	if (size == 1)
		return;

	preorder_left_tree(arr, size / 2, tmp);
	preorder_right_tree(arr + size / 2 + 1, size / 2, tmp);
	
}

template <class T>
void preorder_right_tree(int arr[], int size, Tree<T>* parent) {
	Tree<int>* tmp = new Tree<int>(parent, NULL, NULL, arr[size / 2], parent->get_level() + 1);
	parent->set_right(tmp);
	
	if (size == 1) 
		return;
	
	preorder_right_tree(arr + size / 2 + 1, size / 2, tmp);
	preorder_left_tree(arr, size / 2, tmp);

}

