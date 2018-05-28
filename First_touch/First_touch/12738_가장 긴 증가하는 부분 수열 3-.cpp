#include <iostream>
using namespace std;

int main() {
	int X[1000000] = { 0, };
	int N, max = -1000000001, check, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> check;
		if (max < check) {
			max = check;
			count++;
		}
	}
	cout << count;
}