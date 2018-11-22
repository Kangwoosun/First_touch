#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
bool visit[1001];
int sz = 0;
void DFS(int start) {

	visit[start] = true;
	sz++;
	for (auto i : vec[start]) {
		if (!visit[i])
			DFS(i);
	}

}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int N, M, input1, input2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2;
		vec[input1].push_back(input2);
		vec[input2].push_back(input1);
	}
	DFS(1);
	cout << --sz << endl;
}