#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int arr[] = {1, 2, 2, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(int);

	int l = 0, h = n - 1, mid, idx;
	int key;
	cin >> key;

	while(l <= h){
		mid = l + ((h - l) >> 1);

		if(arr[mid] == key){
			idx = mid;
			l = mid + 1;
		} else if(key > arr[mid]){
			l = mid + 1;
		} else {
			h = mid - 1;
		}
	}

	cout << idx << endl;
	return 0;
}
