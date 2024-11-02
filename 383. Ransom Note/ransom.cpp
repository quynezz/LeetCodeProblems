class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) { 
        unordered_map<char,int> m1; 

        for(auto it : magazine){   
            m1[it]++;
        }
        for(auto it : ransomNote){   
            if(m1[it] <= 0){
                return false; 
            } else { 
                m1[it]--;
            }
        }
        return true;
    }
};