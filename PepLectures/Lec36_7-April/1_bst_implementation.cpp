#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Node* construct(vector<int>& dlist){
//     if(dlist.size() == 1){
//         Node* base_root = new Node(dlist[0]);
//         return base_root;
//     }

//     int mid = (dlist.size() % 2 == 0) ? (dlist.size() / 2) - 1 : dlist.size() / 2;

//     vector<int> left_list, right_list;

//     for(int i = 0; i < mid; i++){
//         left_list[i] = dlist[i];
//     }

//     for(int i = mid+1; i < dlist.size(); i++){
//         left_list[i-mid-1] = dlist[i];
//     }

//     Node* left = construct(left_list);
//     Node* right = construct(right_list);

//     Node* root = new Node(dlist[mid]);

//     root->left = left;
//     root->right = right;

//     return root;
// }

Node* construct(vector<int>& dlist, int lo, int hi)
{
    if(lo > hi){
        return NULL;
    }

    int mid = (lo + hi) / 2;

    Node* left = construct(dlist, lo, mid - 1);
    Node* right = construct(dlist, mid + 1, hi);

    Node* root = new Node(dlist[mid]);

    root->left = left;
    root->right = right;

    return root;
}

void display(Node* root)
{
    if(root->left){
        cout << root->left->data << " ";
    } else {
        cout << " . ";
    }

    cout << "<--" << root->data << "--> ";

    if(root->right){
        cout << root->right->data << " ";
    } else {
        cout << ". ";
    }

    cout << endl;

    if(root->left){
        display(root->left);
    }
    if(root->right){
        display(root->right);
    }
}

int min(Node* root)
{
    if(root->left != NULL){
        return min(root->left);
    } else {
        return root->data;
    }
}

int min_reactive(Node* root)
{
    if(root == NULL){
        return -1;
    }
    
    int left_min = min(root->left);

    if(left_min == -1){
        return root->data;
    }

    return left_min;
}

// Iterative Max
int max(Node* root)
{
    int data;

    while(root != NULL){
        data = root->data;
        root = root->right;
    }
    
    return data;
}

bool find(Node* root, int data)
{
    if(root == NULL){
        return false;
    }

    if(root->data == data){
        return true;
    } else if(data < root->data){
        return find(root->left, data);
    } else {
        return find(root->right, data);
    }
}

void print_in_range(Node* root, int lo, int hi)
{
    if(root == NULL){
        return;
    }
    
    if(root->data > hi){
        print_in_range(root->left, lo, hi);
    } else if(root->data < lo){
        print_in_range(root->right, lo, hi);
    } else {
        // In sorted order print --> Inorder 
        print_in_range(root->left, lo, hi);
        cout << root->data << endl;
        print_in_range(root->right, lo, hi);
    }
}

void replace_with_larger_sum(Node* root, int& sum)
{
    if(root == NULL){
        return;
    }

    replace_with_larger_sum(root->right, sum);

    int root_data = root->data;
    root->data = sum;
    sum += root_data;

    replace_with_larger_sum(root->left, sum);
}

void pair_sum_target(Node* original_root, Node* root, int target)
{
    if(root == NULL){
        return;
    }

    // bool found = false;

    // if(target - root->data < root->data){
    //     found = find(root, target - root->data);
    // }

    // if(found){
    //     cout << root->data << ", " << target - root->data << endl;
    //     pair_sum_target(root->left, target - root->data);
    //     pair_sum_target(root->right, target - root->data);
    // }

    int comp = target - root->data;

    if(comp > root->data && find(original_root, comp)){
        cout << comp << " " << root->data << endl;
    }

    pair_sum_target(original_root, root->left, target);
    pair_sum_target(original_root, root->right, target);
}

class inorder_stack{
public:
    Node* root;
    int state;

    inorder_stack(Node* root, int state){
        this->root = root;
        this->state = state;
    }
};

void inorder_vector_filler_iterative(Node* root, vector<inorder_stack*>& array)
{
    list<inorder_stack*> stack;

    inorder_stack* r_obj = new inorder_stack(root, 0);

    stack.push_front(r_obj);

    while(stack.empty() == false){
        inorder_stack* front = stack.front();

        if(front->state == 0)
        {
            Node* child = front->root->left;
            if(child != NULL){
                // cout << front->root->data << " ";
                inorder_stack* c = new inorder_stack(child, 0);
                stack.push_front(c);
            }
            front->state++;
        }
        else if(front->state == 1)
        {
            // cout << front->root->data << " ";
            array.push_back(front);
            front->state++;
            // return;
        }
        else if(front->state == 2)
        {
            Node* child = front->root->right;    
            if(child != NULL){
                // cout << front->root->data << " ";
                inorder_stack* c = new inorder_stack(child, 0);
                stack.push_front(c);
            }
            front->state++;
        }
        else
        {
            // delete front;
            stack.pop_front();
        }
    }
}

