class Solution {
public:
    
    bool isSafe(int row,int col,vector<vector<int>> &mat)
    {
        int i=row,j=col;
        int n=mat.size();
        
        while(i>=0 and j>=0)
        {
            if(mat[i][j]==1)
                return false;
            
            i--;
            j--;
        }
        
        i=row;
        j=col;
        
        while(i<n and j>=0)
        {
            if(mat[i][j]==1)
                return false;
            
            i++;
            j--;
        }
        
        i=row;
        j=col;
        
        while(j>=0)
        {
            if(mat[i][j]==1)
                return false;
            
            j--;
        }
        
        return true;
    }
    
    void findNQueens(int col, vector<vector<int>> &mat, vector<vector<string>> &res)
    {
        if(col==mat.size())
        {
            vector<string> temp;
            string row="";
            
            for(int i=0;i<mat.size();i++)
            {
                for(int j=0;j<mat.size();j++)
                {
                    if(mat[i][j]==1)
                        row+='Q';
                    
                    else
                        row+='.';
                }
                
                temp.push_back(row);
                row="";
            }
            
            res.push_back(temp);
            return;
        }
        
        for(int row=0;row<mat.size();row++)
        {
            if(isSafe(row,col,mat))
            {
                mat[row][col]=1;
                findNQueens(col+1,mat,res);
                mat[row][col]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<vector<int>> mat(n, vector<int> (n,0));
        
        findNQueens(0,mat,res);
        
        return res;
        
    }
};