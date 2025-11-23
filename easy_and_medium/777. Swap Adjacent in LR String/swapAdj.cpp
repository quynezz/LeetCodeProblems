// class Solution {
// public:
//     bool canTransform(string start, string result) {
//             vector<pair<char,int>> v1, v2; 
//         for(int i = 0; i < start.length(); i++){
//          if(start[i] != 'X'){
//                 v1.push_back({start[i],i});
//             }
//         }
//         for(int i = 0; i < result.length(); i++){
//             if(result[i] != 'X'){
//                 v2.push_back({result[i],i});
//             }
//         }  
//         if(v1.size() != v2.size()) return false;
//         for(int i = 0; i < v1.size(); i++){
//             if(v1[i].first != v2[i].first){
//                 return false;
//             }
//             if(v1[i].first == 'L' && v1[i].second < v2[i].second){
//                     return false;
//             }
//             if(v1[i].first == 'R' && v1[i].second > v2[i].second){ 
//                  return false;
//             }
//         }
//         return true;
//     }
// };





class Solution {
public:
    bool canTransform(string start, string result) { 
        int i = 0, j = 0;
        int n = start.length();
        int m = result.length();
        while(i < n || j < m){
            while(i < n && start[i] == 'X') i++;
            while(j < m && result[j] == 'X') j++;
            if(i == n && j == n) return true;
            if(i == n || j == n || start[i] != result[j]) return false;
            if(start[i] == 'L' && i < j || start[i] == 'R' && i > j) return false;
            i++;
            j++;
        }
        return true;
    }
};