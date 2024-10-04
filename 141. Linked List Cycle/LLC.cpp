#include<bits/stdc++.h> 

using namespace std; 

// Uncomment to run this
// Using Floyd's Cycle Detection Algorithm
 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next ? fast->next->next : nullptr;
        }

        return false;

    }
};

