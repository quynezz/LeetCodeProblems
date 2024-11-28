class Solution {
public:
    char kthCharacter(int k) { 
        string character = "a";
        while(character.size() <= k){    
            string temp = "";
            for(auto it : character){
                if(it == 'z'){
                    it = 'a';
                } 
                int n = (int)it + 1;
                temp += char(n); 
            } 
            character += temp;
        } 
        return character[k - 1];
    }
};