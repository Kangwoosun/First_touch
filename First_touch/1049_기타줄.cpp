#include <iostream>
using namespace std;

int main() {
	int N, M;
	int Brend[100][2];
//	int pack, Individual;
	int min_pack = 1000, min_Individual = 1000;
	int sum;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> Brend[M][0] >> Brend[M][1];
		if (min_pack > Brend[M][0])
			min_pack = Brend[M][0];
		if (min_Individual > Brend[M][1])
			min_Individual = Brend[M][1];
	}
	if (min_pack > 6 * min_Individual)
		sum = min_Individual * N;
	else if (min_pack > (N % 6) * min_Individual)
		sum = min_pack * (N / 6) + min_Individual * (N % 6);
	else
		sum = min_pack * (N / 6 + 1);
	cout << sum << endl;
}