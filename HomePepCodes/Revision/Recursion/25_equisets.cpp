#include <iostream>
#include <vector>
#include <string>

using namespace std;

void equisets1(int arr[], int n, int idx, string s1, string s2, int sum1, int sum2){
    if(idx == n){
        if(sum1 == sum2 && s1.size() > s2.size()){
            cout << s1 << "& " << s2 << endl;
        }
        return;
    }

    equisets1(arr, n, idx + 1, s1 + to_string(arr[idx]) + " ", s2, sum1 + arr[idx], sum2);
    equisets1(arr, n, idx + 1, s1, s2 + to_string(arr[idx]) + " ", sum1, sum2 + arr[idx]);
}

void equisets2(int arr[], int n, int idx, vector<int>& s1, vector<int>& s2, int sum1, int sum2){
    if(idx == n){
        if(sum1 == sum2 && s1.size() < s2.size()){
            for(int i = 0; i < s1.size(); i++){
                cout << s1[i] << " ";
            }

            cout << "& ";

            for(int i = 0; i < s2.size(); i++){
                cout << s2[i] << " ";
            }

            cout << endl;
        }

        return;
    }
    
    s1.push_back(arr[idx]);
    equisets2(arr, n, idx + 1, s1, s2, sum1 + arr[idx], sum2);
    s1.pop_back();

    s2.push_back(arr[idx]);
    equisets2(arr, n, idx + 1, s1, s2, sum1, sum2 + arr[idx]);
    s2.pop_back();
}

int main(int argc, char** argv){
    int arr[] = {10,20,30,40,50,60,70};

    // equisets1(arr, 7, 0, "", "", 0, 0);

    vector<int> s1, s2;
    equisets2(arr, 7, 0, s1, s2, 0, 0);
}