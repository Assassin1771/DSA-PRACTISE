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
    
    int res=0;
    int diameter(TreeNode* root)
{
    if(root==NULL)
        return 0;
    
    int left_height=diameter(root->left);
    int right_height=diameter(root->right);
    
    res=max(res,left_height+right_height);
    
    return max(left_height,right_height)+1;
}
    
    int diameterOfBinaryTree(TreeNode* root) {
        
    int value=diameter(root);
    
    return res;
        
    }
};