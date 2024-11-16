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
    ListNode* swapNodes(ListNode* head, int k) { 
        ListNode* firstNode = head;
        ListNode* secondNode = head;
        ListNode* current = head;
        int j = 1;
        for(int i = 1; i < k; i++){
            firstNode = firstNode->next;
        }   
        while(current->next != NULL){
            current = current->next;
            j++;
        }
        j = j - k + 1;
        for(int i = 1; i < j; i++){ 
            secondNode = secondNode->next;
        }
        swap(firstNode->val,secondNode->val);

        return head;

    }
};