#include <iostream>
#include <vector>
#include <string>

using namespace std;

void encoding(string num, string asf){



    // 1 char call - eg. 2719
    string ch = num[0];
    string rn = num.substr(1);

    // encoding(rn, asf + )

    // 2 char call - eg. 1019
    // Both calls - eg. 1213
}

int main(int argc, char** argv){
    string number = "1123";

    // char s = '2';
    // cout << s - '0' + 'a' - 1 << endl;
    encoding(number, "");
}