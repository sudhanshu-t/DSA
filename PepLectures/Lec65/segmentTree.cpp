// ======= LAZY APPROACH ======= //

#include <iostream>

using namespace std;

int getLogCeil(int n){
    int x = 1;

    while((1 << x) <= n){
        x++;
    }

    return x;
}

class lst{
private:
    int* oa;
    int oas;
    int* sa;
    int sas;
    int* la;

public:
    lst(int* oa, int oas){
        this->oa = oa;
        this->oas = oas;

        int h = getLogCeil(oas) + 1;
        this->sas = (1 << h) - 1;

        sa = new int[sas];
        la = new int[sas];

        build(0, oas - 1, 0);
    }

    void build(int ss, int se, int si){
        if(ss == se){
            sa[si] = oa[ss];
            la[si] = 0;
            return;
        }

        int mid = (ss + se) / 2;
        build(ss, mid, 2 * si + 1);
        build(mid + 1, se, 2 * si + 2);

        la[si] = 0;

        sa[si] = sa[2 * si + 1] + sa[2 * si + 2];
    }

    void update(int qs, int qe, int val, int ss, int se, int si){
        handlePW(ss, se, si);

        if(ss >= qs && se <= qe){
            la[si] += val;
            handlePW(ss, se, si);
            return;
        } else if(ss > qe || se < qs){
            return;
        } else {
            int mid = (ss + se) / 2;

            update(qs, qe, val, ss, mid, 2 * si + 1);
            update(qs, qe, val, mid + 1, se, 2 * si + 2);

            sa[si] = sa[2 * si + 1] + sa[2 * si + 2];
            return;
        }
    }

    int query(int qs, int qe, int ss, int se, int si){
        handlePW(ss, se, si);

        if(ss >= qs && se <= qe){
            return sa[si];
        } else if(ss > qe || se < qs){
            return 0;
        } else {
            int mid = (ss + se) / 2;

            int lc = query(qs, qe, ss, mid, 2 * si + 1);
            int rc = query(qs, qe, mid + 1, se, 2 * si + 2);

            return lc + rc;
        }
    }

    void handlePW(int ss, int se, int si){
        sa[si] += la[si] * (se - ss + 1);

        if(ss != se){
            la[2 * si + 1] += la[si];
            la[2 * si + 2] += la[si];
        }

        la[si] = 0;
    }
};

int main(int argc, char** argv){
    int* arr = new int[8] {1,2,3,4,5,6,7,8};
    lst st(arr, 8);

    // cout << getLogCeil(8) << endl;
    cout << st.query(2, 5, 0, 7, 0) << endl;

    st.update(4, 7, 10, 0, 7, 0);

    cout << st.query(2, 5, 0, 7, 0) << endl;
}