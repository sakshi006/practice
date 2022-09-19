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
    
   void helper(TreeNode* root, int x, int y, int parent, int height, pair<int, int> &p1, pair<int,int>&p2){
        if(!root) return;
		
        if(root->val == x) {
            p1 = {parent, height};
        }
        else if(root->val == y){
            p2 = {parent,height};
        }
        
        helper(root->left, x, y, root->val, height+1, p1, p2);
        helper(root->right, x, y, root->val, height+1, p1,p2);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> x1, x2;
        helper(root, x,y, 0, 0, x1,x2);
        
        if(x1.first != x2.first && x1.second == x2.second) 
            return true;
        
        return false;
    }
};