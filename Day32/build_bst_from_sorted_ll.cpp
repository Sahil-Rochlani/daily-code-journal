#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//approach 1: same as array by travelling to mid breaking list into left and right and building left and right
//subtrees by passing those list recursively

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ListNode* midNode(ListNode* head){
        if(!head)return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevslow = NULL;
        while(fast && fast->next){
            prevslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prevslow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return new TreeNode(head->val);
        ListNode* midprev = midNode(head);
        ListNode* mid = midprev ? midprev->next : head;
        ListNode* midnext = mid->next;
        if(midprev)midprev->next = NULL;
        mid->next = NULL;
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(mid == head ? NULL : head);
        root->right = sortedListToBST(midnext);
        return root;
    }

//approach 2: 

int getLength(ListNode* head){
        if(!head)return 0;
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    TreeNode* solve(ListNode* &head, int n){
        if(!head)return NULL;
        if(n <= 0)return NULL;

        //LNR

        //l
        TreeNode* left = solve(head, n / 2);

        //n
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        root->left = left;

        //r
        root->right = solve(head, n - n / 2 - 1);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLength(head);
        return solve(head, len);
    }