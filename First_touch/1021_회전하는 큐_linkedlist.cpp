#include <iostream>
using namespace std;

class Node {
private:
	int element;
	Node* next_node;
	Node* prev_node;
public:
	int getelement();
	void set_next(Node* new_node);
	void set_prev(Node* new_node);
	Node* next();
	Node* prev();
	Node();
	Node(int n, Node* newnext_node, Node* newprev_node);
};

Node::Node() {}
Node::Node(int n, Node* newnext_node, Node* newprev_node) :element(n), next_node(newnext_node), prev_node(newprev_node) {}
void Node::set_next(Node* new_node) {
	next_node = new_node;
}
void Node::set_prev(Node* new_node) {
	prev_node = new_node;
}
int Node::getelement() {
	return element;
}

Node* Node::next() {
	return next_node;
}

Node* Node::prev() {
	return prev_node;
}

class Cirqueue {
private:
	Node * head;
	Node * tail;
	Node * cursor;
	Node * precursor;
	int size;
public:
	void setcursor();
	void setcursor(Node* newnode);
	void push(int n);
	void pop();
	int getsize();
	bool empty();
	int front();
	int back();
	int now();
	void movCurF();
	void movCurP();
	Cirqueue();
	~Cirqueue();
	void clear();
	int searchF(int n);
	int searchP(int n);
	Node* getprecursor();
};
Node* Cirqueue::getprecursor() {
	return precursor;
}
void Cirqueue::setcursor() {
	cursor = head;
}
void Cirqueue::setcursor(Node* newnode) {
	precursor = cursor;
	cursor = newnode;
}
int Cirqueue::searchF(int n) {
	int count = 0;
	bool check = false;
	precursor = cursor;
	for (int i = 0; i < getsize(); i++) {
		if (cursor->getelement() == n) {
			check = true;
			break;
		}	
		count++;
		movCurF();
	}
	if (check)
		return count;
	
	return -1;
}

int Cirqueue::searchP(int n) {
	int count = 0;
	bool check = false;
	precursor = cursor;
	for (int i = 0; i < getsize(); i++) {
		if (cursor->getelement() == n) {
			check = true;
			break;
		}
		count++;
		movCurP();
	}
	if (check)
		return count;
	return -1;
}
void Cirqueue::push(int n) {
	Node* ptr = NULL;
	if (empty()) {
		ptr = new Node(n, NULL, NULL);
		head = ptr;
		tail = ptr;
		ptr->set_next(ptr);
		ptr->set_prev(ptr);
	}
	else {
		ptr = new Node(n, head, tail);
		tail->set_next(ptr);
		head->set_prev(ptr);
		tail = ptr;
	}

	size++;
}
void Cirqueue::pop() {
	Node* tmp = cursor;
	Node* ptr = cursor->prev();
	cursor = cursor->next();
	cursor->set_prev(ptr);
	ptr->set_next(cursor);
	delete tmp;
	size--;
}
int Cirqueue::getsize() {
	return size;
}
bool Cirqueue::empty() {
	return (getsize() == 0);
}
int Cirqueue::front() {
	if (empty())
		return -1;
	return (head->getelement());
}
int Cirqueue::now() {
	if (empty())
		return -1;
	return (cursor->getelement());
}
void Cirqueue::movCurF() {
	cursor = cursor->next();
}
void Cirqueue::movCurP() {
	cursor = cursor->prev();
}

int Cirqueue::back() {
	if (empty())
		return -1;
	return (tail->getelement());
}
void Cirqueue::clear() {
	while (!empty())
		pop();
}

Cirqueue::Cirqueue() {
	head = NULL;
	tail = NULL;
	size = 0;
	
}
Cirqueue::~Cirqueue() {
	clear();
}
int main() {
	int N, M, location[51];
	Cirqueue cirqueue;
	int count=0;
	int tmp_searchF;
	int tmp_searchP;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> location[i];
	}
	for (int i = 0; i < N; i++) {
		cirqueue.push(i + 1);
	}
	cirqueue.setcursor();
	for (int i = 0; i < M; i++) {
		tmp_searchF = cirqueue.searchF(location[i]);
		cirqueue.setcursor(cirqueue.getprecursor());
		tmp_searchP = cirqueue.searchP(location[i]);
		cirqueue.pop();
		count += (tmp_searchF < tmp_searchP ? tmp_searchF : tmp_searchP);
	}
	cout << count << endl;
}