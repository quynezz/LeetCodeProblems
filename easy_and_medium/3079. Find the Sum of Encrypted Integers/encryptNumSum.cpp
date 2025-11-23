class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            int temp = 0;
            int n = it;
            while(n != 0){
                temp = max(temp,(n % 10));
                n /= 10;
            }
            if(it >= 10 && it < 100){
                sum += (temp * 11);
            }else if(it >= 100 && it < 1000){
                sum += (temp * 111);
            }else if(it < 10){
                sum += it;
            }else if(it == 1000){
                sum += 1111;
            }
        }
        return sum;
    }
};