#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {

	int sum = 0;
	bool a = false;
	int count =0;
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++){
		if (input[i]== ')') {
			
			if (a == true) {
				sum += count - 1;
			}
			else {
				sum++;
			}
			a = false;
			count--;
		}
		else {
			count++;
			a = true;
		}


	}
	cout << sum;
}