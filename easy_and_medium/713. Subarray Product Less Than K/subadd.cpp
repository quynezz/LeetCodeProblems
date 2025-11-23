class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int res = 1;
        deque<int> q;
        if(k <= 0) return count;
        for(auto it : nums){
            res *= it;
            q.push_back(it);
            while(res >= k && !q.empty()){
                res /= q.front();
                q.pop_front();
            }
            count += q.size();
        }
        return count;
    }
};