void pair_sum_target_2(Node* root, int target){
// vector filling approach
    vector<inorder_stack*> array;

    inorder_vector_filler_iterative(root, array);

    for(int i = 0; i < array.size(); i++){
        cout << array[i]->root->data << " ";
    }

    cout << endl;

    int left = 0;
    int right = array.size() - 1;

    while(array[left]->root->data < array[right]->root->data){
        if(array[left]->root->data + array[right]->root->data == target){
            cout << array[left]->root->data << " " << array[right]->root->data << endl;
            left++;
            right--;
        }
        else if(array[left]->root->data + array[right]->root->data > target){
            right--;
        }
        else {
            left++;
        }
    }
    
    // cout << endl;
// O(n) for BST
// O(nlogn) for BT (since sorting is required)
}

void inorder_print_stack_iterative(list<inorder_stack*>& stack)
{
    while(stack.empty() == false){
        inorder_stack* front = stack.front();

        if(front->state == 0)
        {
            Node* child = front->root->left;
            if(child != NULL){
                // cout << front->root->data << " ";
                inorder_stack* c = new inorder_stack(child, 0);
                stack.push_front(c);
            }
            front->state++;
        }
        else if(front->state == 1)
        {
            // cout << front->root->data << " ";
            front->state++;
            return;
        }
        else if(front->state == 2)
        {
            Node* child = front->root->right;    
            if(child != NULL){
                // cout << front->root->data << " ";
                inorder_stack* c = new inorder_stack(child, 0);
                stack.push_front(c);
            }
            front->state++;
        }
        else
        {
            delete front;
            stack.pop_front();
        }
    }
}

void reverse_inorder_print_stack_iterative(list<inorder_stack*>& stack)
{
    while(stack.empty() == false){
        inorder_stack* front = stack.front();

        if(front->state == 0)
        {
            Node* child = front->root->right;    
            if(child != NULL){
                // cout << front->root->data << " ";
                inorder_stack* c = new inorder_stack(child, 0);
                stack.push_front(c);
            }
            front->state++;
        }
        else if(front->state == 1)
        {
            // cout << front->root->data << " ";
            front->state++;
            return;
        }
        else if(front->state == 2)
        {
            Node* child = front->root->left;
            if(child != NULL){
                // cout << front->root->data << " ";
                inorder_stack* c = new inorder_stack(child, 0);
                stack.push_front(c);
            }
            front->state++;
        }
        else
        {
            delete front;
            stack.pop_front();
        }
    }
}

void pair_sum_target_3(Node* root, int target)
{
    list<inorder_stack*> s1;
    list<inorder_stack*> s2;

    inorder_stack* r_obj1 = new inorder_stack(root, 0);
    inorder_stack* r_obj2 = new inorder_stack(root, 0);

    s1.push_front(r_obj1);
    s2.push_front(r_obj2);

    inorder_print_stack_iterative(s1);
    reverse_inorder_print_stack_iterative(s2);

    inorder_stack* front_left = s1.front();
    inorder_stack* front_right = s2.front();

    while(front_left->root->data < front_right->root->data){
        
        if(front_left->root->data + front_right->root->data == target){
            cout << front_left->root->data << " " << front_right->root->data << endl;
            inorder_print_stack_iterative(s1);
            reverse_inorder_print_stack_iterative(s2);
        } 
        else if (front_left->root->data + front_right->root->data > target){
            reverse_inorder_print_stack_iterative(s2);
        }
        else {
            inorder_print_stack_iterative(s1);
        }

        front_left = s1.front();
        front_right = s2.front();
    }
    
    return;
}

int main(int argc, char** argv)
{
    vector<int> dlist = {10, 20, 40, 50, 60, 70, 80};

    Node* root = construct(dlist, 0, dlist.size() - 1);
    display(root);

    cout << min(root) << endl;
    cout << max(root) << endl;
    cout << find(root, 10) << endl;

    print_in_range(root, 20, 70);

    int sum = 0;
    // replace_with_larger_sum(root, sum);

    display(root);

    // pair_sum_target(root, root, 100);
    pair_sum_target_2(root, 100);
    // pair_sum_target_3(root, 100);

    // inorder_print_stack_iterative(root);
    // cout << endl;
}