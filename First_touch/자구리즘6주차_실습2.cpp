#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec[1001];

int main() {
	queue<int> qu;
	int N;
	int u, v;
	int tmp;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
	}
	qu.push(1);
	while (!qu.empty()) {
		tmp = qu.front();
		for (auto i : vec[tmp])
			qu.push(i);
		qu.pop();
		cout << tmp << " ";
	}
}