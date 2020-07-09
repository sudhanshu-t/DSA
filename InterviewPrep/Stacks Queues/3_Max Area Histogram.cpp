#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

int maxRectArea(int* ht, int n) {
//write your code here

	stack<int> st;

	vector<int> lb (n, 0);
	vector<int> rb (n, 0);
	vector<long long int> area (n, 0);

	// Left Boundary
	for(int i = 0; i < n; i++){
		while(st.size() != 0 && ht[st.top()] >= ht[i]){
			st.pop();
		}

		lb[i] = (st.size() == 0) ? -1 : st.top();
		st.push(i);
	}

	for(int i = 0; i < lb.size(); i++){
		cout << lb[i] << " ";
	}
	cout << endl;

	while(st.size() != 0){
		st.pop();
	}

	// Right Boundary
	for(int i = n-1; i >= 0; i--){
		while(st.size() != 0 && ht[st.top()] >= ht[i]){
			st.pop();
		}

		rb[i] = (st.size()) ? st.top() : n;
		st.push(i);
	}

	for(int i = 0; i < rb.size(); i++){
		cout << rb[i] << " ";
	}
	cout << endl;

	// Area
	int myMax = INT_MIN;
	for(int i = 0; i < n; i++){
		area[i] = (rb[i] - lb[i] - 1) * ht[i];
		if(area[i] > myMax){
			myMax = area[i];
		}
	}

	for(int i = 0; i < area.size(); i++){
		cout << area[i] << " ";
	}
	cout << endl;

	return myMax;
}

int main(int argc, char** argv) {
	int h;
	cin >> h;
	int* height = new int[h];

	for(int i=0;i<h;i++){
		cin >> height[i];
	}

	cout << maxRectArea(height, h) << endl;
}