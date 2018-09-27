#include <iostream>
#include <string>
using namespace std;

class Cirqueue {
private:
	int back_val;
	int array[10000];
public:
	void push(int n);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
	Cirqueue();
	~Cirqueue();
};

void Cirqueue::push(int n) {
	back_val++;
	array[back_val] = n;
	
}
int Cirqueue::pop() {
	if (empty())
		return -1;
	int tmp = array[0];
	for (int i = 1; i <=back_val; i++)
		array[i - 1] = array[i];
	back_val--;
	return tmp;
}
int Cirqueue::size() {
	return back_val + 1;
}
bool Cirqueue::empty() {
	return (back_val < 0);
}
int Cirqueue::front() {
	if (empty())
		return -1;
	return array[0];
}
int Cirqueue::back() {
	if (empty())
		return -1;
	return array[back_val];
}

Cirqueue::Cirqueue() {
	back_val = -1;
}
Cirqueue::~Cirqueue() {

}

int main() {
	Cirqueue queue;
	string input;
	int N,num;
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