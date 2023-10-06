#include <iostream>
#include <ctime>

using namespace std;

const int ARR_LENGHT = 100;

void swapEl(int arr[], int firstIndex, int secondIndex);
int split(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

int main() {
	srand(time(NULL));

	int arr[ARR_LENGHT];

	cout << "Input " << ARR_LENGHT << " arr values:" << endl;
	for (int i = 0; i < ARR_LENGHT; i++) {
		arr[i] = rand() % 50;
	}

	quickSort(arr, 0, ARR_LENGHT - 1);

	for (int i = 0; i < ARR_LENGHT; i++) {
		if (i % 10 == 0) {
			cout << endl;
		} else {
			cout << arr[i] << "\t";
		}
	}
	cout << endl;
}

void swapEl(int arr[], int firstIndex, int secondIndex) {
	int tmp = arr[firstIndex];
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = tmp;
}

int split(int arr[], int start, int end) {
	int leader = arr[end];
	int lIndex = start;

	for (int i = start; i < end; i++) {
		if (arr[i] <= leader) {
			swapEl(arr, lIndex, i);
			lIndex++;
		}
	}

	swapEl(arr, lIndex, end);

	return lIndex;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}

	int leader = split(arr, start, end);

	quickSort(arr, start, leader - 1);
	quickSort(arr, leader + 1, end);
}