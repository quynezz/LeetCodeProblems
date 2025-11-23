class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        int temp = 0;
        int part = 0;
        for(auto it : arr){ 
            sum += it;
        }
        if(sum % 3 != 0){
            return false;
        }
        sum /= 3;
        for(int i = 0; i < arr.size(); i++){ 
            temp += arr[i];
            if(temp == sum){ 
                temp = 0;
                part++;
            }
            if(part == 3){
                return true;
            }
        }
        return false;
    }
};