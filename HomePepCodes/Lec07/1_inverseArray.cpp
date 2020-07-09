#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int arr[] = {4, 2, 0, 1, 3};
	int inv[100], n = sizeof(arr) / sizeof(int);

	for(int i = 0; i < n; i++){
		inv[arr[i]] = i;
	}

	for(int i = 0; i < n; i++){
		cout << inv[i] << " ";
	}

	cout << endl;

	return 0;
}
