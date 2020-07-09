#include <iostream>
using namespace std;

void swap(int arr[], int l, int h){
	int temp = arr[l];
	arr[l] = arr[h];
	arr[h] = temp;
}

int main(int argc, char** argv){
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(int);

	int l = 0, h = n - 1;
	while(l < h){
		swap(arr, l, h);
		l++;
		h--;
	}

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}
