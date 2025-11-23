class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int cur_min = 0; 
            int cur_max = 0;
            for(auto it : nums){
                cur_min = min(cur_min + it,0);
                cur_max = max(cur_max + it,0);
            }
            cout << cur_min << " " << cur_max << endl;
            return cur_max - cur_min;
        }
    };