class Solution {
private:  
    int size(ListNode *head) {  
        int ans = 0;
        while (head != NULL) {  
            head = head->next;
            ans++; 
        }
        return ans;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
        int k = size(head); 
        if (k == 1 && n == 1) {  
            delete head; 
            return NULL; 
        } 
        if (n == k) {
            ListNode* newHead = head->next; 
            delete head;
            return newHead;
        } 
        ListNode* temp = head; 
        ListNode* prev = head;  
        for (int i = 1; i < (k - n) + 1; i++) {   
            prev = temp; 
            temp = temp->next;
        }
            prev->next = temp->next; 
            delete temp; 
        return head; 
    }
};