#include <iostream>
using namespace std;


//int lion_size[100001] = {0,3,7,};
//int last_pos = 2;
//int lion(int n) {
//
//	if (lion_size[n] == 0) {
//		for (int i = last_pos+1; i <= n; i++) {
//			lion_size[i] += lion_size[i - 1];
//
//			for (int j = i - 2; j >= 1; j--) {
//				lion_size[i] += 2 * lion_size[j];
//			}
//			lion_size[i] %= 9901;
//		}
//		last_pos = n;
//	}
//	return lion_size[n];
//}
//
//int main() {
//
//	int N;
//	cin >> N;
//	cout << lion(N) % 9901;
//}

int lion_size[100001][3] = {  };
int last_pos = 1;

int lion(int n) {
	int sum = 0;
	if (lion_size[n][0] == 0) {
				for(int i = last_pos+1; i<=n; i++){
					lion_size[i][0] = (lion_size[i - 1][0] + lion_size[i - 1][1] + lion_size[i - 1][2]) % 9901;
					lion_size[i][1] = (lion_size[i - 1][0] + lion_size[i - 1][2]) % 9901;
					lion_size[i][2] = (lion_size[i - 1][0] + lion_size[i - 1][1]) % 9901;
				}
				last_pos = n;
	}
	sum += (lion_size[n][0] + lion_size[n][1] + lion_size[n][2]) % 9901;
	return sum;
}


int main() {
	lion_size[1][0] = 1;
	lion_size[1][1] = 1;
	lion_size[1][2] = 1;
	int N;
	cin >> N;
	cout << lion(N);
}