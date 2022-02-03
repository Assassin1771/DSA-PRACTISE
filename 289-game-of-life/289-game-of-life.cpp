class Solution {
public:
    
    int dx[8]={0,-1,-1,-1,0,1,1,1};
    int dy[8]={-1,-1,0,1,1,1,0,-1};
    
    bool isSafe(int x,int y,vector<vector<int>>& board)
    {
        
        int m=board.size();
        int n=board[0].size();
        
        if(x<0 or x>=m or y<0 or y>=n)
            return false;
        
        return true;
    }
    
    int check(int x,int y,vector<vector<int>>& board)
    {
        int count=0;
        for(int i=0;i<8;i++)
        {
            int xCoordinate=x+dx[i];
            int yCoordinate=y+dy[i];
            if(isSafe(xCoordinate,yCoordinate,board) and board[xCoordinate][yCoordinate]==1)
            {
                count++;
                // cout<<x<<" "<<y<<" "<<xCoordinate<<" "<<yCoordinate<<" "<<count<<endl;
            }
        }
        
        return count;
        
        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<int>> res;
        
        for(int i=0;i<m;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                int x=check(i,j,board);
                // cout<<x<<endl;
                
                if(board[i][j])
                {
                    if(x<2)
                        temp.push_back(0);
                    
                    else if (x==2 or x==3)
                        temp.push_back(1);
                    
                    else if(x>3)
                        temp.push_back(0);
                }
                
                else
                {
                    if(x==3)
                        temp.push_back(1);
                    
                    else
                        temp.push_back(0);
                }
            }
            
            res.push_back(temp);
            temp.clear();
        }
        
        board=res;
        
    }
};