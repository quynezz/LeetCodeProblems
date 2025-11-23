class Solution {
private:
    // Function to append a value to the linked list
    void pushback(ListNode*& head, ListNode*& tail, int val) {  
        ListNode* newNode = new ListNode(val);
        
        if (head == NULL) { 
            head = newNode;  // Set head if it's empty
            tail = head;  // Tail will be the head if it's the first node
        } else {
            tail->next = newNode; 
            tail = newNode;  
        }
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        vector<int> v;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        ListNode* res = NULL;
        ListNode* tail = NULL;
        for (int val : v) {
            pushback(res, tail, val);
        }

        return res;
    }
};
