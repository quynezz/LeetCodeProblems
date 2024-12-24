class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words,char separator) {
        vector<string> v;
        for (int i = 0; i < words.size(); i++) {
            string temp = "";
            string res = "";
            for (auto it : words[i]) {
                if (it == separator) {
                    temp += ' ';
                } else {
                    temp += it;
                }
            }
            stringstream ss(temp);
            string word;
            while (ss >> word) {
                v.push_back(word);
            }
        }
        return v;
    }
};