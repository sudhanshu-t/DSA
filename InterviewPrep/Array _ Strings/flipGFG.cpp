#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> flipMisunderstood(string A) {
    int c = 0;
    int i = -1;
    int j = 0;
    
    int len = 0;
    int st = 0;
    int end = 0;
    
    while(j < A.size()){
        if(A[j] - '0' == 0){
            c++;

            // cout << c << endl;
            // cout << A.substr(i, j) << endl;            
            if(c > 1){
                if(j - i - 1 > len){
                    len = j - i - 1;
                    st = i+1;
                    end = j-1;
                }
                
                while(c != 1){
                    i++;
                    if(A[i] - '0' == 0){
                        c--;
                    }
                }
            }
        }
        
        j++;
    }

    // cout << st << " " << end << " " << len << endl;


    // cout << "new " << j - i - 1 << endl;
    if(j - i - 1 > len){
        len = j - i - 1;
        st = i+1;
        end = j-1;
    }
    
    vector<int> res (2);
    
    res[0] = st;
    res[1] = end;
    
    return res;
}

vector<int> flipMisunderstood2(string s){
    int oc = 0;
    int os = 0;
    int oe = 0;
    int i = 0;

    vector<int> res;
    
    while(i < s.size()){
        if(s[i] - '0' == 0){
            int c = 1;
            int st = i;

            while(i + 1 < s.size() && s[i+1] - '0' != 1){
                i++;
                c++;
            }

            int end = i;

            if(c > oc){
                oc = c;
                os = st;
                oe = end;

                if(res.size() == 0){
                    res.push_back(os+1);
                    res.push_back(oe+1);
                } else {
                    res[0] = os + 1;
                    res[1] = oe + 1;
                }
            }
        }
        
        i++;
    }

    return res;
}

vector<int> flip(string s){
    int gmax = 0;
    int gst = -1;
    int gen = -1;

    int lst = 0;
    int len = 0;
    int lmax = 0;
    int temp = 0;

    for(int i = 0; i < s.size(); i++){
        temp += (s[i] == '0' ? 1 : -1);        

        if(temp > lmax){
            lst = i;
            len = i;
            lmax = temp;
        } else {
            len = i;
            lmax += temp;
        }

        if(lmax > gmax){
            gmax = lmax;
            gst = lst;
            gen = len;
        }

        cout << gst << " " << gen << endl;
    }

    vector<int> res;
    if(gst == -1 || gen == -1){
        return res;
    }

    res.push_back(gst + 1);
    res.push_back(gen + 1);
    return res;
}

int main(int argc, char** argv){
    string s = "1101010001";

    vector<int> res = flip(s);

    cout << res[0] << " " << res[1] << endl;
}