class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        int ans = 0;
        int temp = 0;
        unordered_map<int,int> m;
        for(auto it : nums){   
            m[it]++;
            if(m[it] > ans){ 
            ans = m[it];
            temp = it;
            }
        }
        return temp;;
    }
};