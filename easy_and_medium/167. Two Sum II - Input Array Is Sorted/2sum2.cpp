class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { 
        int i = 0; 
        int j = numbers.size() - 1;
        int sum = 0;
        while(i < numbers.size() && j > 0){
            int sum = numbers[i] + numbers[j]; 
            if(sum < target){
                i++;
            }else if(sum == target){
                break;
            }else{ 
                j--;
            }
        }
            return {i + 1, j + 1};
    }
};