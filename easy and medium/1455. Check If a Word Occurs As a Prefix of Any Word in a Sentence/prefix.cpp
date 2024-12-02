class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int temp = 0;
        int count = 0;
        while (ss >> word) {
            temp++;
            if (word.find(searchWord) != string::npos) {
                for (int i = 0; i < searchWord.size(); i++) { 
                    if(word[i] == searchWord[i]){
                        count++;
                    }else{ 
                        break;
                    }
                }
            }
            if(count == searchWord.size()){
                return temp;
            }
            count = 0;
        }
        return temp = (count == 0) ? -1 : temp;
    }
};