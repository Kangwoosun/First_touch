#include <iostream>
using namespace std;

int X[1000001] = { 0, };
int min(int a, int b) {
	return (a < b ? a : b);
}
int Xdp(int n) {

		for (int i = 6; i <= n; i++) {
			X[i] = X[i-1] + 1;
			if (!(i % 3))
				X[i] = min(X[i], X[i/3] + 1);
			if (!(i % 2))
				X[i] = min(X[i], X[i/2] + 1);

		}
	return X[n];
}


int main() {
	
	X[1] = 0;
	X[2] = 1;
	X[3] = 1;
	X[4] = 2;
	X[5] = 3;

	int N;
	cin >> N;
	cout << Xdp(N);
}