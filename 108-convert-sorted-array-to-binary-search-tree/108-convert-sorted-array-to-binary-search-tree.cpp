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
    
    TreeNode* constructBST(int low, int high, vector<int> &nums)
    {
        if(low>=high)
            return NULL;
        
        int mid=(low+high)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->left=constructBST(low,mid,nums);
        root->right=constructBST(mid+1,high,nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int low=0;
        int high=nums.size();
        
        return constructBST(low,high,nums);
        
    }
};