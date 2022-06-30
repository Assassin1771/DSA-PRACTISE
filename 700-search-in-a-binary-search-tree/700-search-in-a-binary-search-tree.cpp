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
    
    TreeNode* searchNode(TreeNode* root, int key)
    {
        if(root==NULL)
            return NULL;
        
        if(root->val==key)
            return root;
        
        else if(root->val>key)
            return searchNode(root->left,key);
        
        else if(root->val<key)
            return searchNode(root->right,key);
        
        return NULL;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return searchNode(root,val);
        
    }
};