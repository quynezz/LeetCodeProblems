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
void inorder(TreeNode* root, vector<int> &v) {  
    if(root == NULL){
        return;
    }
    inorder(root->left,v); 
    v.push_back(root->val);
    inorder(root->right,v);
}
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        vector<int> temp;
        int res = 0;
        inorder(root,temp);
        for(auto it : temp){  
            if(it >= low && it <= high){
                res += it;
            }
        }
        return res;
    }
};