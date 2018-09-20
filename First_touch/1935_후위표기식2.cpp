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
	~Stack();
};

template <typename T>
Stack<T>::Stack() {
	ESP = NULL;
}
template <typename T>
Stack<T>::~Stack() {
	clear();
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

		T poped = ESP->getelement();
		Node<T>* ptr = ESP;
		ESP = ESP->next();
		delete ptr;

		return poped;
	}
}

template <typename T>
void Stack<T>::clear() {
	while (!empty()) {
		pop();
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
	int N, alphabet[26];
	double tmp_sum = 0.0;
	double tmp_a1, tmp_a2;
	string PS;
	Stack<double> sum;
	cin >> N;
	cin >> PS;
	for (int i = 0; i < N; i++) {
		cin >> alphabet[i];
	}

	for (int i = 0; i < PS.length(); i++) {
		
		if (PS[i] == '+' || PS[i] == '-' || PS[i] == '*' || PS[i] == '/') {
			tmp_a2 = sum.pop();
			tmp_a1 = sum.pop();
			switch (PS[i])
			{
			case '+':
				tmp_sum = tmp_a1 + tmp_a2;
				break;
			case '-':
				tmp_sum = tmp_a1 - tmp_a2;
				break;
			case '*':
				tmp_sum = tmp_a1 * tmp_a2;
				break;
			case '/':
				tmp_sum = tmp_a1 / tmp_a2;
				break;

			}
			sum.push(tmp_sum);

		}
		else {
			sum.push(alphabet[PS[i] - 'A']);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << sum.pop();
}