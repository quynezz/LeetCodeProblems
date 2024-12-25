class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> v;
        for(auto it : logs){
            if(it != "../" && it != "x/" && it != "./"){
                v.push_back(it);
            }else if(it == "../"){
                if(v.empty()){
                    continue;
                }else{
                    v.pop_back();
                }
            }else if(it == "./"){
                continue;
            }
        }
        return v.empty() ? 0 : v.size();
    }
};