#include <iostream>
using namespace std;

#define INT_MAX 2147483647


void heap_push(int value);
int heap_pop();
int heap[100001] = { 0,};
int size_count = 1;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 0) {
			if (size_count == 1) 
				cout << 0 << '\n';
			else 
				cout << heap_pop() << '\n';
		}
		else {
			heap_push(input);
		}
	}
}
void heap_push(int value) {

	heap[size_count] = value;
	size_count++;
	int hold;
	for (int i = size_count-1; i != 1; i /= 2) {
		
		if (heap[i] < heap[i / 2]) {
			hold = heap[i / 2];
			heap[i / 2] = heap[i];
			heap[i] = hold;
		}
		else
			break;

	}
	return;
}
int heap_pop() {
	int min = heap[1];
	int hold, compare_location;
	heap[1] = heap[size_count-1];
	heap[size_count - 1] = INT_MAX;
	size_count--;
	
	for (int i = 1; 2*i < size_count;) {
		compare_location = (heap[2 * i] < heap[2 * i + 1] ? 2*i : 2*i+1);
		if (heap[i] > heap[compare_location]) {
			hold = heap[compare_location];
			heap[compare_location] = heap[i];
			heap[i] = hold;
		}
		else
			break;
		i = compare_location;
	}



	return min;

}
