class Solution {
public:
    string toGoatLatin(string sentence) {
        int i = 1;
        string res = "";
        stringstream ss(sentence); 
        string word; 
        while(ss >> word){
            bool vowel = false;
            string temp = "";
            if(word[0] == 'a' || word[0] == 'A' || word[0] == 'e' || word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || word[0] == 'o'|| word[0] == 'O' || word[0] == 'u' || word[0] == 'U'){
                vowel = true;
            }
            if(vowel == true){
                temp += word[0];
            }
            for(int i = 1; i < word.size(); i++){
                temp += word[i];
            }
            if(vowel == false){
                temp += word[0];
            }
            temp += "ma";
            int n = i; 
            while(n != 0){
                temp += 'a';
                n--;
            } 
            i++;
            res += temp;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};