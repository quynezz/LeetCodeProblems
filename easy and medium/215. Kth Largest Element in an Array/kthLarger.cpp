class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int> pq;
        for(auto it : nums){
            pq.push(it);
        }
        while(!pq.empty() && k > 1){
            k--;  
            pq.pop();
        }
        return pq.top();
    }
};