#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
#include <vector>
#include <list>

using namespace std;

void pce1(vector<int>& one, vector<int>& two){
    unordered_map<int, int> map;
    
    for(int i : one){
        if(map.count(one[i]) == false){
            map[one[i]] = 1;
        } else {
            map[one[i]]++;
        }
    }

    for(int i : two){
        if(map.count(two[i]) != 0){
            cout << two[i] << endl;
            map.erase(two[i]);
        }
    }
}

void pce2(vector<int>& one, vector<int>& two){
    unordered_map<int, int> map;

    for(int i = 0; i < one.size(); i++){
        map[one[i]]++;
    }

    for(auto itr : map){
        cout << itr.first << " " << itr.second << endl;
    }

    for(int i = 0; i < two.size(); i++){
        if(map.count(two[i]) == 1 && map[two[i]] > 0){
            cout << two[i] << endl;
            map[two[i]]--;
        }
    }
}

void longestConsecutiveSequence(vector<int>& arr){
    // map[i] == true means i is the start of sequence containing itself
    unordered_map<int, bool> map;

    for(int i : arr){
        map[i] = true;
    }

    for(int i : arr){
        if(map.count(i - 1)){
            map[i] = false;
        }
    }

    int os = 0;
    int ol = 0;
    for(int i : arr){
        if(map[i] == true){
            int ts = i;
            int tl = 1;

            while(map.count(ts + tl)){
                tl++;
            }

            if(tl > ol){
                ol = tl;
                os = ts;
            }
        }
    }

    cout << os << " of length " << ol << endl;
}

template<class K, class V>
class hm{
    private:
    class hmnode{
        public:
        K key;
        V value;

        hmnode(K key, V value){
            this->key = key;
            this->value = value;
        }
    };

    list<hmnode>* buckets = NULL;

    int n;
    int N;
    double lambda;

    int getBucketIndex(K key){
        int hc = hash<K>()(key);
        hc = abs(hc);
        hc = hc % N;

        return hc;
    }

    typename list<hmnode> :: iterator getDataIndex(int bi, K key){
        for(typename list<hmnode>::iterator itr = buckets[bi].begin(); itr != buckets[bi].end(); itr++){
            if(itr->key == key){
                return itr;
            }
        }

        return buckets[bi].end();
    }

    void rehash(){
        int oldN = N;
        list<hmnode>* oldB = buckets;

        N = 2*N;
        n = 0;
        buckets = new list<hmnode>[N];

        for(int i = 0; i < oldN; i++){
            for(auto itr = oldB[i].begin(); itr != oldB[i].end(); itr++){
                (*this)[itr->key] = itr->value;
            }
        }

        delete[] oldB;
    }

    public:
    hm(){
        n = 0;
        N = 4;
        lambda = (n * 1.0) / N; 

        buckets = new list<hmnode>[N];
    }

    int count(K key){
        int bi = getBucketIndex(key);
        auto itr = getDataIndex(bi, key);

        if(itr == buckets[bi].end()){
            return 0;
        } else {
            return 1;
        }
    }

    V& operator[](const K& key){
        int bi = getBucketIndex(key);
        auto itr = getDataIndex(bi, key);

        if(itr == buckets[bi].end()){
            hmnode node (key, V());
            buckets[bi].push_back(node);
            n++;

            lambda = (n * 1.0) / N;

            if(lambda > 2){
                rehash();
                bi = getBucketIndex(key);
                itr = getDataIndex(bi, key);
            } else {
                return buckets[bi].back().value;                
            }
        }

        return itr->value;
    }

    int size(){
        return n;
    }

    void display(){
        cout << "------------------------------------------------" << endl;
        for(int bi = 0; bi < N; bi++){
            cout << bi << ". ";
            for(auto itr = buckets[bi].begin(); itr != buckets[bi].end(); itr++){
                cout << "[ " << itr->key << ", " << itr->value << " ] ";
            }
            cout << endl;
        }
        cout << "------------------------------------------------" << endl;
    }

    void erase(K key){
        int bi = getBucketIndex(key);
        auto itr = getDataIndex(bi, key);

        buckets[bi].erase(itr);
        n--;
    }
};

int main(int argc, char** argv){
    hm<string, int> map;

    map["India"] = 10;
    map["Russia"] = 8;
    map["Turkey"] = 18;
    map["UK"] = 80;
    map["China"] = 800;
    map["Bangla"] = 100;
    map["Italy"] = 120;
    map["Aus"] = 98;
    map["US"] = 128;

    // cout << map.size() << endl;

    map.display();

    map.erase("Italy");
    
    map.display();

    // unordered_map<char, int> fm;

    // int mymax = INT_MIN;
    // char ans;
    // string s = "abbccddaccbdacdcba";
    // for(int i = 0; i < s.size(); i++){
    //     char ch = s[i];
    //     if(fm.count(ch)){
    //         fm[ch]++;
    //         if(mymax < fm[ch]){
    //             mymax = fm[ch];
    //             ans = ch;
    //         }
    //     }
    //     else
    //         fm[ch] = 1;
    // }

    // cout << ans << " occurs " << mymax << endl;


    // vector<int> one = {2,1,5,1,3,2,1};
    // vector<int> two = {4,5,2,1,2,1,2};
    // pce1(one, two);
    // pce2(one, two);

    // vector<int> arr = {11,3,5,9,12,2,6,8,1,10,15,25,20,16};
    // longestConsecutiveSequence(arr);


}