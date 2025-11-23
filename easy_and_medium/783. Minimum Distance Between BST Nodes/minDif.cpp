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
void DFS(TreeNode* root, vector<int>& v){
    if(!root){
        return;
    }
    DFS(root->left,v);
    v.push_back(root->val);
    DFS(root->right,v);
}
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> temp; 
        int res = INT_MAX;
        DFS(root,temp);
        for(int i = 0; i < temp.size() - 1; i++){
            for(int j = i + 1; j < temp.size(); j++){
                int n = abs(temp[i] - temp[j]);
                res = min(n,res);
            }
        }
        return res;
    }

};