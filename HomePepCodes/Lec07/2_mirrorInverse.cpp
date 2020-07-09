#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int arr[] = {2, 3, 0, 1, 4};

	int n = sizeof(arr) / sizeof(int);

	for(int i = 0; i < n; i++){
		if(arr[arr[i]] != i){
			cout << "Not Mirror Inverse" << endl;
			return 0;
		}
	}

	cout << "Mirror Inverse" << endl;
	return 0;
}
