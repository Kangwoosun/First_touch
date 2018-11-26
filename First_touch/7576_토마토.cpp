#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int row, column;
int box[1001][1001];
bool visit[1001][1001];
void BFS() {
	int tmp_row, tmp_column;
	pair<int, int> current_location;
	queue<pair<int, int>> q;
	int count = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
			if (box[i][j] == 1)
				q.push(make_pair(i, j));
	q.push(make_pair(-1, -1));
	while (!q.empty()) {
		current_location = q.front();
		q.pop();
		if (current_location.first == -1 && current_location.second == -1) {
			if (!q.empty()) {
				q.push(current_location);
				count++;
			}
			continue;
		}

		tmp_row = current_location.first;
		tmp_column = current_location.second;


		//top
		if (tmp_row != 1) {
			if (box[tmp_row - 1][tmp_column] == 0) {
				q.push(make_pair(tmp_row - 1, tmp_column));
				box[tmp_row - 1][tmp_column] = 1;
			}
		}
		//buttom
		if (tmp_row != row) {
			if (box[tmp_row + 1][tmp_column] == 0) {
				q.push(make_pair(tmp_row + 1, tmp_column));
				box[tmp_row + 1][tmp_column] = 1;
			}
		}
		//left
		if (tmp_column != 1) {
			if (box[tmp_row][tmp_column - 1] == 0) {
				q.push(make_pair(tmp_row, tmp_column - 1));
				box[tmp_row][tmp_column - 1] = 1;
			}
		}
		//right
		if (tmp_column != column) {
			if (box[tmp_row][tmp_column + 1] == 0) {
				q.push(make_pair(tmp_row, tmp_column + 1));
				box[tmp_row][tmp_column + 1] = 1;
			}
		}


	}
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
			if (box[i][j] == 0) {
				cout << -1 << endl;
				return;
			}

	cout << count << endl;

}


int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int tomato;
	cin >> column >> row;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cin >> tomato;
			box[i][j] = tomato;
		}
	}
	BFS();
}