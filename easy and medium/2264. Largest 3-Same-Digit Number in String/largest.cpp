class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> v;
        string res = "";
        for(int i = 0; i <= num.size() - 3; i++){
            char temp = num[i];
            bool ok = true;
            for(int j = i; j < i + 3; j++){
                if(num[j] != temp){
                    ok = false;
                }
            }
            if(ok == true){
                v.push_back(num.substr(i,3));
            }
        }
        for(auto it : v){
            res = max(it,res);
        }
    return res;
    }
};