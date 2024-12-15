class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // find max fre 
        int m = INT_MIN; 
        int sum = INT_MAX;
        unordered_map<int,int> m1; 
        unordered_map<int,pair<int,int>> m2;
        for(int i = 0; i < nums.size(); i++){
            m1[nums[i]]++;
            if(m2.find(nums[i]) == m2.end()){
                m2[nums[i]] = {i,i};
            }else{
                m2[nums[i]].second = i;
            }
        }
        for(auto& [num,fre] : m1){
            m = max(fre,m);
        }
        for(auto& [num,fre] : m1){
            if(fre == m){
                int temp = m2[num].second - m2[num].first + 1;
                sum = min(temp,sum);
            }
        }
        return sum;
    }
};