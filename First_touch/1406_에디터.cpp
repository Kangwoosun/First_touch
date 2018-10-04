#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	Node* next_node;
	Node* prev_node;
	char element;
public:
	Node(char s, Node* new_prev, Node* new_next);
	Node* next();
	char getelement();
	Node* prev();
	void setnext(Node* new_node);
	void setprev(Node* new_node);
};
Node::Node(char s, Node* new_prev, Node* new_next):element(s), next_node(new_next), prev_node(new_prev) {}
Node* Node::next() {
	return next_node;
}
Node* Node::prev() {
	return prev_node;
}
char Node::getelement() {
	return element;
}
void Node::setnext(Node* new_node) {
	next_node = new_node;
}
void Node::setprev(Node* new_node) {
	prev_node = new_node;
}


class editor {
private:
	Node* start;
	Node* end;
	Node* cursor;
	bool check_start;
public:
	editor();
	editor(string str);
	~editor();
	void clear();
	bool empty();
	void L();
	void D();
	void B();
	void P(char $);
	void print();
};
editor::editor() {
	start = NULL;
	end = NULL;
	cursor = NULL;
}
editor::editor(string str) {
	check_start = false;
	Node* ptr;
	start = new Node(str[0], NULL, NULL);
	end = start;
	for (int i = 1; i < str.length(); i++) {
		ptr = new Node(str[i], end, NULL);
		end->setnext(ptr);
		end = end->next();
	}
	cursor = end;

}
editor::~editor() {
	clear();
}

void editor::clear() {
	Node* tmp;
	for (Node* ptr = start; ptr != NULL;) {
		tmp = ptr;
		ptr = ptr->next();
		delete tmp;
	}
}
bool editor::empty() {
	return start == NULL;
}
void editor::L() {
	if (check_start)
		return;
	else if (cursor == start)
		check_start = true;
	else
		cursor = cursor->prev();
}
void editor::D() {
	if (check_start)
		check_start = false;
	else if (cursor == end)
		return;
	else
		cursor = cursor->next();
}
void editor::B() {
	Node* ptr_prev;
	Node* ptr_next;
	Node* tmp = cursor;
	if (!check_start) {
		ptr_next = cursor->next();
		ptr_prev = cursor->prev();
		if(ptr_next != NULL)
			ptr_next->setprev(ptr_prev);
		if(ptr_prev != NULL)
			ptr_prev->setnext(ptr_next);
		cursor = ptr_prev;
		if (tmp == start){
			check_start = true;
			cursor = ptr_next;
			start = cursor;
		}
		if (tmp == end)
			end = cursor;
		delete tmp;
	}
}
void editor::P(char $) {
	Node* ptr;
	Node* ptr_next;
	Node* tmp = cursor;
	if (check_start) {
		ptr = new Node($, NULL, start);
		start->setprev(ptr);
		start = ptr;
		check_start = false;
		cursor = start;
	}
	else{
		ptr = new Node($, cursor, cursor->next());
		if (cursor != end) {
			ptr_next = cursor->next();
			ptr_next->setprev(ptr);
		}
		cursor->setnext(ptr);
		cursor = ptr;
		if (tmp == end)
			end = cursor;
	}
}
void editor::print() {
	for (Node* ptr = start; ptr != NULL; ptr = ptr->next()) {
		cout << ptr->getelement();
	}
	cout << '\n';
}
int main() {
	string input;
	int N;
	char Str, input_Str;
	cin >> input;
	cin >> N;
	editor ed(input);
	for (int i = 0; i < N; i++) {
		cin >> Str;
		switch (Str)
		{
		case 'L':
			ed.L();
			break;
		case 'D':
			ed.D();
			break;
		case 'B':
			ed.B();
			break;
		case 'P':
			cin >> input_Str;
			ed.P(input_Str);
			break;
		default:
			break;
		}
	}
	ed.print();
}