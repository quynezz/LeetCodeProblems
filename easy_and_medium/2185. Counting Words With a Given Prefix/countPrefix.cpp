class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            string temp = words[i].substr(0,pref.size());
            temp == pref ? count++ : count += 0;
        }
        return count;
    }
};