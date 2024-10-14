#include<bits/stdc++.h> 
 
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<long long, int> check;
        int n = nums.size(); 
        for(int i = 0; i < n; i++){ 
            if(nums[i]){   
                check[nums[i]]++;
            }
        }    
        for(auto it : nums){  
            if(check[it] == 1){  
                return it;
            }
        }
        return 0;
    }
};