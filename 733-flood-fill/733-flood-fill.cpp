class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isSafe(int row, int col, int color, vector<vector<int>> &image)
    {
        int m=image.size();
        int n=image[0].size();
        
        if(row<0 or row>=m or col<0 or col>=n or image[row][col]!=color)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>> &image, int row, int col, int color, int newColor)
    {
        if(!isSafe(row,col,color,image))
            return;
        
        image[row][col]=newColor;
        
        for(int i=0;i<4;i++)
        {
            dfs(image,row+dx[i],col+dy[i],color,newColor);
        }
            
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]!=color)
        {
            dfs(image,sr,sc,image[sr][sc],color);
        }
        
        return image;
        
    }
};