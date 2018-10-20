#include <iostream>
#include <vector>
using namespace std;

int store[26][2] = { -1, };

void pre_print(int level) {
	cout << (char)(level + 'A');
	if (store[level][0] != '.')
		pre_print(store[level][0]-'A');
	if (store[level][1] != '.')
		pre_print(store[level][1]-'A');
	return;
}
void in_print(int level) {
	
	if (store[level][0] != '.')
		in_print(store[level][0] - 'A');

	cout << (char)(level + 'A');

	if (store[level][1] != '.')
		in_print(store[level][1] - 'A');
	return;
}
void post_print(int level) {
	if (store[level][0] != '.')
		post_print(store[level][0] - 'A');

	if (store[level][1] != '.')
		post_print(store[level][1] - 'A');

	cout << (char)(level + 'A');
	return;
}
int main() {
	int N;
	char parent, left, right;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> parent >> left >> right;
		store[parent - 'A'][0] = left;
		store[parent - 'A'][1] = right;
	}
	pre_print(0);
	cout << endl;
	in_print(0);
	cout << endl;
	post_print(0);
	

}