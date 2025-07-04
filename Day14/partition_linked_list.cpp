#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* gehead = new ListNode();
    ListNode* ge = gehead;
    ListNode* lhead = new ListNode();
    ListNode* l = lhead;
    ListNode* temp = head;
    while(temp){
        if(temp->val < x){
            l->next = temp;
            l = l->next;
        }
        else{
            ge->next = temp;
            ge = ge->next;
        }
        temp = temp->next;
    }
    ge->next = NULL;
    l->next = gehead->next;
    return lhead->next;
}
