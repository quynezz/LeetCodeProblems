class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> m;
        int ele = INT_MIN;
        bool find = false;
        for(auto it : nums) {
            ele = max(ele,it);
            m[it]++;
        }
        for(int i = 1; i <= ele; i++){
            if(m.find(i) == m.end()) return false;
            else if(i != ele && m[i] != 1) return false;
            else if (i == ele){
                if(m[i] == 2){
                    find = true;
                }
            }
        }
        return find;
    }
};