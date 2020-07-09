#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    
    int c = 0, d;
    
    ListNode* head;
    ListNode* tail;
    
    bool first = true;
    
    while(t1 != NULL || t2 != NULL || c != 0){
        int d1 = 0, d2 = 0;
        if(t1 != NULL){
            d1 = t1->val;
        }
        
        if(t2 != NULL){
            d2 = t2->val;
        }
        
        d = (c + d1 + d2) % 10;
        c = (c + d1 + d2) / 10;
        
        ListNode* nn = new ListNode(d);
        
        if(first){
            head = nn;
            tail = nn;
            first = false;
        } else {
            tail->next = nn;
            tail = nn;
        }
        
        if(t1 != NULL) t1 = t1->next;
        if(t2 != NULL) t2 = t2->next;
    }
    
    return head;
}
int main(){

}