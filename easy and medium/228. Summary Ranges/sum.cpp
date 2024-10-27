class Solution {
private:  
void pushRange(int numsStart, int numsEnd,vector<string> &res){  
    if(numsStart != numsEnd){   
        res.push_back(to_string(numsStart) + "->" + to_string(numsEnd));
    } else { 
        res.push_back(to_string(numsStart));
    }
}
public:
    vector<string> summaryRanges(vector<int>& nums) { 
        vector<string> res;
        if(nums.size() == 0){
             return res;
        }
        int start = nums[0]; 
        int end = nums[0];
        for(int i = 1; i < nums.size(); i++){  
            if(nums[i] == 1 + nums[i - 1]){ 
                end = nums[i];
            } else { 
                pushRange(start,end,res);
                start = nums[i]; 
                end = nums[i]; 
            }
        }
        pushRange(start,end,res);
        return res;
    }
};