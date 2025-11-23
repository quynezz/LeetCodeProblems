class Solution {
public:
    bool isCircularSentence(string sentence) { 
        int one = 0; 
        char last = ' ';
        if(sentence.length() <= 1){
            return true;
        }
        if(sentence.find(' ') == string::npos){ 
            one = 1;
        } 
        if(one == 1){ 
            int i = 0; 
            int j = sentence.length() - 1;
            if(sentence[i] != sentence[j]){ 
                return false;
            }
        }else if(one == 0){  
            if(sentence[0] != sentence[sentence.length() - 1]){
                return false;
            }  
            int i = 0; 
            while(i < sentence.length()){ 
                if(sentence[i] == ' '){ 
                    last = sentence[i - 1];
                    i++;
                    if(sentence[i] != last){ 
                        return false;
                    }
                }
                i++;
            }
        }
        return true;
    }
};