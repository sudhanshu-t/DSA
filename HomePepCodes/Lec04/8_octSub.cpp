#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int o1, o2, r1, r2, borr = 0, digit, diff = 0, power = 1;
	cin >> o1 >> o2;

	while(o1 != 0 || o2 != 0 || borr != 0){
		r1 = o1 % 10;
		r2 = o2 % 10;

		o1 /= 10;
		o2 /= 10;

		if(r1 + borr >= r2){
			digit = r1 + borr - r2;
			borr = 0;
		} else {
			digit = r1 + borr + 8 - r2;
			borr = -1;
		}

		diff += power * digit;
		power *= 10;
	}

	cout << diff << endl;
	return 0;
}
