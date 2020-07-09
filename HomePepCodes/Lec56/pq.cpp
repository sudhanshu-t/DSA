#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void kLarg1(vector<int>& arr, int k){
    priority_queue<int> pq;

    for(int i = 0; i < arr.size(); i++){
        pq.push(arr[i]);
    }

    for(int i = 0; i < k; i++){
        cout << pq.top() << endl;
        pq.pop();
    }
}

void kLarg2(vector<int>& arr, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0;
    while(i != arr.size()){
        if(i < k){
            pq.push(arr[i]);
            // cout << pq.top() << endl;
            i++;
            continue;
        }

        int currmin = pq.top();
        // cout << currmin << " " << arr[i] << endl;
        if(arr[i] > currmin){
            pq.pop();
            pq.push(arr[i]);
        }

        i++;
    }

    while(pq.size() != 0){
        cout << pq.top() << endl;
        pq.pop();
    }
}

void kSortedArray(vector<int>& arr, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    int i;
    for(i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    // i = 0;
    while(i != arr.size()){
        if(pq.top() > arr[i]){
            cout << arr[i] << " ";
        } else {
            cout << pq.top() << " ";
            pq.pop();
            pq.push(arr[i]);
        }

        // cout << pq.size() << endl;

        i++;
    }

    while(pq.size() != 0){
        cout << pq.top() << " ";
        pq.pop();
    }
}

class Node{
    public:
    int data;
    int arr_no;
    int index;

    Node(int data, int an, int idx){
        index = idx;
        this->data = data;
        arr_no = an;
    }

    bool operator>(const Node& o) const {
        return this->data > o.data;
    }
};

void mergeKSortedLists(vector<vector<int>>& arr){
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    // cout << arr.size() << endl;

    // int i;
    for(int i = 0; i < arr.size(); i++){
        pq.push(Node (arr[i][0], i, 0));
        // cout << "Node added " << arr[i][0] << endl;
        // cout << pq.size() << endl;
    }

    // cout << i << endl;

    while(pq.size() != 0){
        Node small = pq.top(); pq.pop();
        
        cout << small.data << " ";

        if(small.index + 1 < arr[small.arr_no].size())
            pq.push(Node (arr[small.arr_no][small.index + 1], small.arr_no, small.index + 1));
    }
    cout << endl;
}

class MedianPQ{
private:
    void rebalance(){
        if(left.size() - right.size() == 2){
            int val = left.top(); left.pop();
            right.push(val);
        } else if(left.size() - right.size() == -2){
            int val = right.top(); right.pop();
            left.push(val);
        }
    }

public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    void push(int val){
        if(left.size() != 0 && val < left.top()){
            left.push(val);
        } else {
            right.push(val);
        }

        rebalance();
    }

    int top(){
        if(left.size() > right.size()){
            return left.top();
        } else {
            return right.top();
        }
    }

    void pop(){
        if(left.size() > right.size()){
            return left.pop();
        } else {
            return right.pop();
        }
    }
};

template<class T>
class pq{
private:
    vector<T> list;
    bool (*comptor)(const T& o1, const T& o2) = NULL;

    bool ishp(int i, int j){
        if(this->comptor == NULL){
            return list[j] < list[i];
        } else {
            return comptor(list[i], list[j]);
        }
    }

    void swap(int i, int j){
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }

    void upHeapify(int i){
        if(i == 0){
            return;
        }
        
        int pi = (i - 1) >> 1;

        if(ishp(i, pi)){
            swap(i, pi);
            upHeapify(pi);
        }
    }

    void downHeapify(int i){       
        int li = i*2 + 1;
        int ri = i*2 + 2;

        int hpi = i;
        if(li < list.size() && ishp(li, hpi)){
            swap(li, hpi);
        }

        if(ri < list.size() && ishp(ri, hpi)){
            swap(ri, hpi);
        }

        if(hpi != i){
            swap(i, hpi);
            downHeapify(hpi);
        }
    }

public:
    pq(){
        this->comptor = NULL;
    }

    pq(bool (*comptor)(const T& o1, const T& o2)){
        this->comptor = comptor;
    }

    pq(vector<int>& arr){
        for(int i = 0; i < arr.size(); i++){
            list.push_back(arr[i]);
        }

        for(int i = list.size() - 1; i >= 0; i--){
            downHeapify(i);
        }
    }

    void push(T n){
        list.push_back(n);
        upHeapify(list.size() - 1);
    }

    T top(){
        if(list.size() == 0){
            return T();
        }

        return list[0];
    }

    void pop(){
        if(list.size() == 0){
            return;
        }
        
        swap(0, list.size() - 1);
        list.pop_back();

        downHeapify(0);
    }

    int size(){
        return list.size();
    }
};

class Student{
    public:
    int marks;
    int extra;
    string name;

    Student(){}

    Student(int marks, int extra, string name){
        this->marks = marks;
        this->extra = extra;
        this->name = name;
    }

    void display(){
        cout << "[" << this->name << " : " << this->marks << ", " << this->extra << "]" << endl;
    }

    bool operator<(const Student& o) const {
        // return this->name.compare(o.name) > 0;
        return this->name > o.name;
    }
};

bool StudentMarksComparator(const Student& s1, const Student& s2){
    return s1.marks > s2.marks;
}

bool StudentExtraComparator(const Student& s1, const Student& s2){
    return s1.extra > s2.extra;
}

bool StudentMarksExtraComparator(const Student& s1, const Student& s2){
    if(s1.marks != s2.marks){
        return s1.marks > s2.marks;
    } else {
        return s1.extra < s2.extra;
    }
}

bool StudentExtraMarksComparator(const Student& s1, const Student& s2){
    if(s1.extra != s2.extra){
        return s1.extra > s2.extra;
    } else {
        return s1.marks < s2.marks;
    }
}

int main(int argc, char** argv){
    vector<int> arr = {10,2,3,4,6,20};

    pq<int> pq(arr);

    while(pq.size() > 0){
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
    
    
    // pq<Student> pq;

    // pq.push(Student (7.01, 40, "Rishabh"));
    // pq.push(Student (10, -40, "Rishabh1"));
    // pq.push(Student (-1000, 40, "Rishabh2"));
    // pq.push(Student (100, 40, "Rishabh3"));
    // pq.push(Student (100, 90, "Sudhanshu"));

    // while(pq.size() != 0){
    //     Student top = pq.top();
    //     pq.pop();

    //     top.display();
    // }
    
    // vector<int> arr = {2,8,14,5,6,1,9,4,20,3,11};

    // kLarg1(arr, 4);
    // kLarg2(arr, 4);

    // vector<int> arr = {20,40,10,30,50,80,60,90,70,120,110,100};
    
    // kSortedArray(arr, 4);

    // vector<vector<int>> arr = {
    //     {2,5,9,18,20,25},
    //     {3,7,8,15,22},
    //     {0,4,6,12,50,100},
    //     {1,10,16,21,28}
    // };

    // mergeKSortedLists(arr);

    // vector<int> test {50,10,80,0,20,90,100,5,70,40};
    // MedianPQ pq;

    // for(int i = 0; i < test.size(); i++){
    //     pq.push(test[i]);
    //     cout << pq.top() << " ";
    // }
    // cout << endl;

    // for(int i = 0; i < test.size(); i++){
    //     pq.pop();
    //     cout << pq.top() << " ";
    // }
    // cout << endl;

    // pq minHeap(false);

    // minHeap.push(10);
    // minHeap.push(8);
    // minHeap.push(4);
    // minHeap.push(20);
    // minHeap.push(30);
    // minHeap.push(1);

    // while(minHeap.size()){
    //     cout << minHeap.top() << endl;
    //     minHeap.pop();
    // }
}