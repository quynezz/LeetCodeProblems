class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxLength = 0;
        for(auto it : sentences){
            stringstream ss(it); 
            string word; 
            int count = 0;
            while(ss >> word){
                count++;
            }
            maxLength = max(count,maxLength);
        }
        return maxLength;
    }
};