#include <iostream>

using namespace std;

void swap(int arr[], int i){
	int t = arr[i];
	arr[i] = arr[i+1];
	arr[i+1] = t;

	return;
}
int main(int argc, char** argv){
	int arr[] = {4, 2, 1, 6, 3, 8};
	int n = sizeof(arr) / sizeof(int);

	for(int jc = 1; jc <= n - 1; jc++){
		for(int i = 0; i < n - jc; i++){
			if(arr[i] > arr[i+1]){
				swap(arr, i);
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}
