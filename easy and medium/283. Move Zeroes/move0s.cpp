class Solution {
public:
    void moveZeroes(vector<int>& nums) {   
        vector<int> v; 
        for(auto it : nums){ 
            if(it != 0){ 
                v.push_back(it);
            }
        }
        for(auto it1 : nums){ 
            if(it1 == 0){ 
                v.push_back(it1);
            }
        } 
        for(int i = 0; i < v.size(); i++){ 
            nums[i] = v[i];
        }
    }
};