#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int element;
	Node* next_node;
public:
	int getelement();
	void set_next(Node* new_node);
	Node* next();
	Node();
	Node(int n, Node* new_node);
};

Node::Node() {}
Node::Node(int n, Node* new_node) :element(n), next_node(new_node) {}
void Node::set_next(Node* new_node) {
	next_node = new_node;
}
int Node::getelement() {
	return element;
}

Node* Node::next() {
	return next_node;
}

class Cirqueue {
private:
	Node * head;
	Node * tail;
public:
	void push(int n);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
	Cirqueue();
	~Cirqueue();
	void clear();
};

void Cirqueue::push(int n) {
	if (head == NULL) {
		tail = new Node(n, NULL);
		head = tail;
	}
	else {
		Node* ptr = tail;
		tail = new Node(n, NULL);
		ptr->set_next(tail);
	}

}
int Cirqueue::pop() {
	if (empty())
		return -1;
	int return_val = head->getelement();
	Node* ptr = head;
	head = head->next();
	delete ptr;
	return return_val;
}
int Cirqueue::size() {
	int size = 0;
	for (Node* ptr = head; ptr != NULL; ptr = ptr->next())
		size++;
	return size;
}
bool Cirqueue::empty() {
	return (head == NULL);
}
int Cirqueue::front() {
	if (empty())
		return -1;
	return (head->getelement());
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
}
Cirqueue::~Cirqueue() {
	clear();
}

int main() {
	Cirqueue queue;
	string input;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "push") {
			cin >> num;
			queue.push(num);
		}
		else if (input == "back") {
			cout << queue.back() << endl;
		}
		else if (input == "pop") {
			cout << queue.pop() << endl;
		}
		else if (input == "size") {
			cout << queue.size() << endl;
		}
		else if (input == "empty") {
			cout << queue.empty() << endl;
		}
		else if (input == "front") {
			cout << queue.front() << endl;
		}

	}
}