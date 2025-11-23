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
int size(ListNode* head){
    int count = 0; 
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}
public:
    int pairSum(ListNode* head) {
        int sum = 0;
        if(size(head) == 2){
            sum += head->val;
            sum += head->next->val;
            return sum;
        }
        vector<int> v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i < v.size(); i++){
            int temp1 = v[i];
            int temp2 = v.size() - 1 - i;
            sum = max(sum, temp1 + temp2);
        }
        return sum;
    }
};