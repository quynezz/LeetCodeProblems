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
TreeNode* createNode(vector<int>& nums1, int start, int end){  
    if(start > end){ 
        return NULL;
    }
    int mid = (start + end) / 2; 
    TreeNode* root = new TreeNode(nums1[mid]);
    root->left = createNode(nums1,start, mid - 1);
    root->right = createNode(nums1,mid + 1, end);
    return root;
}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans =  createNode(nums,0,nums.size() - 1);
        return ans;
    }

};