#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int arr[] = {1,1,1,2,2,2,3,4,4,4,5,5,5};
	int n = sizeof(arr) / sizeof(int);

	int u = 0;
	for(int b = 0; b < 3; b++){
		int bm = 1 << b;
		int count = 0;
		for(int i = 0; i < n; i++){
			if((arr[i] & bm) == bm)
				count++;
		}

		if(count % 3 == 1){
			u += 1 << b;
		}
	}

	cout << u << endl;
	return 0;
}
