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
    
private:
    vector<vector<int>> res;

public:
    
    void findPaths(TreeNode* root, int sum, int t, vector<int> temp)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL and root->right==NULL)
        {
            sum+=root->val;
            
            if(sum==t)
            {
                temp.push_back(root->val);
                res.push_back(temp);
                
                return;
            }
        }
        
        sum+=root->val;
        temp.push_back(root->val);
        
        findPaths(root->left,sum,t,temp);
        findPaths(root->right,sum,t,temp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
                
        if(root==NULL)
            return res;
    
        vector<int> temp;
        
        int sum=0;
        findPaths(root,sum,targetSum,temp);
        
        return res;
        
    }
};