#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

void pattern_d_i(string s){
    stack<int> st;
    int num = 1;

    for(int i = 0; i <= s.size(); i++){
        st.push(num);
        num++;

        if(s[i] == 'i'){
            while(st.size() > 0){
                cout << st.top();
                st.pop();
            }
        }
    }

    // st.push(num++);
    while(st.size() > 0){
        cout << st.top();
        st.pop();
    }

    cout << endl;
}

void next_greater_element(int arr[], int n){
    stack<int> st;

    for(int i = 0; i < n; i++){
        st.push(arr[i]);
    }
    
    int nge = arr[n-1];
    st.pop();
    cout << "-1" << endl;

    for(int i = n-2; i >= 0; i--){
        int popped = st.top();
        st.pop();
        int top = st.top();

        if(popped > top){
            cout << popped << endl;
            if(popped > nge){
                nge = popped;
            }
        } else {
            cout << nge << endl;
        }
    }
}

void nge_rtol(int arr[], int n){
    stack<int> st;
    
    for(int i = n-1; i >= 0; i--){
        while(st.size() > 0){
            if(st.top() < arr[i]){
                st.pop();
            } else {
                cout << st.top() << endl;
                st.push(arr[i]);
            }
        }

        if(st.empty()){
            cout << "-1" << endl;
            st.push(arr[i]);
        }
    }
}

// class helper_nge {
// public:
//     int val;
//     int index;

//     helper_nge(int val, int index){
//         this->val = val;
//         this->index = index;
//     }
// };

void nge_ltor(vector<int>& v){
    stack<int> st;

    vector<int> res (v.size(), 0);

    for(int i = 0; i < v.size(); i++){
        while(st.size() > 0 && v[st.top()] < v[i]){
                res[st.top()] = v[i];
                // cout << v[i] << "-->" << st.top() << endl;
                st.pop();
        }

        st.push(i);
    }

    while(st.size() > 0){
        res[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    cout << endl;
}

int max_area_histo(vector<int>& v){
    vector<int> rb (v.size(), 0);
    vector<int> lb (v.size(), 0);
    vector<int> area (v.size(), 0);

    // Right Boundary (Using 1st approach)
    stack<int> st;

    rb[v.size() - 1] = v.size();
    for(int i = v.size()-2; i >= 0; i--){
        while(st.size() > 0){
            if(v[st.top()] > v[i]){
                st.pop();
            } else {
                rb[i] = st.top();
            }
        }

        if(st.empty()){
            rb[i] = v.size();
        }

        st.push(i);
    }

    // Left Boundary (1st approach)
    while(st.size() > 0){
        st.pop();
    }

    lb[0] = -1;

    for(int i = 1; i < v.size(); i++){
        while (st.size() > 0)
        {
            if(v[st.top()] > v[i]){
                st.pop();
            } else {
                lb[i] = st.top();
            }
        }
        
        if(st.empty()){
            lb[i] = -1;
        }

        st.push(i);
    }

    // Finding area for each rectangle
    for(int i = 0; i < v.size(); i++){
        area[i] = v[i] * (rb[i] - lb[i] - 1);
    }

    int max = INT_MIN;
    for(int i = 0; i < v.size(); i++){
        if(area[i] > max){
            max = area[i];
        }
    }

    return max;
}

vector<int>* sliding_window(vector<int>& v, int k){
    stack<int> st;
    vector<int> nge (v.size(), 0);

    // cout << "Hi" << endl;
    for(int i = v.size() - 1; i >= 0; i--){
        while(st.size() > 0 && v[st.top()] < v[i]){
            st.pop();
        }

        nge[i] = st.size() == 0? v.size(): st.top();
        st.push(i);
    }

    // cout << "Hi" << endl;

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[nge[i]] << " ";
    // }

    // cout << endl;

    vector<int>* res = new vector<int>();
    // res = {0};
    int j = 0;

    for(int i = 0; i < v.size() - k + 1; i++){
        if(j < i){
            j = i;
        }

        while(nge[j] < i + k){
            j = nge[j];
        }

        (*res).push_back(nge[j]);
    }

    return res;
}

bool duplicate_bracket(string s){
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == ')'){
            if(st.top() == '('){
                return true;
            } else {
                while(st.top() != '('){
                    st.pop();
                }

                st.pop();
            }
        } else {
            st.push(ch);
        }
    }

    return false;
}

int celebrity_left_right(vector<vector<bool>>& data){
    int left = 0;
    int right = data.size() - 1;

    while(left != right){
        if(data[left][right] == true){
            left++;
        } else if(data[left][right] == false){
            right--;
        } else if(data[right][left] == true){
            right--;
        } else {
            left++;
        }
    }

    for(int i = 0; i < data.size(); i++){
        if(i != left && data[left][i] == true){
            return -1;
        }
    }

    for(int i = 0; i < data.size(); i++){
        if(i != left && data[i][left] == false){
            return -1;
        }
    }

    return left;
}

