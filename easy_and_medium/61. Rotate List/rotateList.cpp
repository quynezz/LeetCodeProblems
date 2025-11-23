#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private: 
    int size(ListNode* head) { 
        int ans = 0;
        while (head != NULL) {
            ans++;
            head = head->next;
        }
        return ans;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) { 
        int n = size(head);
        k = k % n;
        if(k == 0 || head == NULL || head->next == NULL){
            return head; 
        }  
        ListNode* current = head;  
        for(int i = 0; i < n - k - 1; i++){
            current = current->next;
        }
        ListNode* newHead = current->next;
        current->next = NULL;
        ListNode* pre = newHead; 
        while(pre->next != NULL){
            pre = pre->next;
        }
        pre->next = head;  
        return newHead;
    }
};
