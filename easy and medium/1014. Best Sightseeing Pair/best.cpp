class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int tempMax = INT_MIN;
        tempMax = max(tempMax,values[0]);
        int ans = INT_MIN;
        for(int i = 1; i < values.size(); i++){
            tempMax--;
            int temp = tempMax + values[i];
            ans = max(temp,ans); 
            tempMax = max(values[i],tempMax);
        }
        return ans;
    }
};