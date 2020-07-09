#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>>* wordBreak(vector<string>& dcry, string word){


    vector<vector<string>>* mres = new vector<vector<string>>();

    for(int i = 1; i < word.size(); i++){
        string str = word.substr(0, i);

        for(int j = 0; j < dcry.size(); j++){
            if(str == dcry[j]){
                string rs = word.substr(i);

                vector<vector<string>>* res = wordBreak(dcry, rs);

                for(int k = 0; k < res.size(); k++){
                    (*res)[i].push_back(str);
                }

                for(int k = 0; k < (*res).size(); k++){
                    for(int l = 0; l < (*res)[k].size(); l++){
                        for(int m = 0; m < dcry.size(); m++){
                            if(str + (*res)[k][l] == dcry[m]){
                                
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char** argv){
    vector<string> dcry = {"i", "like", "sam", "samsung", "sung", "ice", "icecream", "man", "mango", "go"};

    string word = "ilike";
    vector<vector<string> = wordBreak(dcry, word);

    return 0;
}