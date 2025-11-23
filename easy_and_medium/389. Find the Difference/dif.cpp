class Solution {
public:
    char findTheDifference(string s, string t) { 
        int i = 0; 
        int j = 0; 
        for(auto it : s){ 
            i += it;
        } 
        for(auto it : t){ 
            j += it;
        }
        int temp = j - i; 
        return (char)temp;
    }
};