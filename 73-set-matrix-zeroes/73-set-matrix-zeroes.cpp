class Solution {
public:
    
    void solve1(int x,vector<vector<int>> &temp)
    {
        for(int i=0;i<temp[0].size();i++)
            temp[x][i]=0;
    }
    
    void solve2(int y,vector<vector<int>> &temp)
    {        
        for(int i=0;i<temp.size();i++)
            temp[i][y]=0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        // vector<vector<int>> temp=matrix;
    
        int m=matrix.size();
        int n=matrix[0].size();
        
        set<int> s1;
        set<int> s2;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        
        for(auto i:s1)
            solve1(i,matrix);
        
        for(auto i:s2)
            solve2(i,matrix);
        
    }
};