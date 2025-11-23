class Solution {
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        calculateSumAndTilt(root, tilt);
        return tilt;
    }

private:
    int calculateSumAndTilt(TreeNode* root, int& tilt) {
        if (!root) return 0; 
         if(root->left == NULL && root->right == NULL){
        return root->val;
    }
        int leftSum = calculateSumAndTilt(root->left, tilt);  
        int rightSum = calculateSumAndTilt(root->right, tilt); 
        tilt += abs(leftSum - rightSum); 

        return leftSum + rightSum + root->val; 
    }
};
