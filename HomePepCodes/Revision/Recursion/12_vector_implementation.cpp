#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string>* get_sub_seq(string s){
    if(s.size() == 1){
        vector<string>* bres = new vector<string>;
        string b(1, s[0]);
        bres->push_back("-");
        bres->push_back(b);

        return bres;
    }
    
    vector<string>* rres = get_sub_seq(s.substr(1));
    char c = s[0];

    vector<string>* mres = new vector<string>;

    for(int i = 0; i < rres->size(); i++){
        mres->push_back("-" + rres->at(i));
        (*mres).push_back(c + (*rres)[i]);
    }

    return mres;
}

vector<string>* get_sub_seq_2(string s, int i){
    if(i == s.size()){
        vector<string>* bres = new vector<string>;
        bres->push_back("");

        return bres;
    }

    vector<string>* rres = get_sub_seq_2(s, i + 1);

    vector<string>* mres = new vector<string>;

    char c = s[i];

    for(int i = 0; i < rres->size(); i++){
        mres->push_back("-" + rres->at(i));
        mres->push_back(c + rres->at(i));
    }

    return mres;
}

vector<string>* get_path(int cr, int cc, int dr, int dc){
    if(cc > dc || cr > dr){
        vector<string>* bres = new vector<string>;
        return bres;
    }

    if(cc == dc && cr == dr){
        vector<string>* bres = new vector<string>;
        bres->push_back("");
        
        return bres;
    }

    vector<string>* rres_h = get_path(cr, cc + 1, dr, dc);
    vector<string>* rres_v = get_path(cr + 1, cc, dr, dc);

    vector<string>* mres = new vector<string>;

    for(int i = 0; i < rres_h->size(); i++){
        mres->push_back("H" + rres_h->at(i));
    }

    for(int i = 0; i < (*rres_v).size(); i++){
        mres->push_back("V" + (*rres_v)[i]);
    }

    return mres;
}

vector<string>* stair(int n){
    if(n == 0){
        vector<string>* bres = new vector<string>;
        bres->push_back("");
        return bres;
    }

    if(n < 0){
        vector<string>* bres = new vector<string>;
        return bres;
    }

    vector<string>* rres_1 = stair(n-1);
    vector<string>* rres_2 = stair(n-2);
    vector<string>* rres_3 = stair(n-3);

    vector<string>* mres = new vector<string>;

    for(int i = 0; i < rres_1->size(); i++){
        mres->push_back("1-" + rres_1->at(i));
    }
    for(int i = 0; i < rres_2->size(); i++){
        mres->push_back("2-" + rres_2->at(i));
    }
    for(int i = 0; i < rres_3->size(); i++){
        mres->push_back("3-" + rres_3->at(i));
    }

    return mres;
}

vector<string>* stair_proactive(int n){
    if(n == 0){
        vector<string>* bres = new vector<string>;
        (*bres).push_back("");
        
        return bres;
    }
    
    vector<string>* mres = new vector<string>;
    
    if(n-1 >= 0){
        vector<string>* rres_1 = stair_proactive(n-1);

        for(int i = 0; i < rres_1->size(); i++){
            mres->push_back("1-" + rres_1->at(i));
        }
    }
    if(n-2 >= 0){
        vector<string>* rres_2 = stair_proactive(n-2);
        
        for(int i = 0; i < rres_2->size(); i++){
            mres->push_back("2-" + rres_2->at(i));
        }
    }
    if(n-3 >= 0){
        vector<string>* rres_3 = stair_proactive(n-3);
        
        for(int i = 0; i < rres_3->size(); i++){
            mres->push_back("3-" + rres_3->at(i));
        }
    }

    return mres;
}

int main(int argc, char** argv){
    // vector<string>* v = get_sub_seq("abc");
    // vector<string>* v = get_sub_seq_2("abc", 0);

    // for(int i = 0; i < v->size(); i++){
    //     cout << (*v)[i] << endl;
    // }

    // string s = "c";
    // cout << s.substr(1) << endl;

    // vector<string>* v = get_path(0, 0, 2, 2);

    // for(int i = 0; i < v->size(); i++){
    //     cout << (*v)[i] << endl;
    // }

    // vector<string>* v = stair(4);
    vector<string>* v = stair_proactive(4);

    for(int i = 0; i < v->size(); i++){
        cout << v->at(i) << endl;
    }

    return 0;
}