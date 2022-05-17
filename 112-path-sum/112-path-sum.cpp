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
    bool ans = false;
    bool sumTree(TreeNode* root, int t,int sum)
    {
        if(root)
        {
            sum+=root->val;
            if(root->left == NULL && root->right == NULL and sum == t)
                return true;
            
            return sumTree(root->left,t,sum) || sumTree(root->right,t,sum);
        }
                
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum=0;
        return sumTree(root,targetSum,sum);
    }
};