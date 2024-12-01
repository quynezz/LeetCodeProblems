class Solution {
public:
    bool checkIfExist(vector<int>& arr) { 
        for(int i = 0; i < arr.size(); i++){   
            int n = arr[i];
            for(int j = 0;  j < arr.size(); j++){  
                if(arr[j] * 2 == arr[i] && i != j){ 
                    return true;
                }
            }
        }
        return false;
    }
};