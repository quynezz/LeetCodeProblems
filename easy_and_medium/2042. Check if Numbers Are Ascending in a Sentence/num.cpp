class Solution {
public:
    bool areNumbersAscending(string s) { 
        vector<int> v;
        stringstream ss(s); 
        string word; 
        while(ss >> word){ 
            if(isdigit(word[0])){  
                v.push_back(stoi(word));
            }
        }
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i] >= v[i + 1]){ 
                return false;
            }
        } 
        return true;
    }
};