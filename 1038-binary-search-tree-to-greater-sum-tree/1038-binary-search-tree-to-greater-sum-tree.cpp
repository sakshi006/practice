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
    
    void inorder(TreeNode*root, int &prev)
    {
        if(!root)
            return;
        
        inorder(root->right, prev);
        if(prev == -1)
        {
            prev = root->val;
        } else {
            root->val += prev;
            prev = root->val;
        }
        inorder(root->left,prev);
            
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return NULL;
        int prev = -1;
        inorder(root, prev);
        
        return root;
    }
};