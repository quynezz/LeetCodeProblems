class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) { 
        unordered_map<int,string> m;
        vector<int> v; 
        vector<string> res; 
        for(auto it : score){  
            v.push_back(it);
        }
        sort(v.begin(),v.end(),greater<int>()); 
        for(int i = 0; i < v.size(); i++){ 
            if(i == 0){ 
                m[v[i]] = "Gold Medal";
            } else if(i == 1){ 
                m[v[i]] = "Silver Medal";
            } else if(i == 2){ 
                m[v[i]] = "Bronze Medal";
            }else{ 
                m[v[i]] = to_string(i + 1);
            }
        } 
        for(auto it : score){ 
            res.push_back(m[it]);
        }
        return res;
    }
};