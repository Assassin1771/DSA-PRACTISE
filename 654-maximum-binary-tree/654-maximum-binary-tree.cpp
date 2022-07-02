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
    
    TreeNode* constructTree(int start, int end, vector<int> &nums)
    {
        if(start<=end)
        {
            int ind=0;
            int maxx=-1;
            for(int i=start;i<=end;i++)
            {
                if(nums[i]!=-1)
                {
                    if(maxx<nums[i])
                    {
                        maxx=nums[i];
                        ind=i;
                    }
                }
            }
            
            TreeNode* root=new TreeNode(nums[ind]);
            nums[ind]=-1;
            
            root->left=constructTree(start,ind-1,nums);
            root->right=constructTree(ind+1,end,nums);
            
            return root;
        }
        
        return NULL;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int start=0, end=nums.size();
        
        return constructTree(start,end-1,nums);
        
    }
};