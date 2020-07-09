#include <iostream>
using namespace std;

int main(int argc, char** arv){
	int n;
	cin >> n;

	int stars = n / 2 + 1;
	int spaces = 1;

	for(int r = 0; r < n; r++){
		for(int i = 0; i < stars; i++){
			cout << "*";
		}

		for(int i = 0; i < spaces; i++){
			cout << " ";
		}

		for(int i = 0; i < stars; i++){
                        cout << "*";
                }

		if(r < n / 2){
			stars--;
			spaces += 2;
		}
		else {
			stars++;
			spaces -= 2;
		}

		cout << endl;
	}

	return 0;
}
