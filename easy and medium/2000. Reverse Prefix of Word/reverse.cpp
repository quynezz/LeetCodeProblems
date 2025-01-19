class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.find(ch) == string::npos) return word;
        int index = word.find(ch);
        string temp = word.substr(0,index + 1);
        cout << index << endl;
        reverse(temp.begin(),temp.end());
        for(int i = index + 1; i < word.size(); i++){
            temp += word[i];
        }
        return temp;

    }
};