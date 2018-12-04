#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

pair<int, int> location_swan[2];

int R, C;
int lake[1501][1501];
bool visit[1501][1501];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0,0,1,-1 };


queue<pair<int, int>> q_ice;
bool is_in(int row, int column) {
	return ((1 <= row && row <= R && 1 <= column && column <= C) ? true : false);
}

int get_check_day(int day) {
	pair<int, int> current_location;
	int current_row, current_column;
	int check_row, check_column;
	queue <pair<int, int>> q;
	q.push(location_swan[0]);
	
	while (!q.empty()) {
		current_location = q.front();
		current_row = current_location.first;
		current_column = current_location.second;
		q.pop();
		if (location_swan[1].first == current_row && location_swan[1].second == current_column)
			return 1;
		for (int i = 0; i < 4; i++) {
			check_row = current_row + mx[i];
			check_column = current_column + my[i];
			if (is_in(check_row, check_column) && !visit[check_row][check_column] && lake[check_row][check_column] <= day) {
				visit[check_row][check_column] = true;
				q.push(make_pair(check_row, check_column));
			}
		}

	}
	return 0;
}

int set_day() {
	int max = 0;
	pair<int, int> current_location;
	int current_row, current_column;
	int check_row, check_column;
	
	while (!q_ice.empty()) {
		current_location = q_ice.front();
		q_ice.pop();
		current_row = current_location.first;
		current_column = current_location.second;
		for (int i = 0; i < 4; i++) {
			check_row = current_row + mx[i];
			check_column = current_column + my[i];
			if (is_in(check_row, check_column) && !visit[check_row][check_column] && lake[check_row][check_column] == 1) {
				visit[check_row][check_column] = true;
				q_ice.push(make_pair(check_row, check_column));
				lake[check_row][check_column] = lake[current_row][current_column] + 1;
				if (max < lake[check_row][check_column])
					max = lake[check_row][check_column];
			}
		}
	}
	return max;
}

void BFS(int row, int column) {
	visit[row][column] = true;
	queue<pair<int, int>>q;
	pair<int, int> current_location;
	int current_row, current_column;
	int check_row, check_column;
	q.push(make_pair(row, column));
	
	while (!q.empty()) {
		current_location = q.front();
		q.pop();
		current_row = current_location.first;
		current_column = current_location.second;

		for (int i = 0; i < 4; i++) {
			check_row = current_row + mx[i];
			check_column = current_column + my[i];
			
			if (is_in(check_row, check_column) && !visit[check_row][check_column]) {
				if (lake[check_row][check_column] < 1) {
					visit[check_row][check_column] = true;
					q.push(make_pair(check_row, check_column));
				}
					
				else if (lake[check_row][check_column]==1) {
					visit[check_row][check_column] = true;
					q_ice.push(make_pair(check_row, check_column));
				}
			}


		}

	}

}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int start, end, middle;
	string input;
	cin >> R >> C;
	int x = 0;
	int day = 0;
	for (int i = 1; i <= R; i++) {
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			switch (input[j])
			{
			case '.':
				lake[i][j+1] = 0;
				break;
			case 'X':
				lake[i][j+1] = 1;
				break;
			case 'L':
				lake[i][j+1] = -1;
				location_swan[x] = make_pair(i, j+1);
				x++;
				break;

			default:
				break;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!visit[i][j] && lake[i][j] <= 0)
				BFS(i, j);
		}
	}
	start = 0;
	end = set_day();
	while (start<=end) { 
		memset(visit, false, sizeof(visit));
		middle = (start + end) / 2;
		if (get_check_day(middle)) {
			end = middle-1;
		}
		else {
			start = middle+1;
		}
		
	}
	cout << start << endl;
	return 0;
}