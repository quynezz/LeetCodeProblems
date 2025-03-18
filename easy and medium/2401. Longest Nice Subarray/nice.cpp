class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int l = 0, r = 0;
            int cur = 0;
            int longest = 0;
    
            while (r < nums.size()) {
                while (l < r && (cur & nums[r]) != 0) {
                    cur ^= nums[l]; 
                    l++;
                }
                cur |= nums[r];
                longest = max(longest, r - l + 1);
                r++;
            }
            return longest;
        }
    };
    