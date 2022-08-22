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
public:
    int d = INT_MAX;
    TreeNode* prev = NULL;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(prev)
            d = min(d, abs(root->val - prev->val));
        prev = root;
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        inorder(root);
        return d;    
    }
};