// class Solution {
// public:
//     bool canChange(string start, string target) {   
//         // first method
//         vector<pair<char,int>> v1, v2; 
//         for(int i = 0; i < start.length(); i++){
//          if(start[i] != '_'){
//                 v1.push_back({start[i],i});
//             }
//         }
//         for(int i = 0; i < target.length(); i++){
//             if(target[i] != '_'){
//                 v2.push_back({target[i],i});
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
    bool canChange(string start, string target) {   
      int i = 0, j = 0;
        int n = start.length();
        int m = target.length();
        while(i < n || j < m){
            while(i < n && start[i] == '_') i++;
            while(j < m && target[j] == '_') j++;
            if(i == n && j == n) return true;
            if(i == n || j == n || start[i] != target[j]) return false;
            if(start[i] == 'L' && i < j || start[i] == 'R' && i > j) return false;
            i++;
            j++;
        }
        return true;
    }
};





