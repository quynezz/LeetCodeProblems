class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        unordered_map<string, vector<string>> m;  
        vector<vector<string>> res; 
        string temp = "";
        for(auto it : strs){
            temp = it;  
           sort(it.begin(),it.end()); 
            m[it].push_back(temp);
        }
        for(auto[word,vec] : m){  
            res.push_back(vec);
        }
       
        return res;
    }
};