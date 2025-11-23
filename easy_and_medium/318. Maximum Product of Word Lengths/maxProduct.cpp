class Solution {
public:
    int maxProduct(vector<string>& words) { 
        vector<unsigned> v;
        int sum = 0;
        for(auto it : words){
            unsigned temp = 0;
            for(auto i : it){
                temp = temp | (1 << (i - 'a'));
            }
            v.push_back(temp);
        }
        for(int i = 0; i < v.size() - 1; i++){
            for(int j = i + 1; j < v.size(); j++){
                if((v[i] & v[j]) == 0){
                    int n = words[i].length();
                    int m = words[j].length();
                    sum = max(sum,n*m);
                }
            }
        }
        return sum;
    }
};