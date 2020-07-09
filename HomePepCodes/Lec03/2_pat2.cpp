#include<iostream>
using namespace std;

int main(int argc, char** argv){
	int n;
	cin >> n;

	int count = 1;

	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= r; c++){
			cout << count << " ";
			count++;
		}
		cout << endl;
	}

	return 0;
}
