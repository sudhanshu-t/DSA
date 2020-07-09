#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool isFrequencyEqual(string s) {
    //Write your code here	 	 
    unordered_map<char, int> fmap;

    int maxF = 0;
    int minF = 100000;
    int maxC = 0;
    int minC = 0;
    for(int i = 0; i < s.size(); i++){
        fmap[s[i]]++;
    }

    for(auto itr : fmap){
        maxF = max(maxF, itr.second);
        minF = min(minF, itr.second);
    }
    // cout << maxF <<endl;

    for(auto itr : fmap){
        if(itr.second == maxF)
            maxC++;
        
        else if(itr.second == minF){
            minC++;
        }
    }
    int nonMaxC = fmap.size() - maxC;
    
    // cout << maxF << " " << maxC << endl;
    // cout << minF << " " << minC << endl;

    if(minF == maxF){
        return true;
    }

    if(maxC > 1 && (minF > 1 || minC > 1)){
        return false;
    }

    if(maxF-minF>1 && nonMaxC > 1){
        return false;
    }

    // bool found = false;
    // for(auto itr : fmap){
    //     if(itr.second == maxF){
    //         continue;
    //     } else {
    //         if(itr.second == maxF - 1){
    //             continue;
    //         } else if(!found && itr.second == 1){
    //             found != found;
    //         } else {
    //             return false;
    //         }
    //     }
    // }

    return true;
}

//Don't make any changes here
int main(int argc, char** argv){
    string s;
    cin >> s;
    bool bl = isFrequencyEqual(s);
    if(bl == true){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}