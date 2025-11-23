class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // hardest easy problem
        unordered_map<char,int> m;
        vector<string> v;
        for(auto it : words[0]){  
            m[it]++;
        } 
        for(int i = 1; i < words.size(); i++){
            unordered_map<char,int> temp;
            for(auto it : words[i]){ 
                temp[it]++;
            }   
            for(auto [word,freq] : m){ 
                if(temp.count(word)){ 
                   m[word] = min(temp[word],freq);
                }else if(temp.find(word) == temp.end()){ 
                    while(m[word]> 0){ 
                        m[word]--;
                    }
                }
            }
        }
        for(auto [word,freq] : m ){ 
            while(freq > 0){  
                v.push_back(string(1,word));
                freq--;
            }
        }
        return v;
    }
};