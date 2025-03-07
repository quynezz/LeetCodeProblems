class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
        vector<int> ans;
         int shortest = INT_MAX;
    
         auto check_prime = [&](int a) -> bool{ 
            if(a == 1) return false;
            for(int i = 2; i <= sqrt(a); i++){
                    if(a % i == 0) return false;
            }
            return true;
         };
    
         for(int i = left; i <= right; i++){
            if(check_prime(i)) {
                ans.push_back(i);
                cout << i << " ";
            }
         }   
        if(ans.size() < 2) return {-1,-1};
        int first = 0, second = 0;
        for(int i = 0; i < ans.size() - 1; i++){
            if((ans[i + 1] - ans[i]) < shortest){
                shortest = ans[i + 1] - ans[i];
                first = ans[i], second = ans[i + 1];
            }
        }
        return {first,second};
        }
    };