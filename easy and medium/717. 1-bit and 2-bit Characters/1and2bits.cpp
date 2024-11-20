class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {  
        int i = 0;  
        int last = 0;  
        while(i < bits.size()){ 
            if(bits[i] == 1){
                if(i + 1 < bits.size()){
                    last = 1;
                    i += 2;
                }
            } 
            else if(bits[i] == 0){
                last = 0;
                i++;
            }
        } 
        return last == 0;
    }
};