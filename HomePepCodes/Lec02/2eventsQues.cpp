#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int s1, e1, s2, e2;
	cin>>s1>>e1>>s2>>e2;

	// E1 in E2
	if(s2 <= s1 && e1 <= e2){
		cout<<"E1 in E2"<<endl;
	}
	// E2 in E1
	else if(s1 <= s2 && e2 <= e1){
		cout<<"E2 in E1"<<endl;
	}
	// No  Overlap
	else if(e1 < s2 || e2 < s1){
		cout<<"No Overlap"<<endl;
	}
	// Partial Overlap
	else {
		cout<<"Partial Overlap"<<endl;
	}

	return 0;
}
