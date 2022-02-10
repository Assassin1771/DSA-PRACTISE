class Solution {
public:
    
    void solve(int x,int y,vector<vector<int>> &temp)
    {
        for(int i=0;i<temp.size();i++)
            temp[i][y]=0;
        
        for(int i=0;i<temp[0].size();i++)
            temp[x][i]=0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<vector<int>> temp=matrix;
    
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    solve(i,j,temp);
                }
            }
        }
        
        matrix=temp;
        
    }
};