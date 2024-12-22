class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> m;
        unordered_map<int,int> mT;
        vector<int> v;
        int count = 0;
        int cc = 0;
        for(auto it : nums){
            if(mT.find(it) == mT.end()){
                cc++;
            }
            mT[it]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                count++;
                m[nums[i]]++;
            }
            mT[nums[i]]--;
            if(mT[nums[i]] == 0){
                mT.erase(nums[i]);
                cc--;
            }
            v.push_back(count - cc);
        }
        return v;
    }
};