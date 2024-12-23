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
    // For each level, store into a vector, consist of two vector(one is original and one is sorted), compare two of them and make the least minimum swap 
private: 
int getMin(vector<int>& temp){
    vector<int> original = temp;
    sort(original.begin(),original.end());
    unordered_map<int,int> M; 
    // store swap;
    int countSwap = 0;
    for(int i = 0; i < temp.size(); i++){
        M[temp[i]] = i;
    }
    for(int i = 0; i < temp.size(); i++){
        if(original[i] != temp[i]){
            int index1 = 0; 
            int index2 = 0; 
            index1 = M[original[i]];
            index2 = M[temp[i]];
            swap(temp[index1],temp[index2]);
            M[temp[index1]] = index1;
            M[temp[index2]] = index2;
            countSwap++;
        }
    }
    return countSwap;
}
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int level = q.size();
            vector<int> lv(level);  
            for(int i = 0; i < level; i++){
                TreeNode* current = q.front();
                q.pop();
                lv[i] = current->val;
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            count += getMin(lv);
        }
        return count;
    }
};