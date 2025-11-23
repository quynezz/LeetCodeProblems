class Solution {
public:
    bool detectCapitalUse(string word) {
        string temp = ""; 
        string temp2 = "";
        string temp3 = "";

        for(int i = 0; i < word.length(); i++){ 
            temp += toupper(word[i]);
            temp2 += tolower(word[i]);
            if(i == 0){
                temp3 += toupper(word[0]);
            }else {
                temp3 += tolower(word[i]);
            } 
        }
        if(temp == word ||temp2 == word || temp3 == word){  
            return true;
        } 
        return false;
    }
};