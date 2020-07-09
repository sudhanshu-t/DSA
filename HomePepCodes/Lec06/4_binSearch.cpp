#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	int l = 0, h = n - 1, mid, k;
	cin >> k;

	while(l <= h){
		mid = l + ((h - l) >> 1);

		if(arr[mid] == k){
			cout << mid << endl;
			return 0;
		} else if(k > arr[mid]){
			l = mid + 1;
		} else {
			h = mid - 1;
		}
	}
	cout << "Not Found" << endl;
	return 0;
}

