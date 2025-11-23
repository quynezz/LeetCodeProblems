class Solution {
public:
    int removeDuplicates(vector<int>& nums) { 
        unordered_map<int,int> m;  
        for(auto it : nums){
            m[it]++; 
        } 
        nums.clear();
        for(auto [num,fre] : m){ 
            if(fre >= 2){
                nums.push_back(num);
                nums.push_back(num);
            }else{
                nums.push_back(num);
            }
        }
        sort(nums.begin(),nums.end());
        return nums.size();
    }
};