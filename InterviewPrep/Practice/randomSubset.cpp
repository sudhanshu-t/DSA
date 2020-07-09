#include <bits/stdc++.h>
using namespace std;

vector<int> randomSubset(int n, int k) {
    unordered_map<int, int> map;
    default_random_engine seed((random_device())());

    for (int i = 0; i < k; i++) {
        int rand_i = uniform_int_distribution<int> {i, n - 1} (seed);

        auto ptr1 = map.find(i);
        auto ptr2 = map.find(rand_i);

        if (ptr1 == map.end() && ptr2 == map.end()) {
            map[rand_i] = i;
            map[i] = rand_i;
        } else if (ptr1 == map.end() && ptr2 != map.end()) {
            map[i] = map[rand_i];
            map[rand_i] = i;
        } else if (ptr1 != map.end() && ptr2 == map.end()) {
            map[rand_i] = map[i];
            map[i] = rand_i;
        } else {
            int temp = map[i];
            map[i] = map[rand_i];
            map[rand_i] = temp;
        }
    }

    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(map[i]);
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> subset = randomSubset(n, k);
    for (int i: subset) cout << i << " ";
    cout << endl;
}