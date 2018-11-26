#include <iostream>
#include <string.h>
using namespace std;

int arr[101][101];
//int output[101][101];
bool visit[101];
int N;
bool can_go(int start, int end) {

	if (arr[start][end])
		return true;

	visit[start] = true;
	bool check = false;

	for (int i = 1; i <= N; i++) {
		if (arr[start][i])
			if (!visit[i])
				check = can_go(i, end);
		if (check)
			return check;
	}
	return false;
}
void find(int start) {

	for (int i = 1; i <= N; i++) {
		if (arr[start][i] == 0) {
			if (can_go(start, i)) {
				arr[start][i] = 1;
			}
			memset(visit, false, sizeof(visit));
		}
	}

}


int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int input;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> input;
			arr[i][j] = input;
		}
	for (int i = 1; i <= N; i++) {
		find(i);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}