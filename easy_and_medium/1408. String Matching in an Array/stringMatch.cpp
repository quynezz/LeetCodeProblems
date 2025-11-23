class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> v;
        set<string> s;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i != j){
                    if(words[i].size() < words[j].size() && words[j].find(words[i]) != string::npos && !s.count(words[i])){
                        v.push_back(words[i]);
                        s.insert(words[i]);
                    }
                }
            }
        }
        return v;
    }
};