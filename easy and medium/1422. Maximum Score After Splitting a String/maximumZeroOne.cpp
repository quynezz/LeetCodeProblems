class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        vector<int> prefixOnes (s.size(),0);
        vector<int> prefixZeros(s.size(),0);
        // predefine first Zero element
        s[0] == '0' ? prefixZeros[0] = 1 : prefixZeros[0] = 0; 
        for(int i = 1; i < s.size(); i++){
            prefixZeros[i] = (s[i] == '0' ? 1 : 0) + prefixZeros[i - 1];
        }
        // predefine first One element
        s[s.size() - 1] == '1' ? prefixOnes[s.size() - 1] = 1 : prefixOnes[s.size() - 1] = 0; 
        for(int i = s.size() - 2; i >= 0; i--){
            prefixOnes[i] = (s[i] == '1' ? 1 : 0) + prefixOnes[i + 1];
        }
        for(int i = 0; i < s.size() - 1; i++){
            int n = prefixZeros[i];
            int m = prefixOnes[i + 1];
            score = max(score,(n + m));
        }
        return score;
    }
};