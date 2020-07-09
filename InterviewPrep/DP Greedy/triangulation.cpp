#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array
// It should return the required output

int triCost(vector<int>& a, int left, int right){
    if(right - left + 1 < 3){
        return 0;
    }
    
    int myMin = INT_MAX;
    
    for(int i = left + 1; i < right; i++){
        myMin = min(myMin, triCost(a, left, i) + triCost(a, i, right) + a[left]*a[i]*a[right]);
    }
    
    return myMin;
}

int minScoreTriangulation(vector<int>& a) {
    // Write your code here
    
//  return triCost(a, 0, a.size() - 1);
    
    
    vector<vector<int>> strg (a.size(), vector<int> (a.size()));
    
    for(int x = 2; x < a.size(); x++){
        for(int i = 0, j = x; j < a.size(); j++, i++){
            int myMin = INT_MAX;
            for(int k = i+1; k < j; k++){
                myMin = min(myMin, strg[i][k] + strg[k][j] + a[i] * a[k] * a[j]);
                
            //  cout << strg[k][j] <<  endl;
            }
            
            strg[i][j] = myMin;
        }
    }
    
//  for(int i = 0; i < strg.size(); i++){
//      for(int j = 0; j < strg[0].size(); j++){
//          cout << strg[i][j] << " ";
//      }
//      cout << endl;
//  }
    
    return strg[0][a.size() - 1];
}

int main(int argc,char**argv){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }   

    cout<<minScoreTriangulation(v)<<endl;
}