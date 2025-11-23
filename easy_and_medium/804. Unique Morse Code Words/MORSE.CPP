class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<string,int> m;
        for(auto it : words){
            string temp = "";
            for(auto ti : it){
                temp += morse[ti - 'a'];
            }
            m[temp]++;
        }
        int count = 0;
        for(auto& [morse, fre] : m){
            count++;
        }
        return count;   
    }
};