#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int a[][3] = {
		{1,0,0},
		{0,0,1}
	};
	int b[][4] = {
		{1,0,1,0},
		{1,1,1,1},
		{0,1,1,0}
	};

	int ar = sizeof(a) / sizeof(a[0]);
	int ac = sizeof(a[0]) / sizeof(int);

	int br = sizeof(b) / sizeof(b[0]);
	int bc = sizeof(b[0]) / sizeof(int);

	int r = ar;
	int c = bc;

	int ans[r][c];

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			ans[i][j] = 0;
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			for(int k = 0; k < ac; k++){
				ans[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}


	return 0;
}
