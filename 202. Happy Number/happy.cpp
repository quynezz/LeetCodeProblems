
class Solution {
public:
    bool isHappy(int n) { 
        int temp = 0;
        map<int, int> m; 
        vector<int> v; 
        
        while(n > 0) { 
            int digit = n % 10; 
            n = n / 10;  
            v.push_back(digit);
        }  
        // loop forever  until it meet the duplicate temp;
        while (true) {  
            temp = 0;
            for(int i = v.size() - 1; i >= 0; i--) { 
                temp += v[i] * v[i]; 
            } 
            
            if(temp == 1) { 
                return true; 
            }  
            if(m[temp] > 0) {  
                return false; 
            } 
            m[temp]++; 
            
            v.clear();
            while(temp > 0) { 
                int digit = temp % 10; 
                v.push_back(digit); 
                temp /= 10; 
            }
            
        }
        
        return false; 
    }
};
