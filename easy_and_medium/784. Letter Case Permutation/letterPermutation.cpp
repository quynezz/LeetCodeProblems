class Solution {
private: 
void back(vector<string> &ans,string &s,string &temp,int index){ 
    if(temp.length() == s.length()){ 
        ans.push_back(temp);
        return;
    }  
    if(isdigit(s[index])){
        temp.push_back(s[index]);
        back(ans,s,temp,index + 1);
        temp.pop_back();
    }else { 
        temp.push_back(toupper(s[index]));
        back(ans,s,temp,index  + 1); 
        temp.pop_back();

        temp.push_back(tolower(s[index]));
        back(ans,s,temp,index  + 1); 
        temp.pop_back();

    }
}
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans; 
        string temp = "";
        back(ans,s,temp,0);
        return ans;
    }
};