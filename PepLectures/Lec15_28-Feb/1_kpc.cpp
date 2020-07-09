#include <iostream>
#include <string>
#include <vector>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};


vector <string> gkpc(string str){  
    if(str.size() == 1){
        vector <string> br, bres;
    br.push_back("");
        // cout << str[0] << endl << endl;
        // string s1 = codes[str[0] - '0'];

        // for(int j=0; j<br.size(); j++){
        //     for(int i = 0; i < codes[str[0] - '0'].size(); i++){
        //         char s = codes[str[0] - '0'][i];
        //         // string r = s + "";
        //         // cout << s << endl << r <<  endl;
        //         bres.push_back(s + br[j]);
        //     }
        // }

        for(int i = 0; i < codes[str[0] - '0'].size(); i++){
                char s = codes[str[0] - '0'][i];
                string r = string(1, s); // Converting char to string bcz cannot pushback char to a vector od string datatype
                // string r = s + "";
                // cout << s << endl << r <<  endl;
                bres.push_back(r);
        }

        return bres;
    }
    
    string s;
    for(int i = 0; i < str.size() - 1; i++){
        s.push_back(str[i+1]); // s[i] = str[i+1] nahi chala
    }

    vector <string> rres = gkpc(s);

    vector <string> mres;

    for(int i = 0; i < codes[str[0] - '0'].size(); i++){
        for(int j = 0; j < rres.size(); j++){
            string s = codes[str[0] - '0'];
            mres.push_back((s[i]) + (rres[j]));
        }
    }

    return mres;

}
int main(int argc, char** argv){
    vector <string> words = gkpc("682");

    for(int i = 0; i < words.size(); i++){
        cout << words[i] << endl; 
    }

    cout << words.size() << endl;

    // string s = "234";

    // cout << s[0] << endl;
    return 0;
}