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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        long long res=0;
        
        while(q.size())
        {
            long long curr_size=q.size();
            long long leftMost=-1,rightMost=-1;
            long long currMin=q.front().second;
            
            for(int i=0;i<curr_size;i++)
            {
                TreeNode* currNode=q.front().first;
                long long currInd=q.front().second-currMin;
                
                q.pop();
                
                if(i==0)
                    leftMost=currInd;
                
                if(i==curr_size-1)
                    rightMost=currInd;
                
                if(currNode->left)
                    q.push({currNode->left,2*currInd+1});
                
                if(currNode->right)
                    q.push({currNode->right,2*currInd+2});
                
                // cout<<currNode->val<<" "<<currInd<<endl;
            }
            
            res=max(res,rightMost-leftMost+1);
        }
     
        return res;
    }
};