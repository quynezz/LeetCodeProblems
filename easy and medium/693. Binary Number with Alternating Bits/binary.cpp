class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> v;
        while(n != 0){
            int temp = n % 2; 
            v.push_back(temp);
            n /= 2;
        }
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i] == v[i + 1]){
                return false;
            }
        }
        return true;
    }
};