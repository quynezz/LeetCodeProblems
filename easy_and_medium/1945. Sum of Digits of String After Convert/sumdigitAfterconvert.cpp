class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        int n = 0;
        for(auto it : s){ 
            int m = it - 'a' + 1;
           temp += to_string(m);
        }
        while(k--){
            for(auto it : temp){
                n += it - '0';
            }
            temp = to_string(n);
            if(k - 1 < 0){
                break;
            }else{
                n = 0;
            }
        }
        return n;
    }
};