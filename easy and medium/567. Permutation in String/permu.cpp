class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for(int i = 0; i < s1.length(); i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        for(int i = s1.length(); i < s2.length(); i++) {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - s1.length()] - 'a']--;
            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};