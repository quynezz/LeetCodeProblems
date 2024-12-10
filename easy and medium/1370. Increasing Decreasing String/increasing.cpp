class Solution {
public:
    string sortString(string s) {
        unordered_map<int,int> m;
        bool great = false; //false for min and true for max;
        bool visited[256];
        memset(visited,false,sizeof(visited));
        string res = "";
        for(auto it : s){
            int temp = 0;
            temp += (it - '0');
            m[temp]++;
        }
        while(res.size() < s.size()){ 
            // find min
            if(great == false){  
                    int small = INT_MAX;  
                    bool done = false; //iterate all the char
                for(auto [num, fre]: m){
                    if(!visited[num] && fre > 0){
                        small = min(small,num);
                        done = true;
                    }
                }
                // done process or not
                if(done == true){
                    res += (small + '0');
                    m[small]--;
                    visited[small] = true; 
                }else{ 
                    great = true;
                    memset(visited,false,sizeof(visited));
                }
            }
            // find max
             else if(great == true){  
                    int large = INT_MIN;  
                    bool done = false; //iterate all the char
                for(auto [num, fre]: m){
                    if(!visited[num] && fre > 0){
                        large = max(large,num);
                        done = true;
                    }
                }
                // done process or not
                if(done == true){ 
                    res += (large + '0');
                    m[large]--;
                    visited[large] = true; 
                }else{ 
                    great = false;
                    memset(visited,false,sizeof(visited));
                }
            }
        }
        return res;
    }
};