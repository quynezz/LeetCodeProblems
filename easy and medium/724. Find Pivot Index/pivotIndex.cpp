class Solution {
public:
    int pivotIndex(vector<int>& nums) {     
        int lsum = 0, total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(lsum == total - lsum - nums[i]){
                return i;
            }
            lsum += nums[i];
        } 
        return -1;
        
        // int l = 0; 
        // int r = nums.size() - 1;  
        // while(l < nums.size()){
        // int suml = 0; 
        // int sumr = 0;
        //     for(int i = 0; i < l;i++){
        //         suml += nums[i]; 
        //     }  
        //     for(int j = r; j > l; j--){
        //         sumr += nums[j];
        //     }
        //     if(suml == sumr){
        //         return l;
        //     }
        //     l++; 
        // }
        // return -1;
        }
};