class Solution {
public:
    int maxPower(string s) {
        int count = 1;
        int ans = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]) count++;
            else ans = max(count,ans), count = 1;
        }
        if(count > 1) ans = max(count,ans);
        return ans;
    }
};