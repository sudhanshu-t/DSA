#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char** argv){
    char c;
    cin >> c;

    if(c >= 'A' && c <= 'Z'){// ascii comparison w/o conversion to int
        cout << "Uppercase" << endl;
        char lc = 'a' + (c - 'A'); // Converts rhs to int, lhs is still char
        
        cout << "Converted to Lowercase: " <<  lc << endl;
    } else if(c >= 'a' && c <= 'z'){
        cout << "Lowercase" << endl;
        char uc = 'A' + (c - 'a');

        cout << "Converted to Uppercase: " << uc << endl;
    } else {
        cout << "Enter an alphabet" << endl;
    }
    
    return 0;
}
