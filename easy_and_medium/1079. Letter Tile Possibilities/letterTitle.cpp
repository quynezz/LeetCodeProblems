class Solution {
    public:
        int numTilePossibilities(string tiles) {
            unordered_map<char,int> m; 
            for(auto it : tiles) m[it]++;
            int ans = 0;
            string temp = "";
            set<string> s;
            backtrack(m,temp,tiles,ans,s);
            return ans;
        }
    private: 
        void backtrack(unordered_map<char,int>& m, string& ans, string& tit,int& count,set<string>& s){
            // base case: 
            if(ans.size() != 0 && s.find(ans) == s.end()){
                count++;
            }
            if(s.find(ans) != s.end()){
                return;
            }
        for(auto& [num,fre] : m){
                if(m[num] != 0){
                    ans += num;
                    m[num]--;
                    backtrack(m,ans,tit,count,s);
                    m[num]++;
                    ans.pop_back();
                }
            }
    
    
    
    
    
    
        }   
    };