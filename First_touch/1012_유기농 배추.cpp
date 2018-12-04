#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;


int field[51][51];
int count_check = 0;
int M, N;
bool visit[51][51];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
bool is_in(int row, int column) {
	return ((1 <= row && row <= N && 1 <= column && column <= M) ? true : false);
}

void BFS(int row, int column) {

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

			if (is_in(check_row, check_column) && !visit[check_row][check_column] && field[check_row][check_column]) {
				q.push(make_pair(check_row, check_column));
				visit[check_row][check_column] = true;
				
			}
		}

	}

	count_check++;
}

int main() {
	string input;
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int T ,K;
	int row, column;
	cin >> T;
	for (int j = 0; j < T; j++) {
		cin >> N >> M >> K;

		for (int i = 0; i < K; i++) {
			cin >> row >> column;
			field[row + 1][column + 1]++;
		}
		for(int i=1; i<=N; i++)
			for (int k = 1; k <= M; k++) {
				if (!visit[i][k] && field[i][k])
					BFS(i, k);
			}
		cout << count_check << endl;
		memset(field, 0, sizeof(field));
		memset(visit, false, sizeof(visit));
		count_check = 0;

	}
}