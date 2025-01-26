class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0;
        int temp = 0;
        for(int i = 0 ; i < nums.size() - 1; i++){
            temp += nums[i];
            int temp2 = 0;
            for(int j = i + 1; j < nums.size(); j++){
                temp2 += nums[j];
            }
            abs(temp - temp2) % 2 == 0 ? count++ : count += 0; 
        }
        return count;
    }
};