#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> vec[100001];
int node_parent[100001];

void set_tree() {
	deque<int> BFS_qu;
	int index;
	int parent = 0;
	int count;
	
	BFS_qu.push_back(1);
	while (1) {
		count = 0;
		
		
		index = BFS_qu.front();
		BFS_qu.pop_front();

		BFS_qu.push_back(0);
		BFS_qu.push_back(index);
		
		for (auto i : vec[index]) {
			if (parent != i) {
				node_parent[i] = index;
				BFS_qu.push_back(i);
				count++;
			}
		}
		if (count == 0) {
			BFS_qu.pop_back();
			BFS_qu.pop_back();
			if (BFS_qu.empty())
				return;
		}

		if (BFS_qu.front() == 0) {
			BFS_qu.pop_front();
			parent = BFS_qu.front();
			BFS_qu.pop_front();
			
		}

		
	}

}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int N,input_1, input_2;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> input_1 >> input_2;
		vec[input_1].push_back(input_2);
		vec[input_2].push_back(input_1);
	}
	
	set_tree();

	for (int i = 2; i <= N; i++)
		cout << node_parent[i] << '\n';
}