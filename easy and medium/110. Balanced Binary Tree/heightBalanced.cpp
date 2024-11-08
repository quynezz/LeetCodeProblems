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
int FindHeight(TreeNode *root){ 
    if(root == NULL){  
        return -1;
    } 
    int LeftHeight = FindHeight(root->left);
    int RightHeight = FindHeight(root->right);
    return (max(LeftHeight,RightHeight) + 1);
}
public:
    bool isBalanced(TreeNode* root) {  
        if(root == NULL){ 
            return 1;
        }
        int l = FindHeight(root->left);
        int r = FindHeight(root->right);                
        if (abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right)){ 
            return true;
        } 
        return false;
    }
};