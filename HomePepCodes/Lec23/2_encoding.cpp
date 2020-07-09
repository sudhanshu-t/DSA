#include <iostream>
#include <string>

using namespace std;

int ifs(string s){
    int power = 1, ans = 0;

    for(int i = s.size()-1; i >= 0; i--){
        ans += (s[i] - '0') * power;
        power *= 10;
    }

    return ans;
}

void encoding(string num, string asf){
    if(num.size() == 0){
        cout << asf << endl;
        return;
    }

    string s = num.substr(0, 2);
    int n = ifs(s);

    cout << n << endl;

    // Only 2 char call
    if(n % 10 == 0){
        char ch = (char)(n + 96);
        // cout << ch << endl;
        encoding(num.substr(2), asf + ch);
    }
    
    // Only 1 char call
    else if(n > 26){
        char ch = num[0];
        // cout << ch << endl;
        encoding(num.substr(1), asf + ch);
    }

    else{
        // Both calls
        char ch1 = num[0];
        encoding(num.substr(1), asf + ch1);

        char ch2 = (char)(n + 96);
        // cout << ch2 << endl;
        encoding(num.substr(2), asf + ch2);
    }
}

int main(int argc, char** argv){
    string num = "1123";

    // cout << ifs(num) << endl;

    encoding(num, "");
}