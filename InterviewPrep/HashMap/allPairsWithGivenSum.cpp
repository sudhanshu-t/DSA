#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;

void print(vector<int>& num1,vector<int> &num2 ,int k){
    //write your code here
    unordered_set<int> set;

    for(int i = 0; i < num2.size(); i++){
        set.insert(num2[i]);
    }

    bool first = true;

    sort(num1.begin(), num1.end());

    for(int i = 0; i < num1.size(); i++){
        if(set.find(k - num1[i]) != set.end()){
            if(first){
                cout <<  num1[i] << " " << k - num1[i];
                first = false;
            } else {
                cout << ", " << num1[i] << " " << k - num1[i];
            }
        }
    }

    if(first){
        cout << -1 << endl;
    }

    return;
}

int main(int argc,char ** argv){

    int n;
    cin>>n;
    int m;
    cin>>m;
    int k;
    cin>>k;
    vector<int> num1;
    vector<int> num2;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num1.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        num2.push_back(a);
    }

    print(num1, num2, k);
    cout<<endl;

}