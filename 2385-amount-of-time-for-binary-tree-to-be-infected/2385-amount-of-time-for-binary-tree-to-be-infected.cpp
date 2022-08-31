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
    
    TreeNode* getParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent, int start)
    {
        queue<TreeNode*>q;
        TreeNode* startNode = NULL;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start)
                startNode = curr;
            
            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return startNode;
    }
    
public:    
    int amountOfTime(TreeNode* root, int start) {
        if(!root) 
            return 0;
        
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>visited;
        
        TreeNode* startNode = getParent(root,parent, start);
        
        visited[startNode] = true;
        
        queue<TreeNode*>q;
        q.push(startNode);
        int ans = 0;
        
        while(!q.empty())
        {
            int n = q.size();
                int lev = 0;
            
            for(int i =0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left])
                {
                    lev = 1;
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right])
                {
                    lev = 1;
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]])
                {
                    lev = 1;
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
              if(lev == 1)
                ans++;
        }
        
        return ans;
    }
};