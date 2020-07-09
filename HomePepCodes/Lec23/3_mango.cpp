#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool itwp(string word, vector<string>& words){
    for(int i = 0; i < words.size(); i++){
        if(word.compare(words[i]) == 0){
            return true;
        }
    }

    return false;
}

void mango(vector<string>& words, string word, string asf){
    if(word.size() == 0){
        cout << asf << endl;
        return;
    }

    for(int i = 1; i <= word.size(); i++){
        string w = word.substr(0, i);
        string rw = word.substr(i);

        if(itwp(w, words) == true){
            mango(words, rw, asf + w + " ");
        }
    }
}

int main(int argc, char** argv){
    vector<string> words = {"man", "go", "mango", "ice", "icecream", "cream", "plane", "air", "airplane"};
    string word = "icecreamairplanemangocream";

    mango(words, word, "");
}