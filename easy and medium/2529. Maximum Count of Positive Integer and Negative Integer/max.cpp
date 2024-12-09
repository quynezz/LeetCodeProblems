class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cP = 0; 
        int cN = 0;
        for(auto it : nums){
            if(it == 0){
                continue;
            }else{
            it > 0 ? cP++ : cN++;
            }
        }
        return max(cP,cN);
    }
};