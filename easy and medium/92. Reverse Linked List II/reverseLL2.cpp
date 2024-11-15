class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) { 
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* temp = dummy;
        ListNode* current = head;
        ListNode* next;
        ListNode* prev = NULL;
        for(int i = 1; i < left; i++){ 
            temp = current;  
            current = current->next;
        }
        for(int i = 0; i < right - left + 1; i++){
            next = current->next; 
            current->next = prev;
            prev = current; 
            current = next; 
        }
        temp->next->next = next;
        temp->next = prev;
        return dummy->next;
    }
}