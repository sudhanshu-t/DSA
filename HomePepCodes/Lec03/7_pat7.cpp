#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int n;
	cin >> n;

	int spaces = n/2;
	int stars = 1;

	for(int r = 1; r <= n; r++){
		for(int i = 0; i < spaces; i++){
			cout << " ";
		}

		for(int i = 0; i < stars; i++){
			cout << "*";
		}

		if(r <= n/2){
			stars += 2;
			spaces--;
		}
		else {
			stars -= 2;
			spaces++;
		}

		cout << endl;
	}

	return 0;
}
