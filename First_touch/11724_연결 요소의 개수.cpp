#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
bool visit[1001];
void DFS(int start) {
	
	visit[start] = true;
	
	for (auto i : vec[start]) {
		if (!visit[i])
			DFS(i);
	}

}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int connected_element = 0;
	int N, M, input1, input2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2;
		vec[input1].push_back(input2);
		vec[input2].push_back(input1);
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			DFS(i);
			connected_element++;
		}
	}
	cout << connected_element;
}