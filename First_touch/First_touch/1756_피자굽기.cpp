#include <iostream>
using namespace std;


int oven[300000] = {};
int pizza[300000] = {};
int main() {
	int count = 0;
	int pizzanum;
	int oven_depth;
	
	cin >> oven_depth >> pizzanum;
	cin >> oven[0];
	for (int i = 1; i < oven_depth; i++) {
		cin >> oven[i];
		if (oven[i]>oven[i-1]) {
			oven[i] = oven[i - 1];
		}
	}
	for (int i = 0; i < pizzanum; i++)
		cin >> pizza[i];

	/*for (int i = 0; i < pizzanum; i++) {
		for (int j = 0; j < oven_depth; j++) {
			if (oven[j] < pizza[i] || oven[j] == 0) {
				oven[j - 1] = 0;
				count = j;
				break;
			}
		}
	}*/
	int m;
	int i = 0, j = oven_depth;
	for (int k = 0; k < pizzanum; k++) {
		while (i < j) {
			m = (i + j) / 2;
			if (pizza[k] == oven[m])
				break;
			else if (pizza[k] < oven[m]) 
				i = m + 1;
			else 
				j = m - 1;
		}
		if (i < j) {
			for (m; pizza[k] <= oven[m]; m++) {
				if (m >= count)
					break;
			}
			count = m;
		}
		i = 0;
		j = count - 1;
	}



	cout << count;

	


}