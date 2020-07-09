#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void LIS_paths(int idx, int length, vector<int>& arr, vector<int>& strg, string psf, vector<int>& path, vector<vector<int>>& paths){
    if(length == 1){
        // cout << psf << endl;
        paths.push_back(path);
        return;
    }

    for(int i = idx - 1; i >= 0; i--){
        if(arr[i] < arr[idx] && strg[i] + 1 == strg[idx]){
            path.push_back(arr[i]);
            LIS_paths(i, length - 1, arr, strg, to_string(arr[i]) + " " + psf, path, paths);
            path.pop_back();
        }
    }
}

int LIS(vector<int>& arr, vector<int>& strg){
    strg[0] = 1;
    int myMax = INT_MIN;

    for(int i = 1; i < strg.size(); i++){
        for(int j = 0; j < strg.size(); j++){
            if(arr[j] < arr[i]){
                strg[i] = max(strg[i], strg[j]);
            }
        }

        strg[i]++;

        if(myMax < strg[i]){
            myMax = strg[i];
        }
    }

    for(int i = 0; i < strg.size(); i++){
        cout << strg[i] << " ";
    }
    cout << endl;

    vector<int> path;
    vector<vector<int>> paths;
    for(int i = 0; i < strg.size(); i++){
        if(myMax == strg[i]){
            path.push_back(arr[i]);
            LIS_paths(i, strg[i], arr, strg, to_string(arr[i]), path, paths);
            path.pop_back();
        }
    }

    // for(int i = 0; i < paths.size(); i++){
    //     for(int j = 0; j < paths[i].size(); j++){
    //         cout << paths[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return myMax;
}

void LDS_paths(int idx, int length, vector<int>& arr, vector<int>& strg, string psf, vector<int>& path, vector<vector<int>>& paths){
    if(length == 1){
        // cout << psf << endl;
        paths.push_back(path);
        return;
    }

    for(int i = idx + 1; i < strg.size(); i++){
        if(arr[i] < arr[idx] && strg[i] + 1 == strg[idx]){
            path.push_back(arr[i]);
            LDS_paths(i, length - 1, arr, strg, psf + " " + to_string(arr[i]), path, paths);
            path.pop_back();
        }
    }
}

int LDS(vector<int>& arr, vector<int>& strg){
    strg[strg.size() - 1] = 1;
    int myMax = INT_MIN;

    for(int i = strg.size() - 2; i >= 0; i--){
        for(int j = i+1; j < strg.size(); j++){
            if(arr[j] < arr[i]){
                strg[i] = max(strg[i], strg[j]);
            }
        }

        strg[i]++;

        if(myMax < strg[i]){
            myMax = strg[i];
        }
    }

    for(int i = 0; i < strg.size(); i++){
        cout << strg[i] << " ";
    }
    cout << endl;

    vector<int> path;
    vector<vector<int>> paths;
    for(int i = 0; i < strg.size(); i++){
        if(myMax == strg[i]){
            path.push_back(arr[i]);
            LDS_paths(i, strg[i], arr, strg, to_string(arr[i]), path, paths);
            path.pop_back();
        }
    }

    // for(int i = 0; i < paths.size(); i++){
    //     for(int j = 0; j < paths[i].size(); j++){
    //         cout << paths[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return myMax;
}

int LBS(vector<int>& arr){
    vector<vector<int>> lis;
    vector<int> path;
    vector<vector<int>> lds;

    int myMax = INT_MIN;
    vector<int> strg (arr.size(), 0);

    vector<int> strg_lds (arr.size(), 0);
    vector<int> strg_lis (arr.size(), 0);

    LIS(arr, strg_lis);
    LDS(arr, strg_lds);

    for(int i = 0; i < arr.size(); i++){
        path.push_back(arr[i]);
        LDS_paths(i, strg[i], arr, strg_lds, "", path, lds);
        LIS_paths(i, strg[i], arr, strg_lis, "", path, lis);
        path.pop_back();

        lis.clear();
        lds.clear();

        cout << lds.size() << lis.size() << endl;

        // strg[i] = lis[0].size() + lds[0].size();

        myMax = max(myMax, strg[i]);
    }

    return myMax;
}

void LCS_paths(int i, int j, string s1, string s2, vector<vector<int>>& strg, string psf){
    if(i == strg.size() - 1 && j == strg[0].size() - 1){
        cout << psf << endl;
        return;
    }

    if(s1[i] == s2[j]){
        LCS_paths(i + 1, j + 1, s1, s2, strg, psf + s1[i]);
    } else {
        if(strg[i+1][j] > strg[i][j+1]){
            LCS_paths(i+1, j, s1, s2, strg, psf);
        } else if(strg[i+1][j] < strg[i][j+1]){
            LCS_paths(i, j+1, s1, s2, strg, psf);
        } else {
            LCS_paths(i+1, j, s1, s2, strg, psf);
            LCS_paths(i, j+1, s1, s2, strg, psf);
        }
    }
}

