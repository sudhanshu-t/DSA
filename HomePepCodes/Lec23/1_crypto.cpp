#include <iostream>
#include <string>

using namespace std;

string s1 = "send", s2 = "more", s3 = "money";
int counter = 0;

string unionString(){
    bool cusf[26] = {false};
    string qs;

    for(int i = 0; i < s1.size(); i++){
        if(cusf[s1[i]-'a'] == false){
            cusf[s1[i] - 'a'] = true;
            qs += s1[i];
        }
    }

    for(int i = 0; i < s2.size(); i++){
        if(cusf[s2[i]-'a'] == false){
            cusf[s2[i] - 'a'] = true;
            qs += s2[i];
        }
    }

    for(int i = 0; i < s3.size(); i++){
        if(cusf[s3[i]-'a'] == false){
            cusf[s3[i] - 'a'] = true;
            qs += s3[i];
        }
    }

    return qs;
}

int gnas(string s, int amap[]){
    int power = 1; // 0th power of 10
    int ans = 0;

    for(int i = s.size() - 1; i >= 0; i--){
        ans += amap[s[i] - 'a'] * power;
        power *= 10;
    }

    return ans;
}

void crypto(string qs, int amap[], bool dusf[]){
    if(qs.size() == 0){
        int n1 = gnas(s1, amap);
        int n2 = gnas(s2, amap);
        int n3 = gnas(s3, amap);

        if(n1 + n2 == n3){
            counter++;

            cout << " " << n1 << endl;
            cout << "+" << n2 << endl;
            cout << "------" << endl;
            cout << n3 << endl;
        }
        
        return;
    }

    char ch = qs[0];
    string rqs = qs.substr(1);

    for(int i = 0; i <= 9; i++){
        if(dusf[i] == false){
            dusf[i] = true;
            amap[ch - 'a'] = i;

            crypto(rqs, amap, dusf);

            dusf[i] = false;
            amap[ch - 'a'] = -1;
        }
    }
}

int main(int argc, char** argv){
    // char s = 'b';
    // cout << s - 'a' << endl;

    string qs = unionString();

    // cout << qs << endl;
    int amap[26] = {-1};
    bool dusf[10] = {false};

    // crypto(qs, amap, dusf);
    // cout << counter << endl;

    char ch = 'a';
    cout << (char)112 << endl;
}