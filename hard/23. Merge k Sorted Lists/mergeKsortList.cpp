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
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        priority_queue<int, vector<int>, greater<int>> pq; 
        ListNode* prev = NULL;
        ListNode* head = NULL;
        for(int i = 0 ; i < lists.size(); i++){
            ListNode* temp = lists[i]; 
            while(temp != NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        while(!pq.empty()){
                int n = pq.top();
                pq.pop();
                ListNode* current = new ListNode(n);
            if(head == NULL){ 
                head = current;
            }else{  
                prev->next = current; 
            }
            prev = current;
        }
        return head;
    }
};