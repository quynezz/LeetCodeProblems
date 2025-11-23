class Solution {
public:
    string largestOddNumber(string num) {
        int last = -1;
        for(int i = num.size(); i >= 0 ; i--){
            if((num[i] - '0') % 2 != 0){
                last = i;
                break;
            }
        }
        if(last != -1){
            return num.substr(0,last + 1);
        }
        return "";
    }
};