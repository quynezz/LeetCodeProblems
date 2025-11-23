class Solution {
public:
// brute force
    int longestPalindrome(string s) { 
        unordered_map<char,int> m;
        bool visited[10000001];
        memset(visited,false,sizeof(visited));
        int ans = 0; 
        int count = 0;
        for(auto it : s){ 
            m[it]++;
        }   
        for(auto temp : s){ 
            if(!visited[temp]){ 
            if(m[temp] % 2 == 0){
                ans += m[temp];
                visited[temp] = true;
            } else if(m[temp] % 2 != 0 && count == 0){  
                ans += m[temp];
                visited[temp] = true;
                count++;
            }else if(m[temp] % 2 != 0 && count != 0){ 
                m[temp]--;
                ans += m[temp];
                visited[temp] = true;
            }
             else if(m[temp] == 1 && count != 0){ 
                ans--;
                visited[temp] = true;
            } else if(m[temp] == 1 && count == 0){ 
                ans += m[temp];
                visited[temp] = true;
            }
            }
        }
        return ans;
    }
};