#include<iostream>
#include<string>
using namespace std;

//write your code here
void removeString(string str, string m, string n) {
    // For m string
    for(int i = 0; i < str.size(); i++){
        for(int j = i; j < str.size(); j++){
            string s;
            if(i == j){
                s = str.substr(i, 1);
            } else {
                s = str.substr(i, j-i+1);
            }

            // cout << s << endl;

            if(s == m){
                string s1 = str.substr(0, i);
                string s2 = str.substr(j+1);

                // cout << s1 << " " << s2 << endl;

                str = s1 + s2;
                // cout << str << endl;
                i = -1;
                break;
            }
        }

        // cout << i << endl;
    }

    // cout << str << endl;
    
    // For n string
    for(int i = 0; i < str.size(); i++){
        for(int j = i; j < str.size(); j++){
            string s;
            if(i == j){
                s = str.substr(i, 1);
            } else {
                s = str.substr(i, j-i+1);
            }

            // cout << s << endl;

            if(s == n){
                string s1 = str.substr(0, i);
                string s2 = str.substr(j+1);

                // cout << s1 << " " << s2 << endl;

                str = s1 + s2;
                // cout << str << endl;
                i = -1;
                break;
            }
        }
    }

    cout << str << endl;
}

int main(int argc, char** argv) {
    string str, m, n;
    cin>>str>>m>>n;
    removeString(str, m, n);
}