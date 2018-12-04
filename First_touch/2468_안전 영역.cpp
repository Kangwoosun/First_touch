#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;


int city[101][101];
int N;
bool visit[101][101];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
bool is_in(int row, int column) {
	return ((1 <= row && row <= N && 1 <= column && column <= N) ? true : false);
}

void BFS(int row, int column ,int height) {

	pair<int, int> current_location;
	int current_row, current_column;
	int check_row, check_column;
	queue<pair<int, int>> q;
	q.push(make_pair(row, column));
	visit[row][column] = true;
	while (!q.empty()) {
		current_location = q.front();
		current_row = current_location.first;
		current_column = current_location.second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			check_row = current_location.first + mx[i];
			check_column = current_location.second + my[i];

			if (is_in(check_row, check_column) && !visit[check_row][check_column] && 
				city[check_row][check_column] > height) {
				q.push(make_pair(check_row, check_column));
				visit[check_row][check_column] = true;

			}
		}

	}

}

int main() {
	int input, max = 0;
	int max_field = 0, tmp;

	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			city[i][j] = input;
			if (max < input)
				max = input;
		}
	}
	for (int i = 0; i < max; i++) {
		tmp = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (!visit[j][k] && city[j][k] > i) {
					BFS(j, k, i);
					tmp++;
				}
			}
		}
		if (max_field < tmp)
			max_field = tmp;
		memset(visit, false, sizeof(visit));
	}
	cout << max_field << endl;
}