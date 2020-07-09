#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void LIS_paths(vector<int>& arr, vector<int>& strg, int idx, int length, string psf, vector<int>& path, vector<vector<int>>& lis){
    if(length == 1){
        cout << psf << endl;

        lis.push_back(path);
        return;
    }
    
    for(int i = 0; i < idx; i++){
        if(strg[i] + 1 == strg[idx]){
            if(arr[i] < arr[idx]){
                path.push_back(arr[i]);
                LIS_paths(arr, strg, i, length - 1, to_string(arr[i]) + " " + psf, path, lis);
                path.pop_back();
            }
        }
    }
}

int LIS(vector<int>& arr, vector<vector<int>>& lis){
    vector<int> strg (arr.size(), 0);

    strg[0] = 1;

    int myMax, omax = INT_MIN;
    for(int i = 1; i < strg.size(); i++){
        myMax = INT_MIN;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                myMax = max(myMax, strg[j]);
            }
        }

        if(myMax == INT_MIN)
            strg[i] = 1;
        else
            strg[i] = myMax + 1;

        omax = max(strg[i], omax);
    }

    for(int i = 0; i < strg.size(); i++){
        cout << strg[i] << " ";
    }
    cout << endl;

    vector<int> path;

    for(int i = 0; i < strg.size(); i++){
        if(strg[i] == myMax){
            LIS_paths(arr, strg, i, myMax, to_string(arr[i]), path, lis);        
        }
    }

    return myMax;
}

void LDS_paths(vector<int>& arr, vector<int>& strg, int idx, int length, string psf, vector<int>& path, vector<vector<int>>& lds){
    if(length == 1){
        cout << psf << endl;

        lds.push_back(path);
        return;
    }
    
    for(int i = 0; i < idx; i++){
        if(strg[i] + 1 == strg[idx]){
            if(arr[i] < arr[idx]){
                path.push_back(arr[i]);
                LDS_paths(arr, strg, i, length - 1, to_string(arr[i]) + " " + psf, path, lds);
                path.pop_back();
            }
        }
    }
}

int LDS(vector<int>& arr, vector<vector<int>>& lds){
    vector<int> strg (arr.size(), 0);

    strg[0] = 1;

    int myMax, omax = INT_MIN;
    for(int i = strg.size() - 1; i >= 0; i--){
        myMax = INT_MIN;
        for(int j = i + 1; j >= 0; j--){
            if(arr[j] < arr[i]){
                myMax = max(myMax, strg[j]);
            }
        }

        if(myMax == INT_MIN)
            strg[i] = 1;
        else
            strg[i] = myMax + 1;

        omax = max(strg[i], omax);
    }

    for(int i = 0; i < strg.size(); i++){
        cout << strg[i] << " ";
    }

    cout << endl;

    vector<int> path;

    for(int i = 0; i < strg.size(); i++){
        if(strg[i] == myMax){
            LDS_paths(arr, strg, i, myMax, to_string(arr[i]), path, lds);        
        }
    }

    return myMax;
}

int LBS(vector<int>& arr){
    vector<vector<int>> lis;
    vector<vector<int>> lds;

    LIS(arr, lis);
    LDS(arr, lds);

    int myMax = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        if(myMax < lis[i].size() + lds[i].size() - 1){
            myMax = lis[i].size() + lds[i].size() - 1;
        }
    }

    return myMax;
}

int LCS(string s1, string s2){
    vector<vector<int>> strg (s1.size() + 1, vector<int> (s2.size() + 1, 0));

    for(int i = 0; i < strg.size(); i++){
        strg[i][s2.size() - 1] = 0;
    }

    for(int j = 0; j < strg[0].size(); j++){
        strg[s1.size() - 1][j] = 0;
    }

    for(int i = strg.size() - 2; i >= 0; i--){
        for(int j = strg[0].size() - 2; j >= 0; j--){
            if(s1[i] == s2[j]){
                strg[i][j] = strg[i+1][j+1] + 1;
            } else {
                strg[i][j] = max(strg[i+1][j], strg[i][j+1]);
            }
        }
    }

    return strg[0][0];
}

// PATHS LCS ==================

/*
========= Diagonal Traversal =========

for(int jigap = 0; jigap < s.size(); jigap++){
    for(int i = 0, j = i + jigap; j < s.size(); i++){
        // Here j is the controlling element since it will reach the wall before i.
    }
}
*/

int LPS(string s){
    vector<vector<int>> strg (s.size(), vector<int> (s.size(), 0));

    for(int x = 0; x < s.size(); x++){
        for(int i = 0, j = x; j < s.size(); i++, j++){
            if(x == 0){
                strg[i][j] = 1;
            }
            else{
                if(s[i] != s[j]){
                    strg[i][j] = max(strg[i][j-1], strg[i+1][j]);
                } else {
                    strg[i][j] = 2 + strg[i+1][j-1];
                }
            }
        }
    }

    for(int i = 0; i < strg.size(); i++){
        for(int j = 0; j < strg.size(); j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    return strg[0][s.size() - 1];
}

int MCM(vector<int>& arr){
    vector<vector<int>> strg (arr.size() - 1, vector<int> (arr.size() - 1, INT_MAX));

    for(int x = 0; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            if(i == j){
                strg[i][j] = 0;
                // break;
                continue;
            }
            for(int k = i; k < j; k++){
                strg[i][j] = min(strg[i][j], strg[i][k] + strg[k+1][j] + arr[i] * arr[k+1] * arr[j+1]);
            }
        }
    }

    for(int i = 0; i < strg.size(); i++){
        for(int j = 0; j < strg.size(); j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }
}

int eggDrop(int e, int f, vector<vector<int>>& strg){
    if(f == 0 || f == 1 || e == 1){
        strg[e][f] = f;
        return f;
    }

    if(strg[e][f] != 0){
        return strg[e][f];
    }

    int mymin = INT_MAX;
    for(int k = 1; k <= f; k++){
        int brtrue = eggDrop(e-1, k-1, strg);
        int brfalse = eggDrop(e, f-k, strg);

        mymin = min(max(brtrue, brfalse), mymin);
    }

    strg[e][f] = mymin + 1;
    return mymin + 1;
}

vector<int> sumFreq = {0, 4, 11, 16, 17, 19};
int optimalBST(vector<int>& val, vector<int>& freq){
    vector<vector<int>> strg (val.size() + 1, vector<int> (val.size() + 1, 0));

    for(int x = 1; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            int mymin = INT_MAX;
            for(int k = i; k < j; k++){
                mymin = min(mymin, strg[i][k] + strg[k+1][j]);
            }
            strg[i][j] = mymin + sumFreq[j] - sumFreq[i];
        }
    }

    return strg[0][strg.size() - 1];
}

int main(int argc, char** argv){
    // vector<int> arr = {100,10,22,9,33,21,50,41,60,80,70};

    // cout << LIS(arr) << endl;

    // cout << LBS(arr) << endl;

    // cout << LCS("acbd", "acebf") << endl;

    // cout << LPS("abkccgbc") << endl;

    // vector<int> arr = {10,20,30,40,50,60};
    // MCM(arr);

    // vector<vector<int>> strg(3, vector<int>(11, 0));
    // cout << eggDrop(2, 10, strg) << endl;
    
    vector<int> val = {5,7,8,17,20};
    vector<int> freq = {4,7,5,1,2};

    cout << optimalBST(val, freq) << endl;
}