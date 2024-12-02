class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) { 
        int count = 0;
        for(int i = 0; i < endTime.size(); i++){
            if(endTime[i] >= queryTime && startTime[i] <= queryTime){
                count++;
            }
        }
        return count;
    }
};