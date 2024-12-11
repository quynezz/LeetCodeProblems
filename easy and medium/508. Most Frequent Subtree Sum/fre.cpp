/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
int DFS(TreeNode* root, unordered_map<int,int>& m){
    // base case:  
    if(!root){  
        return 0;
    } 
    int left = DFS(root->left,m);
    int right = DFS(root->right,m);
    int sum = left + right + root->val;
    m[sum]++;
    return sum;
}
int temp = 0;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        unordered_map<int,int> m;
        DFS(root,m);
        int count = 0;
        for(auto& [num,fre] : m){
            count = max(fre,count);
        }
        for(auto& [num,fre] : m){
            if(fre == count){
                v.push_back(num);
            }
        }
        return v;
    }
};