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
    
    int func(TreeNode* root, int &d)
    {
        if(!root)
            return 0;
        
        int lh = func(root->left, d);
        int rh = func(root->right, d);
        d = max(d, lh+rh);
        
        return max(lh,rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int diameter = 0;
        
        func(root, diameter);
        
        return diameter;
    }
};