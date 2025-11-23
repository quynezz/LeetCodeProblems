class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int sumIndex = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sumIndex += i;
            sum += arr[i];
            if(sum == sumIndex){
                count++;
            }
        }
        return count;
    }
};