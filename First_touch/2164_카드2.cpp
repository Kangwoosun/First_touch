#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	queue<int> qu;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		qu.push(i);
	}
	for (int i = 0; i < N-1; i++) {
		qu.pop();
		qu.push(qu.front());
		qu.pop();
	}
	cout << qu.front();
}