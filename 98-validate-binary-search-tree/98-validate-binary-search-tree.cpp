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
    
    bool checkbst(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if(!root)
            return true;
        
        if((min && root->val <= min->val) || (max && root->val >= max->val))
            return false;
        
        return (checkbst(root->left, min, root) && checkbst(root->right, root, max));
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return checkbst(root, NULL, NULL);
    }
};