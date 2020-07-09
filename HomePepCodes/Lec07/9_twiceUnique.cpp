#include <iostream>
using namespace std;
int main(int argc, char** argv){
	int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
	int n = sizeof(arr) / sizeof(int);

	int u = 0;
	for(int i = 0; i < n; i++){
		u ^= arr[i];
	}

	cout << u << endl;

	return 0;
}
