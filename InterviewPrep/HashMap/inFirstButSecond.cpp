#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input two arrays and lengths.
// It should print required output.
void solve(vector<long>& a, vector<long>& b,int n, int m)  
{  
    //Write your code here
    unordered_set<long int> map;

    for(int i = 0; i < b.size(); i++){
        map.insert(b[i]);
    }

    for(int i = 0; i < a.size(); i++){
        if(map.find(a[i]) == map.end()){
            cout << a[i] << " ";
        }
    }

    cout << endl;
}


int main(int argc,char** argv){
    int n ;
    cin>>n;
    vector<long> num(n);
    for (int i = 0; i < n; i++) {
        
        cin>>num[i];
    }
    int m;
    cin>>m;
    vector <long> num2(m);
    for (int i = 0; i < m; i++) {
        cin>>num2[i];
    }
    solve(num, num2, n, m);
}