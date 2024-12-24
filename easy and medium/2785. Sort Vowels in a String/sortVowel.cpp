class Solution {
public:
    string sortVowels(string s) {
        string vow = "aeiouAEIOU";
        vector<char> v;
        for(int i = 0; i < s.size(); i++){
            if(vow.find(s[i]) != string::npos){
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end(),[&](char one, char two){
            return (int)one < (int)two;
        });
        int k = 0;
        for(int i = 0; i < s.size(); i++){
            if(vow.find(s[i]) != string::npos){
                s[i] = v[k];
                k++;
            }
        }
        return s;
    }
};