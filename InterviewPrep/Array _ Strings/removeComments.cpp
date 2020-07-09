#include<iostream>
#include<vector>
using namespace std;

vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool flag = true;
    string s;
    for(int i = 0; i < source.size(); i++){
        int j = 0;
        while(j < source[i].size()){
            if(source[i][j] == '/'){
                if(j < source[i].size() && source[i][j+1] == '*'){
                    flag = false;
                    j++;
                } else if(j < source[i].size() && source[i][j+1] == '/'){
                    // res.push_back(s);
                    // s = "";
                    break;
                }
            } else if(flag){
                s += source[i][j];
                // cout << "s is " << s << endl;
            } else if(source[i][j] == '*'){
                j++;
                flag = true;
            }

            j++;
        }

        if(flag && s != ""){
            res.push_back(s);
            s = "";
        }
    }


    return res;
}

void display(vector<string> & res){
    cout<<"[";
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1){
            cout<<", ";
        }
    }
    cout<<"]";
}

//Don't make any changes here.
int main(int argc, char** argv){
    int n ;
    cin>>n;
    vector<string> source (n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin,source[i]);
    }

    vector<string> res=removeComments(source);
    display(res);

}