class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) { 
        long long sum = 0;
        int i = 0; 
        int j = nums.size() - 1;
        while(i < j){ 
            string temp = to_string(nums[i]) + to_string(nums[j]); 
            sum += stoi(temp);
            i++;
            j--;   
        }
        if(nums.size() % 2 != 0){ 
            sum += nums[(nums.size() / 2)];
        }
        return sum;
    }
};