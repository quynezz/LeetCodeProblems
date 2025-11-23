class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = 1; 
        int l = 0, r = 0;
        int sum = 1;
        unordered_map<char,int> m;
        while(r < s.size()){
            m[s[r]]++;
            while(m[s[r]] > 2){
                m[s[l]]--;
                l++;
            }
            sum = max(sum,r - l + 1);
            r++;
        }
        return sum;
    }
};