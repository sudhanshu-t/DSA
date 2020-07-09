#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int c = 1;
    int i = digits.size() - 1;

    while(i >= 0 || c != 0){
        if(i < 0){
            vector<int> res (digits.size() + 1);
            res[0] = 1;

            for(int i = 1; i < res.size(); i++){
                res[i] = digits[i-1];
            }

            return res;
        } else if(digits[i] + c > 9){
            digits[i] = 0;
        } else {
            digits[i] = digits[i] + c;
            break;
        }
        i--;
    }

    return digits;
}

//Don't make any changes here.
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> Input(n);
    for(int i=0;i<n;i++){
        cin>>Input[i];
    }
    vector<int> ans = plusOne(Input);
    for (int i : ans) {
        cout<<i<<" ";
    }

}