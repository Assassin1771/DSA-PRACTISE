class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // https://leetcode.com/problems/rotate-image/discuss/1449737/Rotation-90Code-180-270-360-explanation-Inplace-O(1)-Space
        
        //TRANSPOSE (RAR)
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            int left=0,right=n-1;
            while(left<right)
            {
                swap(matrix[i][left],matrix[i][right]);
                
                ++left;
                --right;    
            }
            
        }
        
        
        
        
    }
};