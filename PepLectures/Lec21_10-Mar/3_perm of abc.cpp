#include <iostream>
#include <string>

using namespace std;

void perm_q(string q, string a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    for(int i = 0; i < q.size(); i++){
        char s = q[i];
        string rq1 = q.substr(0, i);
        string rq2 = q.substr(i+1);
        perm_q(rq1 + rq2, a + s);
    }
}
// * //
void perm_a(string q, string a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }
    
    char ch = q[0];
    string rq = q.substr(1);

    for(int i = 0; i < a.size()+1; i++){
        string left = a.substr(0, i);
        string right = a.substr(i);

        perm_a(rq, left + ch + right);
    }
}

// duplicate handler
void perm_q1(string q, string a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }
    
    int bm = 0;
    for(int i = 0; i < q.size(); i++){
        char ch = q[i];
       
        string left = q.substr(0, i);
        string right = q.substr(i + 1);
        
        if((bm & (1 << (ch - 97)) == 0)){
            bm = bm | (1 << (ch-97));

            perm_q1(left + right, a + ch);
        }
    }
}

int main(int argc, char** argv){
    // perm_q("abc", "");
    perm_a("abc", "");
    // perm_q1("aabb", "");
}