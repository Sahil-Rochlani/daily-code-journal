#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//recursive
 ListNode* recursive(ListNode* l1, ListNode* l2, int c = 0) {
        if(l1 || l2 || c){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + c;
            c = sum / 10;
            ListNode* ans = new ListNode(sum % 10);
            ans -> next = recursive(l1 ? l1->next : 0, l2 ? l2->next : 0, c);
            return ans;
        }
        return NULL;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursive(l1, l2);
    }