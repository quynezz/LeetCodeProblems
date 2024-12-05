class Solution {
public:
    bool canTransform(string start, string result) {
            vector<pair<char,int>> v1, v2; 
        for(int i = 0; i < start.length(); i++){
         if(start[i] != 'X'){
                v1.push_back({start[i],i});
            }
        }
        for(int i = 0; i < result.length(); i++){
            if(result[i] != 'X'){
                v2.push_back({result[i],i});
            }
        }  
        if(v1.size() != v2.size()) return false;
        for(int i = 0; i < v1.size(); i++){
            if(v1[i].first != v2[i].first){
                return false;
            }
            if(v1[i].first == 'L' && v1[i].second < v2[i].second){
                    return false;
            }
            if(v1[i].first == 'R' && v1[i].second > v2[i].second){ 
                 return false;
            }
        }
        return true;
    }
};