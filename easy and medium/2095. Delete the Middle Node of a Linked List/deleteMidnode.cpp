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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL || head == NULL){
            return NULL;
        }
        ListNode* f = head;
        ListNode* s = head;
        ListNode* pre = NULL; 
        while(f != NULL && f->next != NULL){  
            pre = s;
            s = s->next;
            f = f->next->next;
        }
        if(pre != NULL){
        pre->next = s->next;
        }
        delete s;
        return head;
    }
};