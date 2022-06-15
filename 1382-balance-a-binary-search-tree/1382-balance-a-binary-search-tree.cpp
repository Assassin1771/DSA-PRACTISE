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
    
    vector<int> inorder;
    
    void findInorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        findInorder(root->left);
        inorder.push_back(root->val);
        findInorder(root->right);
    }
    
    TreeNode* buildTree(int start, int end)
    {
        if(start>end)
            return NULL;
        
        int mid=(start+end)/2;
        TreeNode* head=new TreeNode(inorder[mid]);   
        
        head->left=buildTree(start,mid-1);
        head->right=buildTree(mid+1,end);
        
        return head;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        
        findInorder(root);
    
        return buildTree(0,inorder.size()-1);
    
    }
};