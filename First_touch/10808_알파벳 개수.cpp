#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;
	int alphabet[26] = { 0 };
	for (auto i : input) {
		alphabet[i - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";
}