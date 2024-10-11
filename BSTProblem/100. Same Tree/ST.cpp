class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base cases
        if (!p && !q) return true;  // Both are null
        if (!p || !q) return false; // One is null, but the other is not
        return (p->val == q->val) && 
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
