class Solution {
public:
    string sortSentence(string s) {  
        unordered_map<int,string> m;
        string temp = "";
        vector<int> v;
        stringstream ss(s); 
        string word;  
        while(ss >> word){ 
            int n = word.back() - '0';
            word.pop_back();
            m[n] = word;
            v.push_back(n); 
        }  
        sort(v.begin(),v.end());  
        for(int i = 0; i < v.size(); i++){  
            temp += m[v[i]];
            temp += ' ';
        }
        temp.pop_back();
        return temp;
    }

};