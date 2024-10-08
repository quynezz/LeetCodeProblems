#include <bits/stdc++.h>
typedef long long ll; 

using namespace std;
class Solution {
public:
// Using two-pointers
    int removeElement(vector<int>& nums, int val) {
        int i = 0;  // Pointer for the position of valid elements
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];  // Move valid elements to the front
                i++;  // Increment the position for the next valid element
            }
        }
        return i;  // Return the new size of valid elements
        // Test cases loop to test itself
    }
};
