class Solution {
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++){
            int ones = 0;
            int n = i;
            while(n != 0){
                n % 2 == 1? ones += 1 : ones += 0;
                n /= 2;
            }
            isPrime(ones) == true ? count +=1 : count += 0;
        }   
        return count;
    }
};