int LCS(string s1, string s2){
    vector<vector<int>> strg (s1.size() + 1, vector<int> (s2.size() + 1, 0));

    for(int i = strg.size() - 1; i >= 0; i--){
        for(int j = strg[0].size() - 1; j >= 0; j--){
            if(i == strg.size() - 1 || j == strg[0].size() - 1){
                strg[i][j] = 0;
            } else {
                if(s1[i] == s2[j]){
                    strg[i][j] = strg[i+1][j+1] + 1;
                } else {
                    strg[i][j] = max(strg[i][j+1], strg[i+1][j]);
                }
            }
        }
    }

    LCS_paths(0, 0, s1, s2, strg, "");

    return strg[0][0];
}

// void LPS_paths(vector<vector<int>>& strg, string s, string psf, int i, int j){
//     if(strg[i][j] == 0){
//         cout << psf << endl;
//         return;
//     }
    
//     if(s[i] == s[j]){
//         LPS_paths(strg, s, psf + " " + s[i], i+1, j-1);
//     } else {
//         if(strg[i+1][j] > strg[i][j-1]){
//             LPS_paths(strg, s, psf + " " + s[j], i+1, j);
//         } else {
//             LPS_paths(strg, s, psf + " " + s[i], i, j-1);
//         }
//     }
// }

int LPS(string s){
    vector<vector<int>> strg (s.size(), vector<int> (s.size(), 0));

    for(int x = 0; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            if(i == j){
                strg[i][j] = 1;
            } else {
                if(s[i] == s[j]){
                    strg[i][j] = 2 + strg[i+1][j-1];
                } else {
                    strg[i][j] = max(strg[i+1][j], strg[i][j-1]);
                }
            }
        }
    }

    // LPS_paths(strg, s, s[0], 0, strg.size() - 1);

    // for(int i = 0; i < strg.size(); i++){
    //     for(int j = 0; j < strg.size(); j++){
    //         cout << strg[i][j] << " ";
    //     }
    //     cout << endl;
    // } for(int i = 0; i < strg.size(); i++){
    //     for(int j = 0; j < strg.size(); j++){
    //         cout << strg[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return strg[0][strg.size() - 1];
}

