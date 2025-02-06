class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> m; 
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                int temp = nums[i] * nums[j];
                m[temp]++;
            }
        }
        for(auto& [num,fre] : m){
            if(fre >= 2){
                count += (fre * (fre - 1)) / 2; 
            }
        }
        return count * 8;
    }
};