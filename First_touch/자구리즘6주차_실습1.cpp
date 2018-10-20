#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
void preorder(int location) {
	cout << location << " ";
	for (auto i : vec[location]) {
		preorder(i);
	}
}
void postorder(int location) {
	
	for (auto i : vec[location]) {
		postorder(i);
	}
	cout << location << " ";
}
int main() {	
	int N;
	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
	}
	preorder(1);
	cout << endl;
	postorder(1);
	cout << endl;
}