#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool myCompare(const int& a, const int& b){
    int digitsB = 0, digitsA = 0;

    int safeB = b;
    int safeA = a;

    if(b == 0){
        digitsB = 1;
    } else {
        while(safeB != 0){
            safeB = safeB / 10;
            digitsB++;
        }
    }

    if(a == 0){
        digitsA = 1;
    } else {
        while(safeA != 0){
            safeA = safeA / 10;
            digitsA++;
        }
    }

    long long int num1, num2;

    // num1 - ab, num2 - ba

    num1 = a * pow(10, digitsB) + b;
    num2 = b * pow(10, digitsA) + a;

    // cout << digitsA << " " << digitsB << endl;
    // cout << num1 << " " << num2 << endl;
    if(num1 < num2){
        return false;
    } else {
        return true;
    }
}

string largestNumber(const vector<int> &A) {
    vector<int> copy (A);
    sort(copy.begin(), copy.end(), myCompare);
    
    for(int i = 0; i < copy.size(); i++){
        for(int j = i+1; j < copy.size(); j++){
            if(!myCompare(copy[i], copy[j])){
                int temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }

    string res = "";
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
        res += to_string(copy[i]);
        sum += copy[i];
    }

    return (sum == 0) ? "0" : res;
}

int main(int argc, char** argv){
    vector<int> A = {1,234,56,7,89,1011};
    cout << largestNumber(A);

    // cout << myCompare(123,4567) << endl;
}