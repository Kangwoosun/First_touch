#include <iostream>
#include <queue>
using namespace std;

int main() {
	int queue_size, number_choice;
	int choice_location[50], count =0;
	int location[50],tmp_location[50], current_size;
	cin >> queue_size >> number_choice;
	for (int i = 0; i < number_choice; i++) {
		cin >> choice_location[i];
	}
	for (int i = 0; i < queue_size; i++) {
		location[i] = i + 1;
	}
	current_size = queue_size;
	for (int i = 0; i < number_choice; i++) {
		for (int j = 0; j < current_size; j++) {
			if (choice_location[i] == location[j]) {
				count += (j <= current_size - j ? j : current_size - j);
				for (int k = 0; k < current_size; k++)
					tmp_location[k] = location[k];
				current_size--;
				for (int k = 0; k < current_size; k++) {
					if (j+k < current_size) 
						location[k] = tmp_location[j + 1 + k];
					else 
						location[k] = tmp_location[j + k - current_size];
				}
				break;
			}

		}
	}
	cout << count << '\n';

}