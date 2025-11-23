class Solution {
public:
    string digitSum(string s, int k) {
        bool ok = false;
        if(s.size() == k || s.size() < k){
            return s;
        }
        while(ok == false){  
            int i = 0; 
            string another = "";
            while(i < s.size()){
                int sum = 0;
                if(i + k <= s.size()){
                    int n = k;
                    while(n != 0){
                        sum += s[i] - '0';
                        i++;
                        n--;
                    } 
                    another += to_string(sum);
                }else{
                    while(i < s.size()){
                        sum += s[i] - '0';
                        i++;
                    }
                    another += to_string(sum);
                }
            }
            if(another.size() <= k){
                ok = true;
            }
                s = another;
        }    
        return s;
    }
};