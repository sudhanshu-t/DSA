#include <iostream>
using namespace std;

int swap(int arr[], int i, int jc){
	int t = arr[i];
	arr[i] = arr[jc - 1];
	arr[jc - 1] = t;

	return 0;
}

int main(int argc, char** argv){
	int arr[] = {2,5,1,4,3,0};
	int n = sizeof(arr) / sizeof(int);

	for(int jc = 1; jc <= n - 1; jc++){
		for(int i = jc; i < n; i++){
			if(arr[jc-1] > arr[i]){
				swap(arr, i, jc);
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}
