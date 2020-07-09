#include<iostream>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2 strings
// It should return boolean output.
bool isLongPressedName(string &name, string &typed) {
    // Write your code here
    int i = 0;
    int j = 0;

    while(j < typed.size()){
        if(i < name.size() && name[i] == typed[j]){
            i++;
            j++;
        } else {
            if(typed[j] != name[i-1]){
                return false;
            }
            while(typed[j] == name[i-1]){
                j++;
            }
        }
    }

    if(i < name.size() && name[i] != typed[j-1]){
        return false;
    }

    return true;
}

int main(int argc, char** argv){
    string name, typed;
    cin>>name>>typed;

    if(isLongPressedName(name, typed)){
        cout<<"true";
    }else{
        cout<<"false";
    }

    return 0;
}