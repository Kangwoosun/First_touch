#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
private:
	T element;
	Node<T>* next_node;
public:
	T getelement();
	Node<T>* next();
	Node();
	Node(T n, Node<T>* new_node);
};

template <typename T>
Node<T>::Node() {}

template <typename T>
Node<T>::Node(T n, Node<T>* new_node) :element(n), next_node(new_node) {}

template <typename T>
T Node<T>::getelement() {
	return element;
}

template <typename T>
Node<T>* Node<T>::next() {
	return next_node;
}

template <typename T>
class Stack {
private:
	Node<T> * ESP;
public:
	void push(T n);
	T pop();
	int size();
	bool empty();
	T top();
	void clear();
	Stack();
};

template <typename T>
Stack<T>::Stack() {
	ESP = NULL;
}

template <typename T>
void Stack<T>::push(T n) {
	ESP = new Node<T>(n, ESP);
}

template <typename T>
T Stack<T>::pop() {
	if (empty())
		return -1;
	else {

		int poped = ESP->getelement();
		Node<T>* ptr = ESP;
		ESP = ESP->next();
		delete ptr;

		return poped;
	}
}

template <typename T>
void Stack<T>::clear() {
	for (ESP; ESP != NULL;) {
		Node<T>* prev = ESP;
		ESP = ESP->next();
		delete prev;
	}

}

template <typename T>
int Stack<T>::size() {

	int size = 0;
	for (Node<T>* ptr = ESP; ptr != NULL; ptr = ptr->next())
		size++;
	return size;
}

template <typename T>
bool Stack<T>::empty() {
	return  (ESP == NULL);
}

template <typename T>
T Stack<T>::top() {
	if (empty())
		return -1;
	else
		return ESP->getelement();
}

int main() {
	int check = 0;
	char cursor;
	string alphabet = "",PS;
	Stack<char> stack_operator, tmp_stack;
	cin >> PS;
	for (int i = 0; i < PS.length(); i++) {
		cursor = PS[i];


		
		if (cursor == '+' || cursor == '-' || cursor == '*' || cursor == '/' || cursor == '(' || cursor == ')') {
			if (stack_operator.empty()) {
				stack_operator.push(cursor);
				continue;
			}
			if (stack_operator.top() == '(' && cursor != ')') {
				stack_operator.push(cursor);
				continue;
			}
			switch (cursor)
			{
			case'(':
				check++;
				stack_operator.push(cursor);
				break;
			case ')':
				check--;
				while(stack_operator.top() != '(' && !stack_operator.empty())
					alphabet += stack_operator.pop();
				stack_operator.pop();
				break;
			case '*':
			case '/':
				switch (stack_operator.top())
				{
				case '*':
				case '/':
					alphabet += stack_operator.pop();
					stack_operator.push(cursor);
					break;
				case '+':
				case '-':
					
					stack_operator.push(cursor);

					break;
				}
				break;

			case '+':
			case '-':
				switch (stack_operator.top())
				{
				case '*':
				case '/':
					alphabet += stack_operator.pop();
					if(stack_operator.top() != '(' && !stack_operator.empty())
						alphabet += stack_operator.pop();
					stack_operator.push(cursor);
					break;
				case '+':
				case '-':
					alphabet += stack_operator.pop();
					stack_operator.push(cursor);
					break;
				}
				break;
				break;

			}
		}
		else
			alphabet += cursor;
	}
	if (!stack_operator.empty())
		while (stack_operator.top() != -1 && stack_operator.top() != '(')
			alphabet += stack_operator.pop();
	cout << alphabet;
}