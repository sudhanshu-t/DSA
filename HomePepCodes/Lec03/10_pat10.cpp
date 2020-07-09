#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int n, array[100], max = 0;
	cin >> n;

	// Taking I/P to the array
	for(int i = 0; i < n; i++){
		cin >> array[i];
		max = (array[i] >= max) ? array[i] : max;
	}

	for(int i = 1; i <= max; i++){
		for(int j = 0; j < n; j++){
			if(i <= max - array[j])
				cout << " ";
			else
				cout << "*";
		}

		cout << endl;
	}

	return 0;
}
