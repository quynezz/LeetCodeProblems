class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) { 
        int count = 0;
        for(auto it : words){
        bool can = true;
            for(auto ti : it){
                if(allowed.find(ti) == string::npos){
                    can = false;
                }
            }
            can == true ? count++ : count += 0;
        }
        return count;
    }
};