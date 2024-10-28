class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {  
        // visited
        int n = nums.size(); 
        bool visited[n + 1];
        memset(visited,false,sizeof(visited));
        for(auto it : nums){  
            if(it > 0 && it <= n){  
                visited[it] = true;
            }
        }
        for(int i = 1; i <= n; i++){ 
            if(!visited[i]){  
                return i;
            }
        }
            return n + 1;
            
            // Hash Set
        // unordered_set<int> s;
        // int n = nums.size(); 
        // for(auto it : nums){  
        //     s.insert(it);
        // }
        // int temp = 0;
        // for(int i = 1; i <= n; i++){  
        //     if(s.find(i) == s.end()){  
        //         temp = i;
        //         break;
        //     } else { 
        //         temp = n + 1;
        //     }
        // }
        // return temp;
    }
};