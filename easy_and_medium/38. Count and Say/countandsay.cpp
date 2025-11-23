class Solution {
private: 
string helper(int val){ 
    if(val == 1){
        return "1";
    }
    string res = "1";
    for(int i = 2; i <= val; i++){ 
        int count = 1; 
        string temp = ""; 
        for(int j = 1;  j < res.size(); j++){ 
            if(res[j] == res[j - 1]){ 
                count++;
            } else{ 
                temp += to_string(count) + res[j - 1]; 
                count = 1;
            }  
        }
            temp += to_string(count) + res.back();
            res = temp;
    }
    return res;
}


public:
    string countAndSay(int n) { 
        return helper(n);
    }
};