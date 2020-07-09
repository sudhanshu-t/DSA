#include<iostream>
using namespace std;

int main(int argc, char** argv){
	int n;
	cin >> n;

	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= r; c++){
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
