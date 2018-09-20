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
	Node * ESP;
public:
	void push(int n);
	int pop();
	int size();
	bool empty();
	int top();
	void clear();
	Stack();
};

Stack::Stack() {
	ESP = NULL;
}

void Stack::push(int n) {
	ESP = new Node(n, ESP);
}

int Stack::pop() {
	if (empty())
		return -1;
	else {

		int poped = ESP->getelement();
		Node* ptr = ESP;
		ESP = ESP->next();
		delete ptr;

		return poped;
	}
}
void Stack::clear() {
	for (ESP; ESP != NULL;) {
		Node* prev = ESP;
		ESP = ESP->next();
		delete prev;
	}

}

int Stack::size() {

	int size = 0;
	for (Node* ptr = ESP; ptr != NULL; ptr = ptr->next())
		size++;
	return size;
}

bool Stack::empty() {
	return  (ESP == NULL);
}

int Stack::top() {
	if (empty())
		return -1;
	else
		return ESP->getelement();
}

int main() {
	int N, check;
	string PS;
	Stack stack;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> PS;
		check = 0;
		for (int j = 0; j < PS.length(); j++) {
			if (PS[j] == '(')
				stack.push(0);
			else {
				check = stack.pop();
				if (check == -1) {
					cout << "NO\n";
					break;
				}
			}
		}
		if (check == -1)
			continue;
		if (stack.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
		stack.clear();
	}
}