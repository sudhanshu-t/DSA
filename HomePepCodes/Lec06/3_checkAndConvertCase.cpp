#include <iostream>
using namespace std;
int main(int argc, char** argv){
/*
	char c = (char) -97;
	cout << c << endl;

*/	char c;
	cin >> c;

	if(c >= 65 && c <= 90){
		cout << "Uppercase " << (char) (c - 'A' + 'a') << endl;
	} else {
		cout << "Lowercase " << (char) (c - 'a' + 'A') << endl;
	}

	return 0;
}
