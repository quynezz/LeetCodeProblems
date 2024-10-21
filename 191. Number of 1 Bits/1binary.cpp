class Solution {
private: 
int count1binaryinnumber(int n){  
    unordered_map<int,int> m;
    int temp = 1;
    while (n != 0){   
        int bit = n % 2;
        if(bit == 1){ 
            m[temp]++;
        }
        n /= 2;
    }
    return m[temp];
}
public:
    int hammingWeight(int n) {
        return count1binaryinnumber(n); 

    }
};