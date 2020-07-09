#include <iostream>
#include <climits>

using namespace std;

int getLogCeil(int n){
    int x = 0;

    while((1 << x) < n){
        x++;
    }

    return x;
}

// Socket
class IOperator{
    private:
    public:

    virtual int operation(int lhs, int rhs) = 0;
    virtual int identity() = 0;
};

// Sum Plug
class SumOperator : public IOperator{
public:
    int operation(int lhs, int rhs){
        return lhs + rhs;
    }

    int identity(){
        return 0;
    }
};

// Product Plug
class ProductOperator : public IOperator{
public:
    int operation(int lhs, int rhs){
        return lhs * rhs;
    }

    int identity(){
        return 1;
    }
};

// Max Plug
class MaxOperator : public IOperator{
public:
    int operation(int lhs, int rhs){
        return max(lhs, rhs);
    }

    int identity(){
        return INT_MIN;
    }
};

// Min Plug
class MinOperator : public IOperator{
public:
    int operation(int lhs, int rhs){
        return min(lhs, rhs);
    }

    int identity(){
        return INT_MAX;
    }
};

// GCD Plug
class gcdOperator : public IOperator{
public:
    int operation(int a, int b){
        if(b == 0){
            return a;
        }

        return operation(b, a % b);
    }

    int identity(){
        return 0;
    }
};

class stree{
private:
    int* oa;
    int oas;
    int * sa;
    int sas;
    IOperator* opr = NULL;

public:
    void build(int ss, int se, int si){
        if(ss == se){
            sa[si] = oa[ss];
            return;
        }

        int mid = (ss + se) / 2;

        build(ss, mid, 2*si + 1);
        build(mid + 1, se, 2*si + 2);

        sa[si] = opr->operation(sa[2*si + 1], sa[2*si + 2]);
    }

    int query(int qs, int qe, int ss, int se, int si){
        if(ss >= qs && se <= qe){
            return sa[si];
        } else if(qe < ss || qs > se){
            return opr->identity();
        } else {
            int mid = (ss + se) / 2;
            int lc = query(qs, qe, ss, mid, 2*si + 1);
            int rc = query(qs, qe, mid + 1, se, 2*si + 2);

            return opr->operation(lc, rc);
        }
    }

    void update(int idx, int val, int ss, int se, int si){
        if(ss == se){
            oa[idx] = val;
            sa[si] = val;
            return;
        }

        int mid = (ss + se) / 2;
        if(idx <= mid){
            update(idx, val, ss, mid, 2*si + 1);
        } else {
            update(idx, val, mid + 1, se, 2*si + 2);
        }

        sa[si] = opr->operation(sa[2*si + 1], sa[2*si + 2]);
    }

    stree(IOperator* opr, int* oa, int oas){
        this->opr = opr;
        this->oa = oa;
        this->oas = oas;

        int h = getLogCeil(oas) + 1;
        sas = (1 << h) - 1;
        sa = new int[sas];

        build(0, 7, 0);
    }
};

int main(int argc, char** argv){
    int* arr = new int[8] {2,5,-3,6,7,14,1,9}; 

    IOperator* opr = NULL;
    int choice;
    cin >> choice;

    if(choice == 1){
        opr = new SumOperator();
    } else if(choice == 2){
        opr = new ProductOperator();
    } else if(choice == 3){
        opr = new MaxOperator();
    } else if(choice == 4) {
        opr = new MinOperator();
    } else {
        opr = new gcdOperator();
    }

    stree st (opr, arr, 8);

    cout << st.query(2, 5, 0, 7, 0) << endl;
    cout << st.query(6, 7, 0, 7, 0) << endl;

    st.update(4, 17, 0, 7, 0);

    cout << st.query(2, 5, 0, 7, 0) << endl;
    cout << st.query(1, 3, 0, 7, 0) << endl;

    cout << st.query(2, 3, 0, 7, 0) << endl;

    return 0;
}