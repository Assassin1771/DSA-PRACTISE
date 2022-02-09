class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
//         for(int i=0;i<m;i++)
//         {
//             if(binary_search(matrix[i].begin(),matrix[i].end(),target))
//                 return true;
//         }
        
//         return false;
        
        //OR
        
        int row=0,col=n-1;
        while(row<m and col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            
            else if(matrix[row][col]>target)
                col--;
            
            else
                row++;
        }
        
        return false;
        
        
    }
};