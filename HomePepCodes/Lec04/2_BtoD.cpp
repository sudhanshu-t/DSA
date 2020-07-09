#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int bin;
	cin >> bin;

	int power = 1; // 0th power of 2 (Source base)
	int dec = 0, rem;

	while(bin != 0){
		rem = bin % 10;
		bin /= 10;

		dec += rem * power;
		power *= 2;
	}

	cout << dec << endl;
	return 0;
}
