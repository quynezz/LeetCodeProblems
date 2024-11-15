/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */;
class Solution {
private:  
    void reverseLL(ListNode *&head){   
        ListNode *prev = NULL; 
        ListNode *cur = head;  
        ListNode *next;
        while (cur != NULL) {   
            next = cur->next;   
            cur->next = prev;  
            prev = cur;        
            cur = next;        
        }    
        head = prev;  
    }

    ListNode* add(ListNode *l1, ListNode *l2){ 
        ListNode *current = new ListNode(0); 
        ListNode *temp = current;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry > 0) {  
            int sum = carry;  
            if (l1 != NULL) {  
                sum += l1->val; 
                l1 = l1->next;
            }
            if (l2 != NULL) { 
                sum += l2->val; 
                l2 = l2->next;
            } 
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return current->next;  
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        ListNode *result = add(l1, l2); 
        reverseLL(l1);
        return result;     
    }
    
};
