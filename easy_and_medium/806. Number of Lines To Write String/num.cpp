class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        unordered_map<int,int> m;
        vector<int> ans;
        char temp = 'a';
        for(auto it : widths){
            m[temp] = it;
            temp += 1;
        }
        vector<pair<int,int>> v;
        int i = 0;
        int j = 1;
        int num = 0;
        while(i < s.size()){
            if(num + m[s[i]] > 100){
             v.push_back({j,num});
            j++;
            num = 0;   
            }else{
                num += m[s[i]];
                i++;
            }
        }
        v.push_back({j,num});
        for(auto it : v){
            ans.push_back(it.first);
            ans.push_back(it.second);
        }
        return {ans[ans.size() - 2],ans[ans.size()-1]};
    }
};