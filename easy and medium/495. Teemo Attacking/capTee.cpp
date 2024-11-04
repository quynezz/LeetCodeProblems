class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {   
        if(timeSeries.empty()){ 
            return 0;
        }
        int temp = 0; 
        for(int i = 1; i < timeSeries.size(); i++){ 
            temp+= min(timeSeries[i] - timeSeries[i - 1], duration); 
        }
        temp += duration; 
        return temp;
    }
};