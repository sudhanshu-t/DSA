#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int o1, o2, r1, r2, carry = 0, digit;
	cin >> o1 >> o2;

	int sum = 0, power = 1;
	while(o1 != 0 || o2 != 0 || carry != 0){
		r1 = o1 % 10;
		r2 = o2 % 10;

		o1 /= 10;
		o2 /= 10;

		if(r1 + r2 + carry >= 8){
			digit = r1 + r2 + carry - 8;
			carry = 1;
		} else {
			digit = r1 + r2 + carry;
			carry = 0;
		}

		sum += power * digit;
		power *= 10;
	}

	cout << sum << endl;
	return 0;
}
