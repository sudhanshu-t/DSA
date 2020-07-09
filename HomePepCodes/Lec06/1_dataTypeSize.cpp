#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char** argv){
	//cout << INT_MAX << " " << INT_MIN << endl;

	int power = 1;
	for(int i = 1; i <= 31; i++){
		power *= 2;
		cout << power << endl;
	}

//	cout << power << endl;
	return 0;
}
