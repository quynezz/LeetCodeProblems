class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> v(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                v[i] = nums[i];
            }else if(nums[i] > 0){
                int count = nums[i];
                int index = i;
                while(count != 0){
                    index++;
                    count--;
                    if(index == nums.size()){
                        index = 0;
                    }       
                }
                v[i] = nums[index];
            }else if(nums[i] < 0){
                int count = abs(nums[i]);
                int index = i;
                while(count != 0){
                    index--;
                    count--;
                    if(index == -1){
                        index = nums.size() - 1;
                    }
                }
                v[i] = nums[index];
            }
        }
        return v;
    }
};