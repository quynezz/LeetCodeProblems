    class Solution {
    public:
        int maxDivScore(vector<int>& nums, vector<int>& divisors) {
            vector<pair<int,int>> v;    
            for(auto it : divisors){
                int count = 0;
                for(int i = 0; i < nums.size(); i++){
                    if(nums[i] % it == 0){
                        count++;
                    }
                }
                v.push_back({count,it});
            }
            int last = INT_MIN;
            int fin = INT_MAX;
            for(auto it : v){
                last = max(it.first,last);
            }
            for(auto it : v){
                if(it.first == last){
                    fin = min(it.second,fin);
                }
            }
            return fin;   
        }
    };