#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int n, k;
	cin >> n >> k;

	int bm = 1 << k;

	// If bit is set, unset it
	if((n & bm) == bm){
		cout << "The bit is set, the new number is: " << (n & (~bm)) << endl;
	} else {
		cout << "The bit is already off" << endl;
	}

	return 0;
}
