class Solution {
public:
    int takeCharacters(string s, int k) { 
        int a = 0, b = 0, c = 0; 
        for(auto it : s){
            if(it == 'a') a++; 
            else if(it == 'b') b++;
            else if(it == 'c') c++; 
        }
        if(a < k || b < k || c < k) return -1;
        int l = 0;
        int maxW = 0;
        vector<int> v(3);
        for(int r = 0; r < s.length(); r++){  
            v[s[r] - 'a']++;
            while(v[0] > a - k || v[1] > b - k || v[2] > c - k){  
                v[s[l] - 'a']--;
                l++;
            } 
            maxW = max(maxW,r - l + 1);
        }
        return s.length() - maxW;
    }
};
