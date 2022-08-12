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
    
    TreeNode* findlarge(vector<int>&nums, int start, int end)
    {
        if(start == end)
            return NULL;
        int mx  = maxi(nums, start, end);
        TreeNode* root = new TreeNode(nums[mx]);
        root->left = findlarge(nums, start, mx);
        root->right = findlarge(nums, mx+1, end);
        
        return root;
    }
    
    int maxi(vector<int>&nums, int start, int end)
    {
        int mx = start;
        for(int i = start; i < end; i++)
        {
            if(nums[i] > nums[mx])
                mx = i;
        }
        return mx;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return findlarge(nums, 0 , n);
    }
};