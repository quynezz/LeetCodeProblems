class Solution {
public:
    int findClosestNumber(vector<int>& nums) {  
        int num = INT_MIN;
        int closet = INT_MAX;
        bool visited[1001];
        for(auto it : nums){ 
            if(abs(it) - 0 < closet){ 
                closet = abs(it);
            }
        }
        for(auto it : nums){
            if(abs(it) - 0 == closet){
                num = max(it,num);
            }
        }
        return num;
    }
};