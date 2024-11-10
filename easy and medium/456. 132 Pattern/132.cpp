class Solution {
public:
    bool find132pattern(vector<int>& nums) { 
        // nums[i] < nums[k] < nums[j];
        // find k 
        stack<int> st; 
        int k = INT_MIN; 
        for(int i = nums.size() - 1; i >= 0; i--){ 
            if(nums[i] < k){ 
                return true;
            }
            while(!st.empty() && nums[i] > st.top()){ 
                k = st.top(); 
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};