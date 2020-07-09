#include <iostream>
using namespace std;

int main(int argc, char** arv){
	int dec;
	cin >> dec;

	int power = 1; // 0th power of 10
	int oct = 0, rem;

	while(dec != 0){
		rem = dec % 8;
		dec /= 8;

		oct += power * rem;
		power *= 10;
	}

	cout << oct <<endl;
	return 0;
}
