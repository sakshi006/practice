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
    
    void getsum(TreeNode* root, bool leftcheck, int &sum)
    {
        if(!root)
            return;
        getsum(root->left,true,sum);
        getsum(root->right,false,sum);
        
        if(!root->left && !root->right && leftcheck)
            sum+= root->val;
        
        return;
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int sum=0;
        getsum(root,false,sum);
        return sum;
    }
};