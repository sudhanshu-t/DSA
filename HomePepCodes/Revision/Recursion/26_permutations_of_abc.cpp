#include <iostream>
#include <string>

using namespace std;

void question(string str, string asf){
    if(str.size() == 0){
        cout << asf << endl;
        return;
    }
    
    int bm = 0;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        string rq1 = str.substr(0, i);
        string rq2 = str.substr(i+1);

        if((bm & 1 << (ch - 97)) == 0){
            bm |= (1 << (ch - 97));
            question(rq1 + rq2, asf + ch);
        }
    }
}

int main(int argc, char** argv){
    question("aabb", "");
}