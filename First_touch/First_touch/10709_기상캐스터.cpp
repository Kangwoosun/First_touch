#include <iostream>
using namespace std;
int main() {
	char cloud[101][101];
	int output[101][101] = { 0, };
	int H, W, count_cloud =-1;
	bool check = false;
	cin >> H >> W;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) 
			cin >> cloud[i][j];
		
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (cloud[i][j] == 'c') {
				check = true;
				count_cloud = 0;
			}
			output[i][j] = count_cloud;
			if (check) {
				count_cloud++;
			}
		}
		count_cloud = -1;
		check = false;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++)
			cout << output[i][j] << " ";

		cout << '\n';
	}

}