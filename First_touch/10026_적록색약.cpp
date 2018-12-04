#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

/* R = 1  R,G = 1
* G = 2
* B = 3  B = 3
*/

int handicap_area[101][101];
int unhandicap_area[101][101];
int count_check = 0;
int N;
bool visit[101][101];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
bool is_in(int row, int column) {
	return ((1 <= row && row <= N && 1 <= column && column <= N) ? true : false);
}

void BFS(int row, int column, int area[][101]) {
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
				area[current_row][current_column] == area[check_row][check_column]) {
				q.push(make_pair(check_row, check_column));
				visit[check_row][check_column] = true;
			}
		}

	}

	count_check++;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	string input;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 0; j<input.length(); j++)
			switch (input[j])
			{
			case 'R':
				handicap_area[i][j + 1] = 1;
				unhandicap_area[i][j + 1] = 1;
				break;
			case 'G':
				handicap_area[i][j + 1] = 1;
				unhandicap_area[i][j + 1] = 2;
				break;
			case 'B':
				handicap_area[i][j + 1] = 3;
				unhandicap_area[i][j + 1] = 3;
				break;
			default:
				break;
			}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j])
				BFS(i, j, unhandicap_area);
		}
	}
	cout << count_check << " ";
	memset(visit, false, sizeof(visit));
	count_check = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j])
				BFS(i, j, handicap_area);
		}
	}
	cout << count_check;
}