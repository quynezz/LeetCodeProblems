class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> m; 
        unordered_set<string> s;
        string temp = "";
        string common = "";
        int most = INT_MIN;
        for(auto it : banned){
            s.insert(it);
        }   
        for(auto it : paragraph){
            if(!isalnum(it)){ 
                temp += ' ';
            }else{
                temp += it;
            }
        }  
        stringstream ss(temp);
        string word; 
        while(ss >> word){   
            string res = "";
            for(auto it : word){
                if(isalnum(it)){
                    res += tolower(it);
                }
            }
            if(s.find(res) == s.end()){
                m[res]++;
            }
        } 
        for(auto [word, fre] : m){
            if(fre > most){
                most = fre; 
                common = word;
            }
        }
        return common;
    }
};