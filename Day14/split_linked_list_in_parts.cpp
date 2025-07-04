#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int length(ListNode* head){
    int l = 0;
    ListNode* temp = head;
    while(temp){
        l++;
        temp = temp->next;
    }
    return l;
}
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ans;
    int len = length(head);
    int partsize = len / k ? len / k : 1;
    int extra = len / k ? len % k : 0;
    ListNode* temp = head;
    while(k > 0){
        if(temp){
            ListNode* start = temp;
            ListNode* end = start;
            int l = partsize;
            while(end && l - 1){
                end = end->next;
                l--;
            }
            if(extra){
                end = end->next;
                extra--;
            }
            temp = end->next;
            end->next = NULL;
            ans.push_back(start);

        }
        else ans.push_back(NULL);
        k--;
    }
    return ans;
}