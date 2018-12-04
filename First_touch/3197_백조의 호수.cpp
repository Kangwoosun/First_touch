#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

int daty = 1;
int R, C;
int lake[1501][1501];
bool visit[1501][1501];
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0,0,1,-1 };
bool is_in(int row, int column) {
	return ((1 <= row && row <= R && 1 <= column && column <= C) ? true : false);
}

int main() {
	queue<pair<int, int>> q;
	string input;
	int day = 1;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			switch (input[j])
			{
			case '.':
				lake[i][j] = -2;
				break;
			case 'X':
				lake[i][j] = 0;
				break;
			case 'L':
				lake[i][j] = -1;
				break;

			default:
				break;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if()
		}
	}

}