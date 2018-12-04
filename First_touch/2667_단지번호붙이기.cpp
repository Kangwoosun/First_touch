#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;


int house[101][101];
int check[700];
int count_check = 0;
int N;
bool visit[101][101];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
bool is_in(int row, int column) {
	return ((1 <= row && row <= N && 1 <= column && column <= N) ? true : false);
}

void BFS(int row, int column) {
	
	pair<int, int> current_location;
	int current_row, current_column;
	int check_row, check_column;
	queue<pair<int, int>> q;
	q.push(make_pair(row, column));
	check[count_check] = 1;
	visit[row][column] = true;
	while (!q.empty()) {
		current_location = q.front();
		current_row = current_location.first;
		current_column = current_location.second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			check_row = current_location.first + mx[i];
			check_column = current_location.second + my[i];

			if (is_in(check_row, check_column) && !visit[check_row][check_column] && house[check_row][check_column]) {
				q.push(make_pair(check_row, check_column));
				visit[check_row][check_column] = true;
				check[count_check]++;
			}
		}

	}

	count_check++;
}

int main() {
	string input;
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			house[i][j + 1] = input[j] - '0';
		}
	}
	for(int i = 1; i<=N; i++)
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && house[i][j])
				BFS(i, j);
		}
	cout << count_check << endl;
	sort(check, check + count_check);
	for (int i = 0; i < count_check; i++)
		cout << check[i] << endl;
}