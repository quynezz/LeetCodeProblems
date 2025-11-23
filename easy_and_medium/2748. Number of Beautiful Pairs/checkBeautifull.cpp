class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int first_digit = to_string(nums[i])[0] - '0';
                int last_digit = to_string(nums[j]).back() - '0';
                if(gcd(first_digit, last_digit) == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
