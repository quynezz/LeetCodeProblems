class Solution {
private:  
void generate(int open, int closed,int max, vector<string> &result, string &current){   
    if(current.length() == max * 2){ 
        result.push_back(current);
        return;
    }
    if(open < max){ 
        current.push_back('('); 
        generate(open + 1, closed, max, result, current);
        current.pop_back();
    }
    if(closed < open){ 
        current.push_back(')');
        generate(open, closed + 1, max, result, current);
        current.pop_back();
    }
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result; 
        string current = "";
        generate(0,0,n,result,current);
        return result;
    }
};