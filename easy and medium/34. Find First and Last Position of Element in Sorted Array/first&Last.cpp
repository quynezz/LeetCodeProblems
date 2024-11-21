class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        int l = 0; 
        int r = nums.size() - 1;
        vector<int> v{-1,-1};
        
        // find most left
        
        while(l <= r){
            int mid = (l + r) / 2; 
            if(nums[mid] == target){ 
                v[0] = mid;
                r = mid - 1;
            }else if (nums[mid] > target){
                r = mid - 1;
            }else{ 
                l = mid + 1;
            }
        }
        l = 0; 
        r = nums.size() - 1; 

        // find most right

        while(l <= r){
            int mid = (l + r) / 2; 
            if(nums[mid] == target){
                v[1] = mid; 
                l = mid + 1;
            }else if (nums[mid] > target){ 
                r = mid - 1; 
            }else{ 
                l = mid + 1;
            }
        }
        return v;
    }
};