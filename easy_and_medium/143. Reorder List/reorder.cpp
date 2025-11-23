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
    void reorderList(ListNode* head) {
        ListNode* current = head;
        deque<ListNode*> dq;
        while(current != NULL){
            dq.push_back(current);
            current = current->next;
        }
        head = NULL;
        head = dq.front();
        dq.pop_front();
        // true = back, false = front;
        bool flip = true;
        while(!dq.empty()){
            if(flip){
                head->next = dq.back();
                head = head->next;
                dq.pop_back();
            }else{
                head->next = dq.front();
                head = head->next;
                dq.pop_front();
            }
            flip = !flip;
        }
        head->next = NULL;
    }
};