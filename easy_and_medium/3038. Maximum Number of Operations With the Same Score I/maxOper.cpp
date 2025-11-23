class Solution {
public:
    int maxOperations(vector<int>& nums) {
        deque<int> q(nums.begin(),nums.end());
        int temp = 0;
        int count = 0;
        bool first = false;
        while(q.size() >= 2){
            int n = q.front();
            q.pop_front();
            int m = q.front();
            q.pop_front();
            if(first == false){
                temp = (n + m);
                count++;
                first = true;
            }else{
                if(temp != (n + m)){
                    break;
                }else{
                    count++;
                }
            }
        }
        return count;
    }
};