#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>

using namespace std;

class Logger {
    public:
    unordered_map<string, int> map;
    /**
     * Initialize your data structure here.
     */
    Logger() {
    }

    /**
     * Returns true if the message should be printed in the given timestamp,
     * otherwise returns false. If this method returns false, the message
     * will not be printed. The timestamp is in seconds granularity.
     */
    bool shouldPrintMessage(int timestamp, string message) {
        if(map.find(message) == map.end()){
            map[message] = timestamp;
        } else {
            if(timestamp - map[message] >= 10){ 
                map[message] = timestamp;
                return true;
            }
            else return false;
        }
    }
};


int main(int argc,char** argv) {
    Logger lg;
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    vector<string> S(n);
    for (int i = 0; i < n; i++) {
        cin>>S[i];
    }
    for (int i = 0; i < n; i++) {
        if(lg.shouldPrintMessage(v[i], S[i]))
            cout<< "true" << " ";
        else cout << "false" << " ";
    }
}