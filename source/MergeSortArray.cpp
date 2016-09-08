#include <iostream>
using namespace std;

void MergeArrays(int *, int *, int, int, int);

void MergeSort(int *arr, int *temp, int start, int end){
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	MergeSort(arr, temp, start, mid);
	MergeSort(arr, temp, mid + 1, end);

	MergeArrays(arr, temp, start, mid, end);
}

void MergeArrays(int *arr, int *temp, int start, int mid, int end){
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end){
		if (arr[i]<arr[j]){
			temp[k] = arr[i];
			i++;
		}
		else{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}

	for (int l = i; l <= mid; l++, k++){
		temp[k] = arr[l];
	}

	for (int l = j; l <= end; l++, k++){
		temp[k] = arr[l];
	}

	for (int l = start; l <= end; l++){
		arr[l] = temp[l];
	}
}

/*int main() {
	int arr[8] = { 2, 1, 9, 4, 4, 56, 90, 3 };
	int temp[8];
	cout << "Before sorting" << endl;
	MergeSort(arr, temp, 0, 8 - 1);
	cout << "Array after sorting" << endl;
	for (int i = 0; i<8; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}*/