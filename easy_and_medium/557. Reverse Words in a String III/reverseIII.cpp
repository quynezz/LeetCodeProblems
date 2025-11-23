    class Solution {
    public:
        string reverseWords(string s) {
            string temp = "";
            stringstream ss(s); 
            string word; 
            while(ss >> word){  
                reverse(word.begin(),word.end());  
                temp += word;  
                temp += " ";
            } 
            temp = temp.substr(0,temp.length() - 1);
            return temp;
        }
    };