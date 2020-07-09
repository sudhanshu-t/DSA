#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int n;
	cin >> n;

	int count = 0;

	while(n != 0){
		int rsbm = (n & -n);
		n = n ^ rsbm;

		count++;
	}

	cout << count << endl;

	return 0;
}
