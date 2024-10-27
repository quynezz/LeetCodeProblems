class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 3x ms (but it fast for me)
    //     int n = nums.size();
    //     unordered_map<int,int> m;
    //     for(auto it : nums ){ 
    //         m[it]++;
    //     }
    //     int temp = 0;
    //     for(int i = 0; i <= n; i++){   
    //         if(m[i] < 1){
    //              temp = i;
    //         }
    //     }
    //     return temp;
    // }

    // 1ms (sum method)
    int sum = 0; 
    int temp = 0;
    for(int i = 0; i <= nums.size(); i++){  
        sum += i;
    }
    for(auto it : nums){  
        temp += it;
    }
    return sum = sum - temp;
    }
};