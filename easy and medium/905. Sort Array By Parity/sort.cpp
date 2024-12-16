class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> q;
        for(auto it : nums){
            if(it % 2  == 0){
                q.push_front(it);
            }else if(it % 2 != 0){
                q.push_back(it);
            }
        }
        nums.clear();
        while(!q.empty()){
            nums.push_back(q.front());
            q.pop_front();
        }
        return nums;
    }
};