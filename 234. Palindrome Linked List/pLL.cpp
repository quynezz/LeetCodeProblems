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
    ListNode* reverse(ListNode* head) { 
        ListNode* current = head; 
        ListNode* pre = NULL; 
        ListNode* next; 
        while (current != NULL) {  
            next = current->next; 
            current->next = pre;
            pre = current; 
            current = next; 
        }
        return pre; 
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) { 
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        } 
        // 1 2 2 1 
        // second half : 2 1 
        // reversed it : 1 2 and check with 1 2 2 1
        ListNode* reversedSecondHalf = reverse(slow);
        ListNode* originalHead = head;

        while (reversedSecondHalf != nullptr) {
            if (originalHead->val != reversedSecondHalf->val) {
                return false;
            }
            originalHead = originalHead->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }

        return true; 
    }
};