int CPS(string s){
    vector<vector<int>> strg (s.size(), vector<int>(s.size(), 0));

    for(int x = 0; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            if(i == j){
                strg[i][j] = 1;
            } 
            else {
                if(s[i] == s[j]){
                    strg[i][j] = strg[i+1][j] + strg[i][j-1] + 1;
                } else {
                    strg[i][j] = strg[i+1][j] + strg[i][j-1] - strg[i+1][j-1];
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

    return strg[0][strg.size() - 1];
}

int CandLPSS(string s){
    vector<vector<bool>> strg (s.size(), vector<bool> (s.size(), true));

    int count = 0; int length = 0;
    int maxGap = INT_MIN;
    for(int x = 0; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            if(i == j){
                strg[i][j] = true;
                count++;
            } 
            // else if(x == 1){
            //     // if(s[i] == s[j]){
            //     //     strg[i][j] = true;
            //     //     count++;
            //     // }
            // }
             else {
                if(s[i] == s[j]){
                    if(strg[i+1][j-1] == true){
                        strg[i][j] = true;
                        if(x > maxGap){
                            length = j - i + 1;
                            maxGap = x;
                        }
                        count++;
                    }
                } else {
                    strg[i][j] = false;
                }
            }
        }
    }

    cout << "Length " << length << endl;
    cout << "Max Gap " << maxGap << endl;
    return count;
}

int MPS(string s){
    vector<vector<int>> strg (s.size(), vector<int> (s.size(), 0));

    for(int x = 0; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            if(i == j){
                // strg[i][j] = 0;
            }
            else if(s[i] == s[j] && strg[i+1][j-1] == 0){
                strg[i][j] = 0;
            }
            else {
                int myMin = INT_MAX;
                for(int k = i; k < j; k++){
                    myMin = min(myMin, strg[i][k] + strg[k+1][j]);
                }

                strg[i][j] = myMin + 1;
            }
        }
    }

    for(int i = 0; i < strg.size(); i++){
        for(int j = 0; j < strg.size(); j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    return strg[0][strg.size() - 1];
}

int MCM(vector<int>& arr){
    vector<vector<int>> strg (arr.size() - 1, vector<int> (arr.size() - 1, 0));

    for(int x = 0; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); j++, i++){
            int mymin = INT_MAX;

            if(i == j){
                strg[i][j] = 0;
                // break;
                continue;
            }

            for(int k = i; k < j; k++){
                cout << "Mc " << k << k+1 << " " << arr[i]*arr[k+1]*arr[j+1] << endl;
                mymin = min(mymin, strg[i][k] + strg[k+1][j] + arr[i]*arr[k+1]*arr[j+1]);
            }

            strg[i][j] = mymin;
        }
    }

    for(int i = 0;i < strg.size(); i++){
        for(int j = 0;j < strg.size(); j++){
            cout << strg[i][j] << " ";
        }

        cout << endl;
    }
}

int MSC(vector<vector<int>>& strg, int h, int w){
    if(h == 0 || w == 0){
        return 0;
    }

    if(h == w){
        return 0;
    }

    int ans = INT_MAX;
    int finalAns = INT_MAX;

    int sd = min(h, w);

    // cout << sd << endl;

    if(strg[h][w] != 0){
        return strg[h][w];
    }

    for(int x = 1; x <= sd; x++){
        // P1V
        int c1 = MSC(strg, h-x, x);

        // P2V
        int c2 = MSC(strg, h, w-x);

        // P1H
        int c3 = MSC(strg, x, w-x);

        // P2H
        int c4 = MSC(strg, h-x, w);

        if(x == sd)
            ans = min(c1 + c2 + 1, c3 + c4 + 1);

        else
            ans = min(c1 + c2 + 2, c3 + c4 + 2);

        finalAns = min(finalAns, ans);
    }

    strg[h][w] = finalAns;
    cout << h - 1 << " " << w - 1 << " " << strg[h][w] << endl;
    return finalAns;
}

int eggDrop(int e, int f, vector<vector<int>>& qb){
    if(e == 1 || f == 0 || f == 1){
        qb[e][f] = f;
        return f;
    }

    if(qb[e][f] != -1){
        return qb[e][f];
    }


    int myMin = INT_MAX;
    for(int i = 1; i <= f; i++){
        int breaks = eggDrop(e-1, i-1, qb);
        int saved = eggDrop(e, f-i, qb);

        // cout << breaks << " " << saved << endl;

        myMin = min(max(breaks, saved), myMin);
    }

    qb[e][f] = myMin + 1;
    // cout << e << " " << f << " " << qb[e][f] << endl;

    return qb[e][f];
}

vector<int> freqSumArray = {0,4,11,16,17,19};
int optimalBST(vector<int>& arr, vector<int>& freq){
    vector<vector<int>> strg (arr.size() + 1, vector<int> (arr.size() + 1, 0));

    for(int x = 1; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg[0].size(); i++, j++){
            int mymin = INT_MAX;
            for(int k = i; k < j; k++){
                // cout << "Factor " << strg[i][k] + strg[k+1][j] + freqSumArray[j] - freqSumArray[i] << endl;
                mymin = min(mymin, strg[i][k] + strg[k+1][j] + freqSumArray[j] - freqSumArray[i]);
            }

            strg[i][j] = mymin;
        }
    }

    for(int i = 0; i < strg.size(); i++){
        for(int j = 0;j < strg.size(); j++){
            cout << strg[i][j] << "\t";
        }

        cout << endl;
    }

    return strg[0][strg.size() - 1];
}

void eggDropTrialsPrint(vector<vector<int>>& strg, int e, int f, string psf){
    if(f == 1){
        // cout << e << endl;
        if(e < strg.size() - 1){
            psf += to_string(f) + "br ";
        }
        else if(e == strg.size() - 1){
            psf += to_string(f) + "sv ";
        }
        
        cout << psf << endl;
        return;
    }
    
    for(int k = 1; k <= f; k++){
        if(strg[e][f] - 1 == strg[e-1][k-1]){
            eggDropTrialsPrint(strg, e-1, k-1, psf + to_string(k-1) + "br ");
        }
        if(strg[e][f] - 1  == strg[e][f-k]){
            eggDropTrialsPrint(strg, e, f-k, psf + to_string(f-k) + "sv ");
        }
    }
}

void eggDropTab(int e, int f){
    vector<vector<int>> strg (e+1, vector<int> (f+1, 0));

    for(int j = 0; j < strg[0].size(); j++){
        strg[0][j] = -1;
        strg[1][j] = j;
    }

    for(int i = 0; i < strg.size(); i++){
        strg[i][0] = 0;
    }

    for(int i = 2; i < strg.size(); i++){
        for(int j = 1; j < strg[0].size(); j++){
            int mymin = INT_MAX;
            for(int k = 1; k <= j; k++){
                // cout << strg[i-1][k-1] << " max with " << strg[i][j-k] << endl;
                mymin = min(mymin, max(strg[i-1][k-1], strg[i][j-k]));
            }

            strg[i][j] = mymin + 1;
        }
    }

    for(int i = 0; i < strg.size(); i++){
        for(int j = 0; j < strg[0].size(); j++){
            cout << strg[i][j] << "\t";
        }
        cout << endl;
    }

    eggDropTrialsPrint(strg, e, f, "");
}

