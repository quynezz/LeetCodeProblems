class Solution {
public:
    int alternateDigitSum(int n) {
        string m = to_string(n); 
        int temp = 0;
        for(int i = 0; i < m.length(); i++){  
            if(i % 2 != 0){  
                temp += (m[i] - '0') * -1;
            } else { 
                temp += (m[i] - '0');
            }
        }
        return temp;
    }
};