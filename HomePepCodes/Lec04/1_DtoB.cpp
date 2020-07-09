#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int dec;
	cin >> dec;

	int bin = 0, power = 1; // 0th power of 10
	while(dec != 0){
		int rem = dec % 2;
		dec /= 2;

		bin += rem * power;
		power *= 10;
	}

	cout << bin << endl;
	return 0;
}
