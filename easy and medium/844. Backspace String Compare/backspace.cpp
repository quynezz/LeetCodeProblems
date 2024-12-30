class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1 = "";
        string temp2 = "";
        for(auto it : s){
            if(it != '#'){
                temp1 += it;
            }else{
                if(!temp1.empty())temp1.pop_back();
            }
        }
         for(auto it : t){
            if(it != '#'){
                temp2 += it;
            }else{
                if(!temp2.empty())temp2.pop_back();
            }
        }
        cout << temp1 << " " << temp2 << endl;
        return temp1 == temp2;
    }
};