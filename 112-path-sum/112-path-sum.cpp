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
    
    bool checkPaths(TreeNode* root, int sum, int t)
    {
        if(root==NULL)
            return false;
        
        if(root->left==NULL and root->right==NULL)
        {
            sum+=root->val;
            
            if(sum==t)
                return true;
        }
        
        sum+=root->val;
        
        return checkPaths(root->left,sum,t) or checkPaths(root->right,sum,t);        
            
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL and targetSum==0)
            return false;
        
        int sum=0;
        return checkPaths(root,sum,targetSum);
        
    }
};