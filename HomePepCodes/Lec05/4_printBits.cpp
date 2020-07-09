#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int n;
	cin >> n;

	for(int i = 31; i >= 0; i--){
		int bm = 1 << i;
		if((n & bm) == 0)
			cout << "0";
		else
			cout << "1";
	}

	return 0;
	}
