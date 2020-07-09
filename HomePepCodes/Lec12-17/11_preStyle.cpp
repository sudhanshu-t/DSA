#include <iostream>
#include <vector>
#include <string>

using namespace std;

string codes[] = {".;", "abc", "def", "ghi",
                 "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void printss(string str, string asf){
    if(str.length() == 0){
        cout << asf << endl;
        return;
    }

    string s = str.substr(1);

    printss(s, asf + str[0]);
    printss(s, asf + "-");
}

int counter = 0;

void print_kpc(string str, string asf){
    if(str.size() == 0){
        cout << asf << endl;
        counter++;
        return;
    }

    string s = codes[str[0] - '0'];
    string rq = str.substr(1);

    for(int i = 0; i < s.size(); i++){
        char a = s[i];
        string a1(1, a);
        print_kpc(rq, asf + a1);
    }
}

void printPath(int cr, int cc, int dr, int dc, string asf){
    if(cr == dr && cc == dc){
        cout << asf << endl;
        return;
    }

    if(cr+1 <= dr){
        printPath(cr+1, cc, dr, dc, "H" + asf);
    }

    if(cc+1 <= dc){
        printPath(cr, cc+1, dr,dc, "V" + asf);
    }
}

void stair(int n, string asf){
    if(n == 0){
        cout << asf << endl;
        return;
    }

    if(n-1 >= 0){
        stair(n-1, "1" + asf);
    }

    if(n-2 >= 0){
        stair(n-2, "2" + asf);
    }

    if(n-3 >= 0){
        stair(n-3, "3" + asf);
    }
}

void printPath2(int cr, int cc, int dr, int dc, string asf){
    if(cr == dr && cc == dc){
        cout << asf << endl;
        return;
    }

    // Horizontal jumps
    for(int i = 1; i+cc <= dc; i++){
        printPath2(cr, cc+i, dr, dc, "H" + to_string(i) + asf);
    }

    // Vertical jumps
    for(int i = 1; i + cr <= dr; i++){
        printPath2(cr + i, cc, dr, dc, "V" + to_string(i) + asf);
    }

    // Diagonal jumps
    for(int i = 1; i + cr <= dr && i + cc <= dc; i++){
        printPath2(cr + i, cc + i, dr, dc, "D" + to_string(i) + asf);
    }
}

int main(int argc, char** argv){
    // printss("abc", "");
    // print_kpc("682", "");
    // cout << counter << endl;
    // printPath(0, 0, 2, 2, "");
    // stair(3, "");

    printPath2(0,0,2,2,"");
}