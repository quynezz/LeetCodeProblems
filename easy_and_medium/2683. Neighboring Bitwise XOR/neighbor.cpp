class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> v(derived.size(),0); 
        for(int i = 0; i < derived.size(); i++){
            if(i < derived.size() - 1){
                if(derived[i] == 1){
                    v[i] == 0 ? v[i + 1] = 1 : v[i + 1] = 0;
                }else{
                    v[i] == 0  ? v[i + 1] = 0 : v[i + 1] = 1;
                }
            }else if(i == derived.size() - 1){
                if(derived[i] == 1){
                    if(v[0] != v[derived.size() - 1]) return true;
                    else return false;
                }else if(derived[i] == 0){
                    if(v[0] == v[derived.size() - 1]) return true;
                    else return false;
                }
            }
        }
        return false;
    }
};