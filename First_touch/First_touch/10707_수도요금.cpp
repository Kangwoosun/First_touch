#include <iostream>
using namespace std;
int main() {
	int A, B, C, D, P;
	int X, Y;
	cin >> A >> B >> C >> D >> P;
	X = A * P;
	Y = B;
	if (P > C) {
		Y += D * (P - C);
	}
	cout << (X > Y ? Y : X);
}