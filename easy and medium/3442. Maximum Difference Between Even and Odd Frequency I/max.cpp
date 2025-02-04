class Solution {
public:
    int maxDifference(string s) {
        int res = INT_MIN;
        unordered_map<int,int> m;
        for(auto it : s) m[it]++;
        vector<int> odd,even;
        for(auto&[num,fre] : m) {
            if(fre % 2 == 0){
                even.push_back(num);
            }else if(fre % 2 != 0){
                odd.push_back(num);
            }
        }
        for(int i = 0; i < odd.size(); i++){
            for(int j = 0; j < even.size(); j++){
                res = max(res,m[odd[i]] - m[even[j]]);
            }
        }
        return res;
    }
};