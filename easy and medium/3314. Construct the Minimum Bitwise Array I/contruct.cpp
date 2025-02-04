class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            int ans = -1;
            for(int j = 0; j < nums[i]; j++){
                int temp = j | (j + 1);
                if(temp == cur){
                    ans = j;
                    break;
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};

