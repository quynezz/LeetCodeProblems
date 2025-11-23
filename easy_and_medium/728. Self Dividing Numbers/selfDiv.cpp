class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) { 
        vector<int> v;
        bool ok = true;
        for(int i = left; i <= right; i++){ 
            int n = i;
            while(n > 0){
                int temp = n % 10;
                if(temp == 0){
                    ok = false;
                    break;
                } 
                if(i % temp != 0){
                   ok = false;
                   break;
                }
                n /= 10;
            }
            if(ok == true){
            v.push_back(i);
            }
            ok = true;
        }
        return v;
    }
};