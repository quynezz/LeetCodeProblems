class Solution {
    public:
        int sumOddLengthSubarrays(vector<int>& arr) {
            int count = 0;
            for(int i = 0; i < arr.size(); i++){
                vector<int> temp; 
                for(int j = i; j < arr.size(); j++){
                    temp.push_back(arr[j]);
                    if(temp.size() % 2 != 0 && temp.size() > 2){
                        for(auto it : temp) count += it;
                    } 
                    if(temp.size() == 1){
                        count += arr[j];
                    }
                }
            }
            return count;        
        }
    };
    
    
    
    
    
    // class Solution {
    // public:
    //     int sumOddLengthSubarrays(vector<int>& arr) {
            
    //     }
    // };