class Solution {
public:
    
    void findNQueens(int col, vector<vector<int>> &mat, vector<vector<string>> &res, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
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
            if(leftRow[row]==0 and upperDiagonal[mat.size()-1+col-row]==0 and lowerDiagonal[row+col]==0)
            {
                leftRow[row]=1;
                upperDiagonal[mat.size()-1+col-row]=1;
                lowerDiagonal[row+col]=1;
                
                mat[row][col]=1;
                findNQueens(col+1,mat,res,leftRow,lowerDiagonal,upperDiagonal);
                mat[row][col]=0;
                
                leftRow[row]=0;
                upperDiagonal[mat.size()-1+col-row]=0;
                lowerDiagonal[row+col]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        
        vector<vector<string>> res;
        vector<vector<int>> mat(n, vector<int> (n,0));
        
        vector<int> leftRow(n,0);
        vector<int> upperDiagonal(2*n-1,0);
        vector<int> lowerDiagonal(2*n-1,0);
        
        findNQueens(0,mat,res,leftRow,upperDiagonal,lowerDiagonal);
        
        return res.size();
        
    }
};