#include<iostream>
using namespace std;

int main(int argc, char** argv){
	int n, r;
	cin>>n>>r;

	int nod = 0, safe = n;
	// Calculating num of digits
	while(n != 0){
		n = n / 10;
		nod++;
	}

	n = safe;

	r = r % nod;
	r = (r < 0) ? nod + r : r; // Dealing with negative r

	int div = 1, mul = 1;
	for(int i = 0 ; i < nod; i++){
		if(i < r){
			div *= 10;
		}

		else {
			mul *= 10;
		}
	}

	int q = n / div;
	int rem = n % div;

	int ans = rem * mul + q;

	cout<<ans<<endl;

	return 0;
}
