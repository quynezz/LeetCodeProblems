class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<char, int> m;
        int start = 0;  
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] > 0) {
                start = max(start, m[s[i]]);
            }
            m[s[i]] = i + 1;  
            longest = max(longest, i - start + 1);
        }
        
        return longest;
    }
};


