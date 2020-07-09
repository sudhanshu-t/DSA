#include <bits/stdc++.h>
using namespace std;

class IOperator {
public:
    virtual int operation (int lhs, int rhs) = 0;
    virtual int identity () = 0;
};

class sumPlug : public IOperator {
public:
    int operation (int a, int b) {
        return a + b;
    }

    int identity () {
        return 0;
    }
};

class prodPlug : public IOperator {
public:
    int operation (int a, int b) {
        return a * b;
    }

    int identity () {
        return 1;
    }
};

class minPlug : public IOperator {
public:
    int operation (int a, int b) {
        return min(a, b);
    }

    int identity () {
        return INT_MAX;
    }
};

class maxPlug : public IOperator {
public:
    int operation (int a, int b) {
        return max(a, b);
    }

    int identity () {
        return INT_MIN;
    }
};

class gcdPlug : public IOperator {
public:
    int operation (int a, int b) {
        if (b == 0) {
            return a;
        }

        return operation (b, a % b);
    }

    int identity () {
        return 0;
    }
};

int logCeil (int n) {
    int x = 1;
    while ((1 << x) <= n) {
        x++;
    }

    return x;
}

class stree {
public:
    vector<int> oa;
    vector<int> sa;
    int oas;
    int sas;
    IOperator* opr;

    stree (IOperator* opr, vector<int> oa) {
        this->oa = oa;
        this->opr = opr;
        this->oas = oa.size();

        int h = logCeil(oas) + 1;
        this->sas = (1 << h) - 1;
        
        build(0, oas - 1, 0);
    }

    void build (int lo, int hi, int idx) {
        if (lo == hi) {
            sa[idx] = oa[lo];
            return;
        }

        int mid = lo + (hi - lo) / 2;
        build(lo, mid, 2 * idx + 1);
        build(mid + 1, hi, 2 * idx + 2);

        sa[idx] = opr->operation(sa[2 * idx + 1], sa[2 * idx + 2]);
    }
};

int main() {
    vector<int> arr = {2,5,-3,6,7,14,1,9};
    IOperator* opr = NULL;
}