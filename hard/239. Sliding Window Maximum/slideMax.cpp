class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k <= 0 || nums.size() < k) {
            return {};
        }

        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            result.push_back(nums[dq.front()]);
        }
        return result;
    }
};