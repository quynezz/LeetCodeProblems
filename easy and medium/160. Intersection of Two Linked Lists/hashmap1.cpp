/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { 
        unordered_map<ListNode*,int> hashmap;
        while(headA != NULL){  
            hashmap[headA]++;
            headA = headA->next;
        }
        while(headB != NULL){ 
            if(hashmap[headB] > 0){ 
                return headB;
            } else { 
                headB = headB->next;
            }
        }
            return NULL;
    }
};