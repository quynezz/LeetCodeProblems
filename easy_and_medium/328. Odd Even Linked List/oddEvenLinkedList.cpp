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

    void push_back(ListNode*& head, int val) {
        ListNode* temp = head;
        if (!temp) {
            head = new ListNode(val); 
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        ListNode* cur = new ListNode(val);
        temp->next = cur;
    }
    int size(ListNode* head) {
        int ans = 0;
        while (head != NULL) {
            head = head->next;
            ans++;
        }
        return ans;
    }

public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; 
        }
        
        int n = size(head);
        vector<int> v;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = (temp->next != NULL) ? temp->next->next : nullptr;
        }
        ListNode* cur = head->next;
        while (cur != NULL) {
            v.push_back(cur->val);
            cur = (cur->next != NULL) ? cur->next->next : nullptr;
        }
        ListNode* newHead = nullptr; 
        for (auto it : v) {
            push_back(newHead, it);
        }
        
        return newHead; 
    }
};









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
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) { 
//         if(head == NULL || head->next == NULL){
//             return NULL;
//         }
//         ListNode* odd = head;
//         ListNode* even = head->next;
//         ListNode* newHead = even;
//         while(even != NULL && even->next != NULL){
//             odd->next = odd->next->next;
//             odd = odd->next;
//             even->next = even->next->next;
//             even = even->next;
//         }
//         odd->next = newHead;
//         return head;
//     }
// };