/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        
        if(p->val == root->val || q->val == root->val)
            return root;
        
        TreeNode * lca1 = lowestCommonAncestor(root->left, p,q);
        TreeNode * lca2 = lowestCommonAncestor(root->right, p,q);
        
        if(lca1 && lca2)
            return root;
        
        if(!lca1)
            return lca2;
        else 
            return lca1;
    }
};