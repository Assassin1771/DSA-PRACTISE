class Solution {
public:
    
    double total=0;
    double valid=0;
    
    int dx[8]={-2,-2,-1,1,2,2,-1,1};
    int dy[8]={1,-1,2,2,1,-1,-2,-2};
    
    bool isSafe(int x, int y, int n)
    {
        if(x<0 or y<0 or x>=n or y>=n)
            return false;
        
        return true;
    }
    
    double findAllPaths(int x, int y, int n, int k, vector<vector<vector<double>>> &dp)
    {           
        if(!isSafe(x,y,n))
            return 0;
        
        if(k==0)
            return 1;
        
        if(dp[x][y][k]!=-1)
            return dp[x][y][k];
        
        double count=0;
        for(int i=0;i<8;i++)
        {
            count+=findAllPaths(x+dx[i],y+dy[i],n,k-1,dp);
        }
        
        count/=8;
        
        return dp[x][y][k]=count;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>> (n+1, vector<double> (k+1,-1)));
        return findAllPaths(row,column,n,k,dp);
    }
};