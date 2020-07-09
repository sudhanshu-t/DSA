#include<iostream>
using namespace std;

int main(int argc, char** argv){
	int sieve[100] = {0};

	// Making the Sieve
	for(int i = 2; i <= 10; i++){
		for(int j = 2; i*j < 100; j++){
			sieve[i*j] = 1;
		}
	}

	// Printing the Sieve
	for(int i = 2; i < 100; i++){
		if(sieve[i] == 0)
			cout<<i<<endl;
	}

	return 0;
}
