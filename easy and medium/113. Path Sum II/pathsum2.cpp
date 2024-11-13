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
void tree(TreeNode* root,vector<int> &temp,vector<vector<int>> &ans,int tar){   
    
    temp.push_back(root->val); 

    if(root->right == NULL && root->left == NULL){
        int n = 0; 
        for(auto it : temp){ 
            n += it;
        }
        if(n == tar){
            ans.push_back(temp);
        } 
        return;
        }

    if(root->left){  
        tree(root->left,temp,ans,tar);
        temp.pop_back();
    }  
    if(root->right){ 
      tree(root->right,temp,ans,tar); 
      temp.pop_back();
    }
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        if(root){ 
            tree(root,temp,res,targetSum);
        }
        return res;
    }
};