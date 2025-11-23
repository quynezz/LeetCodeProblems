class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        int even = 0;
        int odd = 1;
        for(int i = 0; i < nums.size(); i++){
             if(nums[i] % 2 == 0){  
                v[even] = nums[i];
                even += 2;
            }
            else {  
                v[odd] = nums[i];
                odd += 2;
            }
        } 
        return v;
    }
    // holy shiet run time =V
    // vector<int> sortArrayByParityII(vector<int>& nums) {
    //     vector<int> v;
    //     unordered_map<int,int> m;
    //     for(auto it : nums){
    //         m[it]++;
    //     }
    //     for(int i = 0; i < nums.size(); i++){    
    //         if(i == 0 || i % 2 == 0){ 
    //             for(auto it : nums){ 
    //                 if(it % 2 == 0 && m[it] > 0){
    //                     v.push_back(it); 
    //                     m[it]--;
    //                     break;
    //                 }
    //             }
    //         } 
    //         else if(i % 2 != 0){ 
    //              for(auto it : nums){ 
    //                 if(it % 2 != 0 && m[it] > 0){
    //                     v.push_back(it); 
    //                     m[it]--;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return v;
    // }
};