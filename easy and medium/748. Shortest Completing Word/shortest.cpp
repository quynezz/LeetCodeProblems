class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> m1; 
        vector<tuple<int,string,int>> ans;
        for(auto it : licensePlate){
            if(isalpha(it) && it != ' ') {
                m1[tolower(it)]++;
            }
        }
        for(int i = 0; i < words.size(); i++){
            unordered_map<char,int> m;
            string temp = words[i];
            bool found = true;
            for(int j = 0; j < temp.size(); j++){
                m[tolower(temp[j])]++;
            }
            for(auto& [charac, fre] : m1){
                if(m[charac] < m1[charac]){
                    found = false;
                    break;
                }
            }
            if(found == true){
                ans.push_back({temp.size(),temp,i});
            }
        }
        int indexMin = INT_MAX;
        int lengthMin = INT_MAX;
        for(auto& [length, word, index] : ans){
            lengthMin = min(length,lengthMin);
        }
        for(auto& [length, word, index] : ans){
            if(length == lengthMin){
                indexMin = min(indexMin,index);
            }
        }
        if(ans.size() == 1){
            auto [length, word, index] = ans[0];
            indexMin = index;
        }
        return words[indexMin];
    }
};