class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {  
        unordered_map<string,int> m1; 
        unordered_map<string,int> m2;
        int i = 0, j = 0;  
        vector<string> v; 
        int ans = INT_MAX; 
        for(auto it : list1){  
            m1[it] = i;
            i++;
        }
        for(auto it : list2){  
            m2[it] = j;
            j++;
        }
        for(auto it : list1){ 
            if(m1.find(it) != m1.end() && m2.find(it) != m1.end()){
                int sum = m1[it] + m2[it];
                if(sum < ans){ 
                    ans = sum; 
                    v.clear();
                    v.push_back(it);
                } else if(sum == ans){ 
                    v.push_back(it);
                }
        }
        }
        return v;
    
        // vector<string> v;
        // int ans = INT_MAX;
        // for(int i = 0; i < list1.size(); i++){ 
        //     for(int j = 0; j < list2.size(); j++){ 
        //         if(list1[i] == list2[j]){ 
        //             int sum = i + j; 
        //             if(sum < ans){ 
        //                 ans = sum;
        //                 v.clear();
        //                 v.push_back(list1[i]);
        //             } else if(sum == ans){ 
        //                 v.push_back(list1[i]);
        //             }
        //         }
        //     }
        // }
        // return v;
    }
};