void maxSumSubsetNonConsecutive(vector<int>& arr){
    int exc = 0;
    int inc = arr[0];

    for(int i = 1; i < arr.size(); i++){
        int pre_inc = inc;
        inc = exc + arr[i];
        exc = max(pre_inc, exc);
    }

    cout << max(inc, exc) << endl;
}

class helper{
    public:
    int end;
    int start;

    helper(int s, int e){
        this->end = e;
        this->start = s;
    }

    bool operator>(const helper& o) const {
        return this->end < o.end;
    }
};

void activitySelection(vector<int>& spts, vector<int>& epts){
    vector<helper> acts;
    for(int i = 0; i < epts.size(); i++){
        acts.push_back(helper (spts[i], epts[i]));
    }

    sort(acts.begin(), acts.end(), greater<helper>());

    // for(int i = 0; i < epts.size(); i++){
    //     cout << acts[i].end << " ";
    // }

    // cout << endl;
    
    int count = 1;
    int prevActIndex = 0;
    for(int i = 1; i < acts.size(); i++){
        if(acts[i].start >= acts[prevActIndex].end){
            prevActIndex = i;
            count++;
        }
    }

    cout << count << endl;
}

void minPlatforms(vector<int>& arrival, vector<int>& departure){
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0, j = 0;
    int mymax = INT_MIN;
    int count = 0;
    while(i < arrival.size()){
        if(arrival[i] < departure[j]){
            count++;
            i++;
        } else {
            count--;
            j++;
        }

        mymax = max(mymax, count);
    }

    // if(i >= arrival.size()){
    //     while(j < departure.size()){
    //         count--;
    //         j++;
    //     }
    // } else {
    //     while(i < arrival.size()){
    //         count++;
    //         i++;
    //     }
    // }

    cout << mymax << endl;
}

class KShelper{
public:
    int wt;
    int val;
    double rat;

    KShelper(int w, int v){
        wt = w;
        val = v;
        rat = (double)v/w;
    }

    bool operator<(const KShelper& o) const {
        return this->rat < o.rat;
    }
};

void fractionalKS(vector<int>& wt, vector<int>& val, int capacity){
    vector<KShelper> ratio;
    for(int i = 0; i < wt.size(); i++){
        ratio.push_back(KShelper (wt[i], val[i]));
    }

    sort(ratio.begin(), ratio.end());

    for(int i = 0; i < ratio.size(); i++){
        cout << ratio[i].rat << " ";
    }
    cout << endl;

    double value = 0;
    int j;
    for(j = ratio.size() - 1; j >= 0; j--){
        if(capacity >= ratio[j].wt){
            capacity -= ratio[j].wt;
            value += ratio[j].val;
        } else {
            break;
        }
        cout << capacity << endl;
    }

    value += ratio[j].rat * capacity;

    cout << value << endl;
}

int main(int argc, char** argv){
    // vector<int> arr = {100,10,22,9,30,21,50,41,60,80,70,1};

    // cout << LIS(arr) << endl;

    // cout << LDS(arr) << endl;

    // cout << LBS(arr) << endl;

    // cout << LCS("abcdef", "acbedghf") << endl;

    // cout << LPS("abkccdecfdbcgca") << endl;

    // cout << CPS("abgcckyb") << endl;

    // cout << CandLPSS("abccbc") << endl;

    // cout << MPS("abccbc") << endl;

    // vector<int> arr = {10,20,30,40,50,60};
    // MCM(arr);

    // vector<vector<int>> strg (4, vector<int>(5, 0));

    // cout << MSC(strg, 3, 4) << endl;

    // int e = 2;
    // int f = 10;
    // vector<vector<int>> qb (e+1, vector<int> (f+1, -1));
    // cout << eggDrop(e,f,qb) << endl;

    // for(int i = 0; i < qb.size(); i++){
    //     for(int j = 0;j < qb[0].size(); j++){
    //         cout << qb[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> arr = {5,7,8,17,20};
    // vector<int> freq = {4,7,5,1,2};

    // cout << optimalBST(arr, freq) << endl;

    // eggDropTab(2, 10);

    // vector<int> arr = {5,6,10,100,10};
    // maxSumSubsetNonConsecutive(arr);

    // vector<int> spts = {3,0,1,8,5,5};
    // vector<int> epts = {4,6,2,9,9,7};
    // activitySelection(spts, epts);

    // vector<int> arrival {900,940,950,1100,1500,1800};
    // vector<int> departure {910,1200,1120,1130,1900,2000};

    // minPlatforms(arrival, departure);

    vector<int> wt {10,40,20,30};
    vector<int> val {60,40,100,120};

    fractionalKS(wt, val, 50);
}