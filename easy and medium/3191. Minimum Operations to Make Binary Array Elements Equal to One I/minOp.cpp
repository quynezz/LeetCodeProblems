class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int count = 0;
            for(int i = 0; i < nums.size() - 2; i++){
                if(nums[i] == 0){
                cout << i << " ";
                count++;
                nums[i]  == 0 ? nums[i] = 1 : nums[i] = 0;
                nums[i + 1]  == 0 ? nums[i + 1] = 1 : nums[i + 1] = 0;
                nums[i + 2]  == 0 ? nums[i + 2] = 1 : nums[i + 2] = 0;
                }
          }
          for(auto it : nums) if(it == 0) return -1;
          return count; 
        }
    };
    
    
    
    