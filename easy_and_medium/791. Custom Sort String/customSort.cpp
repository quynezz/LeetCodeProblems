class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(auto it : s){
            m[it]++;
        }
        string temp = "";
        for(auto it : order){
            while(m[it] > 0){
                temp += it;
                m[it]--;
            }
        }
        for(auto& [word, fre] : m){
            while(fre != 0){
                temp += word;
                fre--;
            }
        }
        return temp;
    }
};