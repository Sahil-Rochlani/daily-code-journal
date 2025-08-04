#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;

        ListNode(int val) : val(val), next(NULL) {}
};
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(int i = 0; i < lists.size();i++){
            if(lists[i])
            pq.push(lists[i]);
        }
        ListNode *head = NULL, *tail = NULL;
        while(!pq.empty()){
            ListNode* top = pq.top();pq.pop();
            if(!head){
                head = top;
            }
            else {
                tail->next = top;
            }
            tail = top;
            if(top->next){
                pq.push(top->next);
            }
        }
        return head;
    }
};