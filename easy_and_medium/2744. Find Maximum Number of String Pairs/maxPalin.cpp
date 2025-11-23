class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = i + 1; j < words.size(); j++){
                string temp1 = words[i];
  1              string temp2 = words[j];
                reverse(temp1.begin(),temp1.end());
                reverse(temp2.begin(),temp2.end());
                if(words[i] == words[j] || words[i] == temp2 || words[j] == temp1){
                    count++;
                } 
            }
        }
        return count;
    }
};