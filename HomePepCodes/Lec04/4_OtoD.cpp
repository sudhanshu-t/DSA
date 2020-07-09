#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int oct;
	cin >> oct;

	int power = 1; // 0th power of 8
	int rem, dec = 0;

	while(oct != 0){
		rem = oct % 10;
		oct /= 10;

		dec += rem * power;
		power *= 8;
	}

	cout << dec << endl;
	return 0;
}
