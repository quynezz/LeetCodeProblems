class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) { 
        int l = 1; 
        int r = 0;
        sort(nums.begin(),nums.end());
        for(auto it : nums){
            r = max(r,it);
        }  
        while(l < r){
            int mid = (l + r) / 2; 
            int count = 0;
            for(auto it : nums){
                if(it > mid){
                    count += (it - 1) / mid;
                    if(count > maxOperations){
                        l = mid + 1; 
                    }else{
                        r = mid;
                    }
                }
            }
        }
        return l;
    }
};