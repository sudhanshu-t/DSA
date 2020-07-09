#include <iostream>
using namespace std;

int octAdd(int o1, int o2){
	int r1, r2, digit, carry = 0, sum = 0, power = 1;

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

		sum += digit * power;
		power *= 10;
	}

	return sum;
}

int main(int argc, char** argv){
	int o1, o2, r1, r2, digit, carry = 0, mul = 0, mul1 = 0, power = 1, power1 = 1;
	cin >> o1 >> o2;

	while(o2 != 0){
		r2 = o2 % 10;
		o2 /= 10;
		power1 = 1;
		mul1 = 0;

		int safe = o1;
		while(o1 != 0 || carry != 0){
			r1 = o1 % 10;
			o1 /= 10;

			if(r1 * r2 + carry >= 8){
				digit = (r1 * r2 + carry) % 8;
				carry = (r1 * r2 + carry) / 8;
			}
			else {
				digit = r1 * r2 + carry;
				carry = 0;
			}

			mul1 += digit * power1;
			power1 *= 10;

//			cout << mul1 << endl;
		}

		cout << mul1 << endl;

		o1 = safe;
		mul = octAdd(mul, power * mul1);
		power *= 10;
	}

	cout << mul << endl;

	return 0;
}
