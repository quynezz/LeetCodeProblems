class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> v;
        if(k == 0){
            for(auto it :code){
                v.push_back(0);
            }
            return v;
        }
        if(k > 0){ 
            for(int i = 0; i < code.size(); i++){
                int j = i + 1; 
                int sum = 0;
                int temp = k; 
                while(temp != 0){
                    if(j >= code.size()){
                        j -= code.size();
                    }
                    sum += code[j];
                    j++;
                    temp--;
                }
                v.push_back(sum);
            }
        }else if(k < 0){ 
            for(int i = 0; i < code.size(); i++){
                int j = i - 1; 
                int sum = 0;
                int temp = abs(k); 
                while(temp != 0){
                    if(j < 0){
                        j += code.size();
                    }
                    sum += code[j];
                    j--;
                    temp--;
                }
                v.push_back(sum);
            }
        }
        return v;
    }
};