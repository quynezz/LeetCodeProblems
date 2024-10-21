class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // thrid test case [7, 7, 7, 7]
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        // first test case [1, 2, "6", 3, 4, 5, "6"]
        ListNode* temp = head;
        ListNode* pre = NULL;

        while (temp != NULL) {
            if (temp->val == val) {
                pre->next = temp->next;
                delete temp;
                temp = pre->next;  
            } else {
                pre = temp;        
                temp = temp->next; 
            }
        }
        
        return head;
    }
};
