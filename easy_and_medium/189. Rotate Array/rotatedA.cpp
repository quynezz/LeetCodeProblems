class Solution {
public:
    void rotate(vector<int>& nums, int k) { 
        k %= nums.size(); 
        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


// 
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         list<int> li;
//         k = k % nums.size();
//         if(nums.size() == 1){
//             return;
//         }
//         for (int i = 0; i < nums.size() - k; i++) {
//             li.push_back(nums[i]);
//         }
//         for (int i = nums.size() - 1; i >= nums.size() - k; i--) {
//             li.push_front(nums[i]);
//         } 
//         nums.clear();
//         for(auto it : li){ 
//             nums.push_back(it);
//         }
//     }
// };