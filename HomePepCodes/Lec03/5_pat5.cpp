#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int n;
	cin >> n;

	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++){
			if(r == c || r + c + 1 == n)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}
