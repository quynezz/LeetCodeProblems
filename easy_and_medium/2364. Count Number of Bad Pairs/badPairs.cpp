class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long n = nums.size();
            long long total = (n * (n - 1))/2;
            unordered_map<int,int> goodPair;
            long long count = 0; 
            for(int i = 0; i < nums.size(); i++){
                count += goodPair[nums[i] - i];
                goodPair[nums[i] - i]++;
            }
            return total - count;
        }
    };