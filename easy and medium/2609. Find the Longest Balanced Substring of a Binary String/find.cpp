class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int longest = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '1'){
                continue;
            }
            int count0 = 1;
            int count1 = 0;
            bool seen = false;
            for(int j = i + 1; j < s.size(); j++){
                // both equal '0';
                if(s[j] == '0' && seen == false){
                    count0++;
                }else if(s[j] == '1' && seen == false){
                    seen = true;
                    count1++;
                    if(count1 == count0) break;
                }else if(s[j] == '1' && seen == true){
                    count1++;
                    if(count1 == count0) break;
                }else if(s[j] == '0' && seen == true){
                    break;
                }
            }
            if(count0 == count1){
            longest = max(longest,count0+count1);
            }
        }
        return longest;
    }
};