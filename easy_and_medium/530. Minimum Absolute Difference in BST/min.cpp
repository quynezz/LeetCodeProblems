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
void inorderTra(TreeNode* root,vector<int> &s){ 
    if(root == NULL) return;
    inorderTra(root->left,s);
    s.push_back(root->val);
    inorderTra(root->right,s);

}
public:
    int getMinimumDifference(TreeNode* root) {  
        int temp = INT_MAX;
        if(root == NULL){ 
            return 0;
        }
        vector<int> v;
        inorderTra(root,v);
        sort(v.begin(),v.end());
        for(int i = 1; i < v.size(); i++){ 
            temp = min(temp,(v[i] - v[i - 1]));
        }
        return temp;
    }
};