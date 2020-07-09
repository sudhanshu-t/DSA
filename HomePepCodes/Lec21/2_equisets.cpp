#include <iostream>
#include <vector>
#include <string>

using namespace std;

void equiset1(int arr[], int n, int sp, string s1, int sos1, string s2, int sos2){
    if(sp == n){
        if(sos1 == sos2){
            cout << s1 << "& " << s2 << endl;
        }

        return;
    }

    equiset1(arr, n, sp+1, s1 + to_string(arr[sp]) + " ", sos1 + arr[sp], s2, sos2);
    equiset1(arr, n, sp+1, s1, sos1, s2 + to_string(arr[sp]) + " ", sos2 + arr[sp]);
}

void disp(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return;
}

void equiset2(int arr[], int n, int sp, vector<int>& s1, int sos1, vector<int>& s2, int sos2){
    if(sp == n){
        if(sos1 == sos2){
            disp(s1);
            cout << "& ";
            disp(s2);
            cout << endl;
        }

        return;
    }

    s1.push_back(arr[sp]);
    equiset2(arr, n, sp+1, s1, sos1+arr[sp], s2, sos2);
    s1.pop_back();
    
    s2.push_back(arr[sp]);
    equiset2(arr, n, sp+1, s1, sos1, s2, sos2+arr[sp]);
    s2.pop_back();
}

int main(int argc, char** argv){
    int arr[] = {10,20,30,40,50,60,70};

    // equiset1(arr, 7, 1, "10 ", 10, "", 0);

    vector<int> kv1, kv2;
    kv1.push_back(10);
    equiset2(arr, 7, 1, kv1, 10, kv2, 0);
}