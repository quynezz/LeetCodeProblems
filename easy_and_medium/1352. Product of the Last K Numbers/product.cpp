#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int maxN = 1000001;
const int MOD = 1e9;
#define vii vector<pair<int, int>>

class ProductOfNumbers {
    vector<int> nums;
    public:
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            nums.push_back(num);
        }
        
        int getProduct(int k) {
            int count = 1;
            for(long long i = nums.size() - 1; i >= 0; i--) {
                if(k != 0){
                    count *= nums[i]; 
                    k--;  
                }
            }
            return count;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */

auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
// int main() {   
//     Solution s; 
//     vector<int> nums = {1,1,2,4,9};
//     int k = 20;
//     s.minOperations(nums,k);
// }
