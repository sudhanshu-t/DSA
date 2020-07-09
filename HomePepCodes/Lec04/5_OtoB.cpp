#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int oct;
	cin >> oct;

	int power = 1; // 0th power of 1000
	int bin = 0, rem;

	while(oct != 0){
		rem = oct % 10;
		oct /= 10;

		switch(rem){
			case 0:
			rem = 0;
			break;

			case 1:
			rem = 1;
			break;

			case 2:
			rem = 10;
			break;

			case 3:
			rem = 11;
			break;

			case 4:
			rem = 100;
			break;

			case 5:
			rem = 101;
			break;

			case 6:
			rem = 110;
			break;

			case 7:
			rem = 111;
			break;

			default:
			return 1;
		}

		bin += rem * power;
		power *= 1000;
	}

	cout << bin <<endl;
	return 0;
}
