class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {    
            vector<int> prefix(nums.size() + 1,0);
            for(int i = 0; i < queries.size(); i++){
                int first = queries[i][0]; 
                int second = queries[i][1];
                prefix[first]++;
                prefix[second + 1]--;
            }
            for(int i = 1; i < prefix.size(); i++){
                prefix[i] = prefix[i - 1] + prefix[i];
            }
            prefix.pop_back();
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] > prefix[i]) return false;
            }
            
            return true;
        }
    };