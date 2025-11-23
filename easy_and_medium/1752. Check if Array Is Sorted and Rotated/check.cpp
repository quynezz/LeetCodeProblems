class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> temp = nums; 
        vector<int> tempM;
        sort(temp.begin(),temp.end());
        int mark = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[0] == temp[(0 + i) % nums.size()]){
                tempM.push_back(i);
            }
        }
        if(tempM.size() == 0) return false;
        for(int mark = 0; mark < tempM.size(); mark++){
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == temp[(i + tempM[mark]) % nums.size()]){
                    count++;
                }
            }
            if(count == nums.size()) return true;
        }    
        return false;
    }
};

