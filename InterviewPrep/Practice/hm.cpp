#include <string>
#include <iostream>
#include <list>

using namespace std;

template<class K, class V>
class hm{
private:
    class hmNode{
    public:
        K key;
        V value;

        hmNode(K k, V v){
            key = k;
            value = v;
        }   
    };

    list<hmNode>* buckets = NULL;
    int n;
    int N;
    double lambda;

    typename list<hmNode>::iterator getDataIndex(int bi, K key){
        for(auto itr = buckets[bi].begin(); itr != buckets[bi].end(); itr++){
            if(itr->key == key){
                return itr;
            }
        }

        return buckets[bi].end();
    }

    int getBucketIndex(K key){
        int hc = hash<K>()(key);
        hc = abs(hc) % N;
        return hc;
    }

    void rehash(){
        int oldN = N;
        list<hmNode>* oldBuckets = buckets;

        N = 2*N;
        n = 0;
        for(int i = 0; i < oldN; i++){
            for(auto itr = buckets[i].begin(); itr != buckets[i].end(); itr++){
                (*this)[itr->key] = itr->value;
            }
        }

        delete[] oldBuckets;
    }

public:
    hm(){
        n = 0;
        N = 4;

        buckets = new list<hmNode>[N];
    }

    V& operator[](K key){
        int bi = getBucketIndex(key);
        auto itr = getDataIndex(bi, key);

        if(itr == buckets[bi].end()){
            hmNode node(key, V());

            buckets[bi].push_back(node);

            n++;
            lambda = (n*1.0) / N;
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

    void erase(K key){
        int bi = getBucketIndex(key);
        auto itr = getDataIndex(bi, key);

        buckets[bi].erase(itr);
        n--;
    }

    void display(){
        for(int i = 0; i < N; i++){
            cout << i << " -> ";
            for(auto itr: buckets[i]){
                cout << "[" << itr.key << ", " << itr.value << "] ";
            }
            cout << endl;
        }
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

    int size(){
        return n;
    }
};

int main(){
    hm<string, int> map;
    cout << "Map created!" << endl;

    map["Sudhanshu"] = 1;
    map["Shona"] = 100;
    map["Billu"] = 33;

    cout << map.count("Sudhanshu") << endl;
    map.erase("Sudhanshu");
    cout << map.count("Sudhanshu") << endl;

    cout << map.size() << endl;

    map.display();
}