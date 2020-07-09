#include <iostream>
#include <string>
#include <climits>
#include <sstream>

using namespace std;

int myAtoi(string str) {
    if(str[0] == '.' || str.size() == 0){
        return 0;
    }    
    
    bool neg = false;
    string s;
    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        
        if(c == '+'){
            if(s.size() > 0){
                break;
            }
            
            if(s.size() == 0){
                if(str.size() == 1){
                    return 0;
                } else {
                    if(i+1 < str.size() && str[i+1] == '-'){
                        return 0;
                    }
                    continue;
                }
            }
        }
        
        if(c == ' '){
            if(s.size() == 0)
                continue;
            else
                break;
        }
        
        if(c == '-'){
            if(str.size() == 1){
                return 0;
            }
            
            if(i+1 < str.size() && str[i+1] == '+'){
                return 0;
            }
            neg = true;
            continue;
        }
        
        if(c == '.'){
            break;
        }
        
        if(c >= 48 && c <= 57){
            s += c;
        }
        
        else {
            break;
        }
    }
    
    if(s.size() == 0)
        return 0;
    
    cout << s << endl;
    
    stringstream geek(s); 
    int ans;
    geek >> ans; 
    
    if(neg){
        if(ans == INT_MAX)
            return INT_MIN;
        else if (ans == 0)
            return 0;
        return -1 * ans;
    } else 
        return ans;
}

int main(){
    string s = "-2147483647";
    cout << myAtoi(s) << endl;
}