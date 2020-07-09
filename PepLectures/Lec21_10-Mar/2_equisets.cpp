#include <iostream>
#include <string>
#include <vector>

using namespace std;

void equiset1(int arr[], int sp, string s1, int sos1, string s2, int sos2, int n){
    if(sp == n){
        if(sos1 == sos2){
            cout << s1 << " &  " << s2 << endl;
        }

        return;
    }

    equiset1(arr, sp+1, s1 + to_string(arr[sp]) + " ", sos1 + arr[sp], s2, sos2, n);
    equiset1(arr, sp+1, s1, sos1, s2 + to_string(arr[sp]) + " ", sos2 + arr[sp], n);   
}

void equiset2(int arr[], int sp, vector<int>& s1, int sos1, vector<int>& s2, int sos2, int n){
    if(sp == n){
        if(sos1 == sos2){
            for(int i = 0; i < s1.size(); i++){
                cout << s1[i] << " ";
            }

            cout << " &  ";
            
            for(int i = 0; i < s2.size(); i++){
                cout << s2[i] << " ";
            }

            cout << endl;
        }

        return;
    }

    s1.push_back(arr[sp]);
    equiset2(arr, sp+1, s1, sos1+arr[sp], s2, sos2, n);
    s1.pop_back();

    s2.push_back(arr[sp]);
    equiset2(arr, sp+1, s1, sos1, s2, sos2+arr[sp], n);
    s2.pop_back();
}

int main(int argc, char** argv){
    int arr[] = {10,20,30,40,50,60,70};

    // equiset1(arr, 0, "", 0, "", 0, 7);

    vector<int> s1, s2;

    equiset2(arr, 0, s1, 0, s2, 0, 7); 
}