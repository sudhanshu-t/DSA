// C++ program to find the minimum value 
// of a + shaped pattern in 2-D array 
#include <bits/stdc++.h> 
using namespace std; 
#define N 100 

const int n = 3, m = 3; 

// Function to return maximum Plus value 
int minPlus(int (arr)[n][m]) 
{ 
	int ans = INT_MAX; 

	int left[N][N], right[N][N], up[N][N], down[N][N]; 

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			left[i][j] = min(0LL, (j ? left[i][j - 1] : 0LL)) 
											+ arr[i][j]; 
			up[i][j] = min(0LL, (i ? up[i - 1][j] : 0LL)) 
											+ arr[i][j]; 
		} 
	} 
 
	for (int i = n-1; i >=0; i--) { 
		for (int j = m-1; j>=0; j--) { 
			right[i][j] = min(0LL, (j + 1 == m ? 0LL: right[i][j + 1])) 
															+ arr[i][j]; 
			down[i][j] = min(0LL, (i + 1 == n ? 0LL: down[i + 1][j])) 
															+ arr[i][j]; 
		} 
	} 

	for (int i = 0; i < n ; ++i) 
		for (int j = 0; j < m ; ++j) {
			ans = min(ans, up[i][j] + down[i][j] 
						+ left[i][j] + right[i][j] - 3*arr[i][j]); 
		}

	return ans; 
} 

// Driver code 
int main() 
{ 

	// int arr[n][m] = { { 1, 2, 3 }, 
	// 				{ -5, -10, 5 }, 
	// 				{ -6, 7, 8 } }; 

	// // Function call to find maximum value 
	// // calculating value of minimum Plus (+) sign 
	// cout << minPlus(arr)<<endl;

	int count = 
	return 0; 
}