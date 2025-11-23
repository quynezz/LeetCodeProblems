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
void pb(ListNode*& head, int val){
    if(head == NULL){
        head = new ListNode(val);
    }else{
    ListNode* temp = head;
    while(temp->next != NULL){ 
        temp = temp->next;
    } 
    temp->next = new ListNode(val);
    }
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        int sum = 0; 
        int carry = 0; 
        int i = 0;
        vector<int> v1,v2,v3;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = NULL;
        while(temp1 != NULL){    
            v1.push_back(temp1->val);
            temp1 = temp1->next;
        } 
        while(temp2!= NULL){    
            v2.push_back(temp2->val);
            temp2 = temp2->next;
        } 
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        // 3 - 4 - 2 -7 
        // 4 - 6 - 5 
        while(i < v1.size() || i < v2.size() || carry){  
            int sum = (i < v1.size() ? v1[i] : 0) + (i < v2.size() ? v2[i] : 0) + carry; 
            v3.push_back(sum % 10);
            carry = sum / 10;
            i++;
        } 
        reverse(v3.begin(),v3.end());
        for(auto it : v3){ 
            pb(head,it);
        }
        return head;
    }
};