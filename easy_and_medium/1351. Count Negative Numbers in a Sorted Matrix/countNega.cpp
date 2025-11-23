class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto it : grid){
            for(auto ti : it){
                if(ti < 0){
                    count++;
                }
            }
        }
        return count;
    }
};