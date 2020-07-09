#include<iostream>

using namespace std;

int main(int argc, char** argv){
	int num;

	cin>>num;

	for(int i = 2; i*i <= num; i++){
		if(num%i == 0){
			cout<<"Non-Prime"<<endl;
			return 0;
		}
	}

	cout<<"Prime"<<endl;

	return 0;
}
