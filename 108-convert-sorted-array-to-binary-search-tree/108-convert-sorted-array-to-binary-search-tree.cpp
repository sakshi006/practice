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
    
    TreeNode* getTree(vector<int>&nums, int n, int low, int high)
    {
        while(low<=high)
        {
            int m = low+(high-low)/2;
            TreeNode* root = new TreeNode(nums[m]);
            root->left = getTree(nums, n, low,m-1);
            root->right = getTree(nums, n, m+1, high);
            
            return root;
        }
        
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int l =0, h = n-1;
        
        return getTree(nums,n,l,h);
    }
};