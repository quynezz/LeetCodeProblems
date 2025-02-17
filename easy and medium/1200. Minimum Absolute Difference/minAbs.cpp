class Solution {
    public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
            vector<vector<int>> ans;
            sort(arr.begin(),arr.end());
            int min_element = INT_MAX;
            for(int i = 0; i < arr.size() - 1; i++){
                min_element = min(abs(arr[i + 1] - arr[i]),min_element);
            }
            for(int i = 0; i < arr.size() - 1; i++){
                    vector<int> temp;
                    if(abs(arr[i + 1] - arr[i]) == min_element){
                        temp.push_back(arr[i]);
                        temp.push_back(arr[i + 1]);            
                        ans.push_back(temp);
                }
            }
            return ans;
        }
    };