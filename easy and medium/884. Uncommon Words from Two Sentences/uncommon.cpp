class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) { 
        unordered_map<string,int> m;
        string s = s1 + " " + s2;
        stringstream ss(s);
        string word;
        vector<string> v;
        while(ss >> word){
            m[word]++;
        } 
      
        for(auto& [word, fre] : m){ 
            if(fre == 1){
                v.push_back(word);
            }
        }
        return v;
    }
};