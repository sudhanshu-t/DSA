#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int bin;
	cin >> bin;

	int power = 1; // 0th power of 10
	int oct = 0, rem;

	while(bin != 0){
		rem = bin % 1000;
		bin /= 1000;

		switch(rem){
			case 0:
			rem = 0;
			break;

			case 1:
			rem = 1;
			break;

			case 10:
			rem = 2;
			break;

			case 11:
			rem = 3;
			break;

			case 100:
			rem = 4;
			break;

			case 101:
			rem = 5;
			break;

			case 110:
			rem = 6;
			break;

			case 111:
			rem = 7;
			break;

			default:
			return 1;
		}

		oct += power * rem;
		power *= 10;
	}

	cout << oct << endl;
	return 0;
}
