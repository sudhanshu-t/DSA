#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "3+4i";
    string b = "5+-20i";

    char ca[a.size() + 1];
    strcpy(ca, a.c_str());
    char* token = strtok(ca, "+i");
    while (token != NULL) {
        cout << token << endl;
        token = strtok(NULL, "+i");
    }

    char cb[b.size() + 1];
    strcpy(cb, b.c_str());
    token = strtok(cb, "+i");
    while (token != NULL) {
        cout << token << endl;
        token = strtok(NULL, "+i");
    }
}