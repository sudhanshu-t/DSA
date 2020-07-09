#include <iostream>
using namespace std;

int main(int arcg, char** argv){
	int n;
	cin >> n;

	int spaces = n/2;
	int stars = 1;

	int var;
	for(int r = 1; r <= n; r++){
		var = (r <= n/2 + 1) ? r : n-r+1 ;

		for(int i = 0; i < spaces; i++){
			cout << " ";
		}

		for(int i = 0; i < stars; i++){
			cout << var;
			if(i < n/2)
				var++;
			else
				var--;
		}

		if(r <= n/2){
			spaces--;
			stars += 2;
		} else {
			spaces++;
			stars -= 2;
		}

		cout << endl;
	}

	return 0;
}

