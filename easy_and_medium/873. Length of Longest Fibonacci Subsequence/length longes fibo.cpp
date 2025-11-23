class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int longest = 0;
            if(arr.size() < 3) return 0;
            unordered_map<int,int> m; 
            for(auto it : arr) m[it]++;
            for(int i = 0; i < arr.size() - 2; i++){
                vector<int> v;
                v.push_back(arr[i]);
                for(int j = i + 1; j < arr.size(); j++){
                    if(v.size() == 1) v.push_back(arr[j]);
                    while(true){
                        int sum = v[v.size() - 2] + v[v.size() - 1];
                        if(m.count(sum)) {
                            v.push_back(sum);
                        } else{
                            break;
                        }
                    }
                    if(v.size() >= 2){
                        int n = v.size(); 
                        longest = max(n,longest);
                        v.clear();
                        v.push_back(arr[i]);
                    }
                }
            }
            return longest == 2 ? 0 : longest;
        }
    };