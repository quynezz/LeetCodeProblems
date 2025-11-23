class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        auto check = [&](string s1, string s2) -> bool{ 
            if(s1.length() > s2.length()) return false;
            string temp1 = s2.substr(0,s1.length());
            string temp2 = s2.substr(s2.length() - s1.length());
            return s1 == temp1 && s1 == temp2;
        };
        int count = 0;
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = i + 1; j < words.size(); j++){
                if(check(words[i],words[j])) count++;
            }
        }
        return count;
    }
};