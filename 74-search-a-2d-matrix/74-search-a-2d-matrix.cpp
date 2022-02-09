class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //O(MN)
        //O(MLOGN)
        int m=matrix.size();
        int n=matrix[0].size();
        
//         int row=0,col=n-1;
//         while(row<m and col>=0)
//         {
//             if(matrix[row][col]==target)
//                 return true;
            
//             else if(matrix[row][col]>target)
//                 col--;
            
//             else
//                 row++;
//         }
        
//         return false;
        
        // O(M+N)
        
        
        int start=0,end=(m*n)-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int val=matrix[mid/n][mid%n];
            
            if(val==target)
                return true;
            
            else if(val>target)
                end=mid-1;
            
            else
                start=mid+1;
            
        }
        
        return false;
        

        
    }
};