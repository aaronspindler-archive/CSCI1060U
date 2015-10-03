#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_ELEMENTS = 1000000;
int numsArray[NUM_ELEMENTS];

void sortArray(int(&numsArray)[NUM_ELEMENTS]);
void swap(int& a, int& b);

int main() {
	clock_t startTime = clock();
	srand(time(NULL));
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		numsArray[i] = rand();
	}
	sortArray(numsArray);
	clock_t endTime = clock();
	float timeDiff = float(endTime - startTime) / CLOCKS_PER_SEC;
	cout << "The time it took to sort: " << NUM_ELEMENTS << " elements is " << timeDiff << " seconds." << endl;
	return 0;
}

void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
	return;
}

void sortArray(int(&numsArray)[NUM_ELEMENTS]) {
	for (int x = 0; x < (NUM_ELEMENTS - 1); x++) {
		for (int y = (x + 1); y < NUM_ELEMENTS; y++) {
			if (numsArray[x] > numsArray[y]) {
				swap(numsArray[x], numsArray[y]);
			}
		}
	}
	return;
}
