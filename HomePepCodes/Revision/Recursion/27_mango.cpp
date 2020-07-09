#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool itwpd(vector<string>& dcry, string word){
    for(int i = 0; i < dcry.size(); i++){
        if(dcry[i] == word){
            return true;
        }
    }

    return false;
}

void mango(vector<string>& dcry, string s, string asf){
    if(s.size() == 0){
        cout << asf << endl;
        return;
    }
    
    string p;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        p += ch;

        if(itwpd(dcry, p)){
            mango(dcry, s.substr(i+1), asf + p + " ");
        }
    }
}

int main(int argc, char** argv){
    vector<string> dcry = {
        "mango", "man", "go", "r", "goice", "icecream", "ice", "cream", "airplane", "air", "plane"
    };

    string s = "mangoicecreamairrplane";

    mango(dcry, s, "");
}