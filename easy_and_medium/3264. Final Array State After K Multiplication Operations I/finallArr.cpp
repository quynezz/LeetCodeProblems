// class Solution {
// public:
//     vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         for(int i = 0; i < nums.size(); i++){
//             pq.push({nums[i],i});
//         }
//         while(k--){
//             auto [num,index] = pq.top();
//             pq.pop();
//             nums[index] = num * multiplier;
//             pq.push({nums[index],index});
//         }
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int temp = INT_MAX;
            int j = 0;
            for(int i = 0; i < nums.size(); i++){ 
                if(nums[i] == temp){
                    continue;
                }else if(nums[i] < temp){
                    temp = nums[i];
                    j = i;
                }
            }
            nums[j] = nums[j] * multiplier; 
        }
        return nums;
    }
};