class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        auto check = [](string& s) -> bool { 
        string vowels = "aeiou";
            return (vowels.find(s[0]) != string::npos && vowels.find(s[s.size() -1]) != string::npos );
        };
        for(int i = left; i <= right; i++){
            if(check(words[i])) count++;
        }
        return count;
    }
};