int celebrity_stack(vector<vector<bool>>& data){
    stack<int> st;

    for(int i = 0; i < data.size(); i++){
        st.push(i);
    }

    while(st.size() > 1){
        int one = st.top();
        st.pop();
        int two = st.top();
        st.pop();

        if(data[one][two]){
            st.push(two);
            // cout << two << endl;
        } else {
            st.push(one);
            // cout << one << endl;
        }
    }

    int left = st.top();

    // cout << left  << endl;
    for(int i = 0; i < data.size(); i++){
        if(i != left && data[left][i] == true){
            return -1;
        }
    }

    for(int i = 0; i < data.size(); i++){
        if(i != left && data[i][left] == false){
            return -1;
        }
    }

    return left;
}

class Interval{
public:
    int start;
    int end;

    Interval(int s, int e){
        this->start = s;
        this->end = e;
    }

    // To compare two intervals acc. to their start times
    bool operator<(const Interval& o) const{
        return this->start < o.start;
    }
};

void overlapping_intervals(vector<int>& start, vector<int>& end){
    vector<Interval> intvs;
    
    for(int i = 0; i < start.size(); i++){
        Interval intv(start[i], end[i]);
        intvs.push_back(intv);
    }

    sort(intvs.begin(), intvs.end());

    stack<Interval> st;

    st.push(intvs[0]);

    for(int i = 1; i < start.size(); i++){
        if(st.top().end > intvs[i].start){
            st.top().end = max(st.top().end, intvs[i].end);
        } else {
            st.push(intvs[i]);
        }
    }

    while(st.size() != 0){
        cout << st.top().start << " - " << st.top().end << endl;
        st.pop();
    }
}

void stock_span(vector<int>& v){
    stack<int> st;
    vector<int> res (v.size(), 0);

    for(int i = 0; i < v.size(); i++){
        while(st.size() > 0 && v[st.top()] < v[i]){
            st.pop();
            // res[i]++;
        }

        res[i] = st.size() == 0 ? i + 1 : i - st.top();
        st.push(i);
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    cout << endl;
}

int eval(int v1, int v2, char op){
    int rv = -1;

    switch(op){
        case '^':
        rv = pow(v1, v2);
        break;

        case '*':
        rv = v1 * v2;
        break;

        case '/':
        rv = v1 / v2;
        break;

        case '+':
        rv = v1 + v2;
        break;

        case '-':
        rv = v1 - v2;
        break;

        default:
        break;
    }

    return rv;
}

int get_priority(char op){
    int rv = -1;

    switch(op){
        case '^':
        rv = 3;
        break;

        case '*':
        case '/':
        rv = 2;
        break;

        case '+':
        case '-':
        rv = 1;
        break;

        default:
        break;
    }

    return rv;
}

int infix_evaluation(string s){
    stack<char> os;
    stack<int> vs;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == '('){
            os.push(ch);
        }
        else if(ch == ')'){
            while(!(os.top() == '(')){
                char op = os.top(); os.pop();
                int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();

                vs.push(eval(v1, v2, op));
            }

            os.pop();
        }
        else if(ch >= '0' && ch <= '9'){
            // operand
            vs.push(ch - '0');
        }
        else {
            // operator
            while(!(os.size() == 0 || 
                    os.top() == '(' || 
                    get_priority(os.top()) < get_priority(ch))){
                char op = os.top(); os.pop();
                int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();

                vs.push(eval(v1, v2, op));
            }

            os.push(ch);
        }
    }
    while(!(os.size() == 0)){
        char op = os.top(); os.pop();
        int v2 = vs.top(); vs.pop();
        int v1 = vs.top(); vs.pop();

        vs.push(eval(v1, v2, op));
    }

    return vs.top();

}

string infix_to_postfix(string exp){
    stack<char> os;
    string postfix;

    for(int i = 0; i < exp.size(); i++){
        char ch = exp[i];
        if(ch == '('){
            os.push(ch);
        } else if(ch == ')'){
            while(os.top() != '('){
                char op = os.top(); os.pop();
                postfix += op;
            }
            os.pop();
        } else if(ch >= '0' && ch <= '9'){
            postfix += ch;
        } else {
            while(os.size() > 0 &&
                  os.top() != '(' &&
                  get_priority(os.top()) >= get_priority(ch)){
                char op = os.top(); os.pop();
                postfix += op;
            }

            os.push(ch);
        }
    }

    while(os.size() > 0){
        char op = os.top(); os.pop();
        postfix += op;
    }

    return postfix;
}

