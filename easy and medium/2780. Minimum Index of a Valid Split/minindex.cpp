class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            if(nums.size() == 1) return -1;
            unordered_map<int,int> m;
            int most = 0;
            int domi = 0;
            for(auto it : nums) m[it]++;
            for(auto [first, second] : m){
                if(second > most){
                    most = second; 
                    domi = first;
                }
            }
    
            int current = 0;
            vector<int> v;
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != domi){
                    v.push_back(nums[i]);
                }else{
                    count++;
                }
                if(count > v.size()){
                    current = i;
                    break;
                }
            }
            if(current == nums.size() - 1) return -1;
            count = 0;
            v.clear();
            for(int i = current + 1; i < nums.size(); i++){
                if(nums[i] != domi){
                    v.push_back(nums[i]);
                }else{
                    count++;
                }
            }
            if(count <= v.size()){
                return -1;
            }
            return current;
        }
    };