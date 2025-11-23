class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 != 0) return false; 
        stack<int> free; 
        stack<int> open;
        for(int i = 0; i < s.size(); i++){
            if(locked[i] == '0'){
                free.push(i);
            }else if(locked[i] == '1' && s[i] == '('){
                open.push(i);
            }else if(locked[i] == '1' && s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }else if(open.empty() && free.empty()){
                    return false;
                }else{
                    free.pop();
                }
            }
        }
        while(!open.empty() && !free.empty()){
            int temp1 = open.top();
            int temp2 = free.top();
            if(temp1 < temp2){
                open.pop();
                free.pop();
            }else{
                return false;
            }
        }
        return open.empty() && free.size() % 2 == 0; 
    }
};