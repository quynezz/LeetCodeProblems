class Solution {
public:
    bool rotateString(string s, string goal) { 
        string ss = s + s;
        int i = 0; 
        //sub from i and move j step;
      if (s.length() != goal.length()) {
    return false;
}

        while(i <= ss.length() - goal.length()){ 
            if(ss.substr(i,goal.length()) == goal){
                return true;
            }
            i++;
        }
        return false;
    }
};