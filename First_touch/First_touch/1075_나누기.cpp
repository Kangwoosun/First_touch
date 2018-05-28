#include <iostream>
using namespace std;


int main() {
	int N, F, S;
	cin >> N >> F;
	
	N = (N / 100) * 100;
	S = F*(N / F);

	if (S == N) {
		cout << "00";
		return 0;
	}
	S = S - N + F;

	cout.width(2);
	cout.fill('0');
	cout << S;

}