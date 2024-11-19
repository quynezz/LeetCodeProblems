class Solution {
public:
    string reverseStr(string s, int k) { 
        int i = 0;
        string temp = "";
        string res = "";
        bool Swap = false;  
        int count = k;
        while(i < s.length()){ 
            temp.push_back(s[i]);  
            count--;
            if(count == 0){ 
                if(Swap == false){ 
                    reverse(temp.begin(),temp.end());
                }
                for(auto it : temp) res += it;
                temp = "";
                Swap = !Swap;
                count = k;
            }
            i++;
        }
        if(!temp.empty()){
            if(!Swap){
                reverse(temp.begin(),temp.end());
            }
            for(auto it : temp) res += it;
        }
        return res;
    }
};