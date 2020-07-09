#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int arr[] = {2, 3, 7, -9, 6, 7, -20, 1, 2, 3, 11};
	int n = sizeof(arr) / sizeof(int);

	int lsum = 0, gsum = 0, lst = 0, gst = 0, lend = 0, gend = 0;

	for(int i = 0; i < n; i++){
		if(lsum + arr[i] > arr[i]){
			lsum += arr[i];
			lend = i;
		} else {
			lsum = arr[i];
			lst = i;
			lend = i;
		}

		if(lsum > gsum){
			gsum = lsum;
			gst = lst;
			gend = lend;
		}
	}

	for(int i = gst; i <= gend; i++){
		cout << arr[i] << " ";
	}
	cout << endl << gsum << endl;

	return 0;
}
