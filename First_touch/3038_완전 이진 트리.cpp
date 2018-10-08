#include <iostream>
using namespace std;

template <class T>
class Node {
private:
	Node<T> next_node;
	T element;
public:
	Node(T n, Node<T> new_node);
	Node<T> next();
	T get_element();
	void set_next(Node<T> new_node);
};
template <class T>
Node<T>::Node(T n, Node<T> new_node):element(n), next_node(new_node) {}

template <class T>
Node<T> Node<T>::next() {
	return next_node;
}

template <class T>
T Node<T>::get_element() {
	return element;
}

template <class T>
void Node<T>::set_next(Node<T> new_node) {
	next_node = new_node;
}

template <class T>
class Linked_list {
private:
	Node<T> head;
	Node<T> tail;
public:
	Linked_list();
	~Linked_list();
	void push(T n);
	void pop();
	void clear();
	Node<T> front();
	Node<T> back();
	bool empty();
	
};
template <class T>
Linked_list<T>::Linked_list() {
	head = NULL;
	tail = NULL;
}
template <class T>
Linked_list<T>::~Linked_list() {
	clear();
}
template <class T>
void Linked_list<T>::push(T n) {
	if (empty()) {
		head = new Node<T>(T n, NULL);
		tail = head;
		return;
	}
	Node<T> ptr = new Node<T>(T n, NULL);
	tail->set_next(ptr);
	tail = ptr;
}
template <class T>
void Linked_list<T>::pop() {
	if (empty())
		return;
	Node<T> ptr = head;
	head = head->next();
	delete ptr;
}
template <class T>
void Linked_list<T>::clear() {
	while (!empty())
		pop();
}
template <class T>
Node<T> Linked_list<T>::front() {
	if (empty())
		return;
	return head->get_element();
}
template <class T>
Node<T> Linked_list<T>::back() {
	if (empty())
		return;
	return tail->get_element();
}
template<class T>
bool Linked_list<T>::empty() {
	return head == NULL;
}

template <class T>
class Tree {
private:
	Tree<T>* parent;
	Linked_list<Tree*> children;
	T element;
	
public:
	Tree();
	Tree(Tree<T>* new_parent, Linked_list<Tree*> new_children, T n);
	~Tree();
	T get_element();
	void set_element(T n);
	Tree<T>* get_parent();
	void set_parent(Tree<T>* new_parent);
	Linked_list<Tree*> get_children();
	void set_children(Tree* new_children);
	void clear();
	bool is_leaf();
	bool is_root();
};

template <class T>
Tree<T>::Tree() {
	parent = NULL;
	children = NULL;
}

template <class T>
Tree<T>::Tree(Tree<T>* new_parent, Linked_list<Tree*> new_children, T n):parent(new_parent), children(new_children),element(n){}

template <class T>
Tree<T>::~Tree() {
	clear();
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
Linked_list<Tree<T>*> Tree<T>::get_children() {
	return children;
}
template <class T>
void Tree<T>::set_children(Tree* new_children) {
	children.push(new_children);
}
template <class T>
void Tree<T>::clear() {
	
	children.clear();
	if (is_root())
		delete this;
}

template <class T>
bool Tree<T>::is_leaf() {
	return children.empty();
}

template <class T>
bool Tree<T>::is_root() {
	return parent == NULL;
}

int main() {
	int N;
	cin >> N;
}