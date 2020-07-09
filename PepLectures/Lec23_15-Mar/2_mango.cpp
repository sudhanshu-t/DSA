#include <iostream>
#include <string>
#include <vector>

#define vs vector<string>

using namespace std;

bool itwd(string word, vs& dict){
    for(int i = 0; i < dict.size(); i++){
        if(word.compare(dict[i]) == 0){
            return true;
        }
    }

    return false;
}

void mango(vs& dict, string word, string asf){
    if(word.size() == 0){
        cout << asf << endl;
        return;
    }

    for(int i = 1; i <= word.size(); i++){
        string rw = word.substr(i);
        string w = word.substr(0, i);
        
        // cout << w << "  " << rw << endl;
        if(itwd(w, dict) == true){
            mango(dict, rw, asf + w + " ");
        }
    }
}

int main(int argc, char** argv){
    vs dict = {"mango", "man", "go", "ice", "cream", "icecream", "air", "airplane", "plane"};
    string word = "mangoicecreamairplane";

    mango(dict, word, "");

    // string s1 = "abc", s2 = "abc";
    // cout << s1.compare(s2) << endl;   
}