#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int input[1024];
	int K;
	cin >> K;
	int val;
	int size = pow(2, K);
	for (int i = 1; i < size; i++) cin >> input[i];
	int d = size;
	int	start_location = size / 2;
	int count = 1;
	for (int i = 0; i < K; i++) {
		val = start_location;
		for (int j = 0; j < count; j++) {
			cout << input[val] << " ";
			val += d;
		}
		cout << endl;
		start_location /= 2;
		count *= 2;
		d /= 2;
	}


}