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
int countLeft(TreeNode* root){   
    int value = 0;
    while(root != NULL){ 
        value++; 
        root = root->left;
    }
    return value;
}
int countRight(TreeNode* root){    
    int value = 0;
    while(root != NULL){ 
        value++; 
        root = root->right;
    }
    return value;
}
public:
    int countNodes(TreeNode* root) {    
        if(root == NULL){ 
            return 0;
        } 
        int l = countLeft(root);
        int r = countRight(root); 
        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};