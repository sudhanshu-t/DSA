#include <iostream>
using namespace std;

void swap(int arr[], int l, int h){
	int temp = arr[l];
	arr[l] = arr[h];
	arr[h] = temp;
}

void reverse(int arr[], int l, int h){
	while(l < h){
		swap(arr, l, h);
		l++;
		h--;
	}
}

int main(int argc, char** argv){
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(int);

	int r;
	cin >> r;
	r = (r < 0)? n + r : r;

	int l = 0, h = n-1;
	reverse(arr, l, r-1);
	reverse(arr, r, h);
	reverse(arr, l, h);

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}
