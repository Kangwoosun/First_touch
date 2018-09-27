#include <iostream>
#include <queue>
using namespace std;

int val[101];
int main() {
	queue<int> qu;
	
	int test_case, N,M,input;
	int count = 0, val_size, max, max_count;
	int check;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> input;
			val[j] = input;
			qu.push(input);
		}
		val_size = N;
		check = M;
		while (1) {
			
			max = 0;
			for (int k = 0; k < val_size; k++) {
				if (max < val[k]) {
					max = val[k];
					max_count = k;
				}
			}
			while (1) {
				int tmp = qu.front();
				qu.pop();
				if (tmp == max) {
					count++;
					break;
				}
				else {
					qu.push(tmp);
					if (check == 0)
						check = qu.size();
				}
				check--;
			}
			if (!check)
				break;
			for (int l = max_count; l < val_size-1; l++) {
				val[l] = val[l + 1];
			}
			val_size--;
			check--;
		}
		cout << count << '\n';
		count = 0;
		while (!qu.empty())
			qu.pop();
	}
}