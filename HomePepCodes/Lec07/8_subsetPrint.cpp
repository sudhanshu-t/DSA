#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(int);

	for(int i = 0; i < 1 << n; i++){
		for(int j = n - 1; j >= 0; j--){
			int bm = 1 << j;
			if((i & bm) == bm){
				cout << arr[n-j-1] << " ";
			} else {
				cout << "- ";
			}
		}
		cout << endl;
	}

	return 0;
}
