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
public:
    
    ListNode* swapPairs(ListNode* head) {
        ListNode *current = head;
        ListNode *pre = head;
        if(head == NULL){ 
            return NULL;
        }
        if(head->next == NULL){ 
            return head;
        }
        while(current != NULL && current->next != NULL){
            current = current->next;
            swap(current->val,pre->val);
            swap(current,pre);
            pre = pre->next;
            current = pre;
        }
        return head;
    }
};