class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isSafe(int x, int y, vector<vector<char>> &board)
    {
        int m=board.size();
        int n=board[0].size();
        
        if(x<0 or y<0 or x>=m or y>=n or board[x][y]=='0')
            return false;
        
        return true;
    }
    
    bool fun(int x, int y, string &temp, vector<vector<char>> &board, string &word)
    {
        
        if(!isSafe(x,y,board))
            return false;
    
        if(temp==word)
            return true;
        
        if(temp.size()>word.size())
            return false;
        
        char original=board[x][y];
        
        for(int i=0;i<4;i++)
        {
            temp.push_back(original);
            board[x][y]='0';
            
            if(temp==word)
                return true;
            
            int l=temp.size();
            if(temp[l-1]!=word[l-1])
            {
                temp.pop_back();
                board[x][y]=original;
                
                return false;
            }
            
            if(fun(x+dx[i],y+dy[i],temp,board,word))
                return true;
            
            temp.pop_back();
            board[x][y]=original;
        }
        
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        
        string temp="";
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    bool flag1=fun(i,j,temp,board,word);
                    
                    if(flag1==true)
                        return true;
                }
            }
        }
    
        return false;
        
    }
};