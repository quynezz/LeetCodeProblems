class Solution {


private:   
void backtrack(int i, string digits, unordered_map<char,string> map, string &temp,vector<string> &result){ 

if(i == digits.size()){  
    result.push_back(temp);
    return;
}
char digit =  digits[i];
string letter = map[digit];  

for(auto it : letter){  
    temp.push_back(it);
    backtrack(i + 1, digits, map, temp,result);  
    temp.pop_back();
}
} 
public:
    vector<string> letterCombinations(string digits) {   
        vector<string> result;
        string temp;
        if(digits.empty()){ 
            return {};
        }
        unordered_map<char, string> m{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
       backtrack(0,digits,m,temp,result);
    return result;
    }
};