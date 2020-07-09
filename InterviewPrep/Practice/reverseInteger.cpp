#include <iostream>
#include <string>
#include <climits>

using namespace std;

int reverse(int x) {
    string s = "";
    
    int copy = x;

    if(copy == 0){
        s = "0";
    }
    
    if(copy < 0){
        copy = -1 * copy;
    }

    if(copy == INT_MIN){
        s = "0";
    }

    while(copy != 0 && copy != INT_MIN){
        int d = copy % 10;
        copy = copy / 10;
        
        s += to_string(d);
    }

    // cout << "s = " << s << endl;
    
    int ans = stoi(s);
    
    if(x < 0){
        return (-1 * ans);
    } else
        return ans;
}

int main(){
    int x = -2147483648;
    cout << reverse(x) << endl;
}