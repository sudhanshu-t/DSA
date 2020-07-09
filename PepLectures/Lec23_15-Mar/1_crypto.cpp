#include <iostream>
#include <string>
#include <vector>

using namespace std;

int counter = 0;

// get number from string
int gnfs(string s, int msf[]){
    int ans;

    int power = 1; // 0th power of 10

    for(int i = s.size()-1; i >= 0; i--){
        ans += msf[s[i] - 'a'] * power;
        power *= 10;
    }

    return ans;
}

void crypto(string s1, string s2, string s3, string qs, int msf[], bool dusf[]){
    if(qs.size() == 0){
        int n1 = gnfs(s1, msf);
        int n2 = gnfs(s2, msf);
        int n3 = gnfs(s3, msf);

        if(n1+n2 == n3){
            counter++;

            cout << " " << n1 << endl;
            cout << "+ " << n2 << endl;
            cout << "-----" << endl;
            cout << " " << n3 << endl << endl;
        }

        return;
    }

    for(int i = 0; i < 10; i++){
        if(dusf[i] == false){
            msf[qs[0] - '0' - 49] = i;
            dusf[i] = true;
            crypto(s1, s2, s3, qs.substr(1), msf, dusf);
            dusf[i] = false;
            msf[qs[0] - '0' - 49] = -1;
        }
    }
}

int main(int argc, char** argv){
    string s1 = "send", s2 = "more", s3 = "money";

    string qs;
    bool cusf[26] = {false};

    for(int i = 0; i < s1.size(); i++){
        if(cusf[s1[i] - '0' - 49] == false){
            cusf[s1[i] - '0' - 49] = true;
            qs += s1[i];
        }
    }

    for(int i = 0; i < s2.size(); i++){
        if(cusf[s2[i] - '0' - 49] == false){
            cusf[s2[i] - '0' - 49] = true;
            qs += s2[i];
        }
    }
    
    for(int i = 0; i < s3.size(); i++){
        if(cusf[s3[i] - '0' - 49] == false){
            cusf[s3[i] - '0' - 49] = true;
            qs += s3[i];
        }
    }

    int msf[26] = {-1};
    bool dusf[10] = {false};

    crypto(s1, s2, s3, qs, msf, dusf);
    cout << counter << endl;

    // cout << qs << endl;

    // cout << ('a' - '0' - 49) << endl;

    return 0;
}