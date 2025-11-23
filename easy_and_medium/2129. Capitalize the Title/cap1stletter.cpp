class Solution {
public:
    string capitalizeTitle(string title) { 
        string temp = "";
        stringstream ss(title);  
        string word; 
        while(ss >> word){
            if(word.length() > 2){
                temp += toupper(word[0]); 
                for(int i = 1; i < word.length(); i++){  
                    temp += tolower(word[i]);
                } 
            }
            if(word.length() == 1 || word.length() == 2 ){ 
                for(int i = 0; i <= word.length() - 1; i++){ 
                temp += tolower(word[i]);
                }
            }
            temp += ' ';
        } 
        temp.pop_back();
        return temp;

    }
};