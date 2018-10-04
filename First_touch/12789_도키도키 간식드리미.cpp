#include <iostream>
#include <stack>
using namespace std;

int main() {
	int student[1000];
	int line[1000] = { 0 };
	int N;
	int count = 0;
	stack<int> st;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> student[i];
		line[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		if (line[count] == student[i])
			count++;
		
		else  {
			if (st.empty()) {
				st.push(student[i]);
				continue;
			}
			if (line[count] == st.top()) {
				i--;
				count++;
				st.pop();
			}
			else {
				st.push(student[i]);
			}
		}
	}
	while (!st.empty()) {
		if (line[count] == st.top()) {
			count++;
		}
		st.pop();
	}
	if (count == N)
		cout << "Nice" << '\n';
	else
		cout << "Sad" << '\n';
}