string infix_to_prefix(string exp){
    // Reversing infix
    for(int i = 0; i < exp.size() / 2; i++){
        char temp = exp[i];
        exp[i] = exp[exp.size() - i - 1];
        exp[exp.size() - i - 1] = temp;
    }

    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '('){
            exp[i] = ')';
        } else if(exp[i] == ')'){
            exp[i] = '(';
        }
    }

    exp = infix_to_postfix(exp);

    for(int i = 0; i < exp.size() / 2; i++){
        char temp = exp[i];
        exp[i] = exp[exp.size() - i - 1];
        exp[exp.size() - i - 1] = temp;
    }
    
    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '('){
            exp[i] = ')';
        } else if(exp[i] == ')'){
            exp[i] = '(';
        }
    }

    return exp;
}

void post123(string post){
    stack<int> es; // evaluation stack
    stack<string> in_s; // infix stack
    stack<string> pre_s; // prefix stack

    // Post Evaluation
    for(int i = 0; i < post.size(); i++){
        char ch = post[i];
        if(ch >= '0' && ch <= '9'){
            es.push(ch - '0');
        } else {
            int v2 = es.top(); es.pop();
            int v1 = es.top(); es.pop();

            es.push(eval(v1, v2, ch));
        }
    }

    // Post to In
    for(int i = 0; i < post.size(); i++){
        char ch = post[i];
        string s(1, ch);

        if(ch >= '0' && ch <= '9'){
            in_s.push(s);
        } else {
            string v2 = in_s.top(); in_s.pop();
            string v1 = in_s.top(); in_s.pop();;
            in_s.push('(' + v1 + s + v2 + ')');
        }
    }

    // Post to Pre
    for(int i = 0; i < post.size(); i++){
        char ch = post[i];
        string s(1, ch);

        if(ch >= '0' && ch <= '9'){
            pre_s.push(s);
        } else {
            string v2 = pre_s.top(); pre_s.pop();
            string v1 = pre_s.top(); pre_s.pop();;
            pre_s.push(s + v1 + v2);
        }
    }

    cout << es.top() << " === " << in_s.top() << " === " << pre_s.top() << endl;
}

void pre123(string pre){
    stack<int> es;
    stack<string> is;
    stack<string> ps;

    // Pre Evaluation
    for(int i = pre.size() - 1; i >= 0; i--){
        char ch = pre[i];
        // string s = string() + ch;

        if(ch >= '0' && ch <= '9'){
            es.push(ch - '0');
        } else {
            int v1 = es.top(); es.pop();
            int v2 = es.top(); es.pop();

            es.push(eval(v1, v2, ch));
        }
    }

    // Pre to Infix
    for(int i = pre.size() - 1; i >= 0; i--){
        char ch = pre[i];

        if(ch >= '0' && ch <= '9'){
            string s = string() + ch;
            
            is.push(s);
        } else  {
            string s = string() + ch;

            string v1 = is.top(); is.pop();
            string v2 = is.top(); is.pop();

            is.push('(' + v1 + s + v2 + ')');
        }
    }

    // Pre to Post
    for(int i = pre.size() - 1; i >= 0; i--){
        char ch = pre[i];

        if(ch >= '0' && ch <= '9'){
            string s = string() + ch;
            
            ps.push(s);
        } else  {
            string s = string() + ch;

            string v1 = ps.top(); ps.pop();
            string v2 = ps.top(); ps.pop();

            ps.push(v1 + v2 + s);
        }
    }

    cout << es.top() << " === " << is.top() << " === " << ps.top() << endl;
}

int main(int argc, char** argv){
    pattern_d_i("iddiidid");
    pattern_d_i("ddidddid");

    // int arr[] = {4, 2, 3, 5, 6, 4, 3, 2, 5};
    // next_greater_element(arr, 9);
    // nge_rtol(arr, 9);

    vector<int> v = {4,1,2,7,9,6,5,3,8};
    // nge_ltor(v);

    // int arr[] = {6,2,5,4,5,1,6};
    // cout << max_area_histo(arr, 7) << endl;

    vector<int> ans = *sliding_window(v, 5);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    cout << duplicate_bracket("((a + b) + ((c + d) + e))") << endl;

    vector<vector<bool>> data = {
        {false, false, true, false, true, true},
        {true, false, true, true, true, true},
        {true, false, false, true, true, false},
        {false, false, false, false, true, false},
        {false, false, false, false, false, false},
        {true, false, true, true, true, false}
    };

    // cout << celebrity_left_right(data) << endl;
    cout << celebrity_stack(data) << endl;

    vector<int> starts = {2, 6, 12, 3, 22, 17, 19};
    vector<int> ends = {4, 9, 15, 7, 26, 20, 23};

    overlapping_intervals(starts, ends);

    stock_span(v);

    string i1 = "8+2/3+2^1*(1+3)";
    cout << infix_evaluation(i1) << endl;

    cout << infix_to_postfix(i1) << endl;
    cout << infix_to_prefix(i1) << endl;

    post123("823/+21^13+*+");
    pre123("++8/23*^21+13");

    return 0;
}