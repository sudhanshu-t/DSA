#include <iostream>
#include <string>

using namespace std;

void perm_q1(string q, string a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    for(int i = 0; i < q.size(); i++){
        char c = q[i];

        string left = q.substr(0, i);
        string right = q.substr(i+1);

        string rq = left + right;
        perm_q1(rq, a + c);
    }
}

void perm_a1(string q, string a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    char c = q[0];
    string rq = q.substr(1);

    for(int i = 0; i < a.size() + 1; i++){
        string left = a.substr(0, i);
        string right = a.substr(i);

        perm_a1(rq, left + c + right);
    }
}

void perm_q2(string& q, string& a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    for(int i = 0; i < q.size(); i++){
        char c = q[i];
        string left = q.substr(0, i);
        string right = q.substr(i+1);
        string rq = left + right;

        perm_q2(rq, a + c);
    }
}

int main(int argc, char** argv){
    // perm_q1("abc", "");
    // perm_q2("abc", "");
    // perm_a1("abc", "");
}