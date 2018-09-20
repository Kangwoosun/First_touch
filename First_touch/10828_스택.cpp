#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int element;
	Node* next_node;
public:
	int getelement();
	Node* next();
	Node();
	Node(int n, Node* new_node);
};

Node::Node() {}
Node::Node(int n, Node* new_node) :element(n), next_node(new_node) {}

int Node::getelement() {
	return element;
}

Node* Node::next() {
	return next_node;
}

class Stack {
private:
	Node * Stack_head;
public:
	void push(int n);
	int pop();
	int size();
	bool empty();
	int top();
	Stack();
};

Stack::Stack() {
	Stack_head = NULL;
}

void Stack::push(int n) {
	Stack_head = new Node(n, Stack_head);
}

int Stack::pop() {
	if (empty())
		return -1;
	else {

		int poped = Stack_head->getelement();
		Node* ptr = Stack_head;
		Stack_head = Stack_head->next();
		delete ptr;

		return poped;
	}
}

int Stack::size() {

	int size = 0;
	for (Node* ptr = Stack_head; ptr != NULL; ptr = ptr->next())
		size++;
	return size;
}

bool Stack::empty() {
	return  (Stack_head == NULL);
}

int Stack::top() {
	if (empty())
		return -1;
	else
		return Stack_head->getelement();
}



int main() {

	int N;
	int input;
	string command;

	Stack stack;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> command;

		if (command == "push") {
			cin >> input;
			stack.push(input);
		}

		else if (command == "pop") {
			cout << stack.pop() << '\n';
		}

		else if (command == "size") {
			cout << stack.size() << '\n';
		}

		else if (command == "empty") {
			cout << stack.empty() << '\n';
		}

		else if (command == "top") {
			cout << stack.top() << '\n';
		}

	}

}