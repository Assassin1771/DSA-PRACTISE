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
    
    TreeNode* insert(TreeNode* root, int key)
    {
        if(root==NULL)
            return new TreeNode(key);
        
        if(root->val>key)
            root->left=insert(root->left,key);
        
        else if(root->val<key)
            root->right=insert(root->right,key);
        
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return insert(root, val);
        
    }
};