class Solution {
public:
    double trimMean(vector<int>& arr) {
        double n = arr.size() *  0.05;
        int m = arr.size() *  0.05;
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = arr.size() - 1;
        while(n != 0){
            arr[i] = 0;
            arr[j] = 0;
            i++;
            j--;
            n--;
        }
        double sum = 0;
        for(auto it : arr){
            sum += it;
        }
        return sum / ((arr.size() - (m * 2))) ;
    }
};