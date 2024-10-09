#include <bits/stdc++.h>
typedef long long ll; 

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { 
        int n = nums.size();
        if (target > nums[n - 1]) {  
            return n;
        } 
        
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int m = (l + r) / 2; 
            if (nums[m] == target) {   
                return m;
            } else if (nums[m] > target) {  
                r = m - 1; 
            } else { 
                l = m + 1; 
            }
        }
        return l; 
    }
};
