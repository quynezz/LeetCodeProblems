class Solution {
    public:
        int maximumCount(vector<int>& nums) {
          int nega = 0, posi = 0; 
          for(auto it : nums) {
            if(it > 0){
                posi++;
            }else if(it < 0){
                nega++;
            }
          }        
          return max(nega,posi);
        }
    };