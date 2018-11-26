#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int row, column;
int miro[101][101];
int visit[101][101];

int how_much() {
	queue<pair<int, int>> q;
	pair<int, int> current_location;
	
	int current_row, current_column;

	q.push(make_pair(1, 1));
	visit[1][1] = 1;
	while (!q.empty()) {
		current_location = q.front();
		q.pop();
		current_row = current_location.first;
		current_column = current_location.second;
		
		if (current_row == row && current_column == column)
			break;

		//go_top
		if (current_row != 1 && visit[current_row - 1][current_column] == 0 && miro[current_row-1][current_column] == 1) {
			q.push(make_pair(current_row - 1, current_column));
			visit[current_row - 1][current_column] = visit[current_row][current_column] + 1;
		}
		//go_bottom
		if (current_row != row && visit[current_row + 1][current_column] == 0 && miro[current_row + 1][current_column] == 1) {
			q.push(make_pair(current_row + 1, current_column));
			visit[current_row + 1][current_column] = visit[current_row][current_column] + 1;
		}
		//go_left
		if (current_column != 1 && visit[current_row][current_column -1] == 0 && miro[current_row][current_column-1] == 1) {
			q.push(make_pair(current_row, current_column-1));
			visit[current_row ][current_column-1] = visit[current_row][current_column] + 1;
		}

		//go_right
		if (current_column != column && visit[current_row][current_column+1] == 0 && miro[current_row][current_column+1] == 1) {
			q.push(make_pair(current_row, current_column+1));
			visit[current_row][current_column+1] = visit[current_row][current_column] + 1;
		}

	}
	
	return visit[row][column];
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string can_go;
	cin >> row >> column;
	for (int i = 1; i <= row; i++) {
		cin >> can_go;
		for (int j = 1; j <= can_go.length(); j++) {
			miro[i][j] = can_go[j - 1] - '0';
		}

	}
	cout << how_much() << endl;
}
