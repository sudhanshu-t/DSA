#include <iostream>
using namespace std;

int main(int arc, char** argv){
	int n;
	cin >> n;

	int stars = 1;
	int spaces = 2*n - 3;
	int var;

	for(int r = 1; r <= n; r++){
		var = 1;
		for(int i = 0; i < stars; i++){
			cout << var;
			var++;
		}

		for(int i = 0; i < spaces; i++){
			cout << " ";
		}

		var = (r == n) ? r-1 : r;
		stars = (r == n) ? stars-1 : stars;
		for(int i = 0; i < stars; i++){
			cout << var;
			var--;
		}

		spaces -= 2;
		stars++;

		cout << endl;
	}

	return 0;
}
