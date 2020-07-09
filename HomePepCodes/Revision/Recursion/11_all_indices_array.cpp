#include <iostream>
using namespace std;

int* all_indices_post(int* arr, int n, int idx, int key, int* p_size){
    if(idx == n){
        // cout << "BC" << endl;
        *p_size = 0;
        return NULL;
    }

    int* ans = all_indices_post(arr, n, idx + 1, key, p_size);
    
    if(arr[idx] == key){
        *p_size += 1;
        int* final_ans = new int(*p_size);
        // cout << "Hi" << endl;
        final_ans[0] = idx;
        // cout << final_ans[1] << endl;

        // cout << *p_size << endl;

        for(int i = 1; i < *p_size; i++){
            final_ans[i] = ans[i-1];    
        }

        return final_ans;
    } else {
        return ans;
    }
}

int main(int argc, char** argv){
    int n;
    cin >> n;

    int* arr = new int(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int size = 0;
    int* ans = all_indices_post(arr, n, 0, key, &size);

    cout << size << endl;
    for(int i = 0; i < size; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
}