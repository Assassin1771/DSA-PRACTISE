class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n,vector<int> (n,-1));
        
        int count=1;
        
        int direction=1;
        int left=0, right=n-1, top=0, bottom=n-1;
        
        while(left<=right and top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++)
                {
                    res[top][i]=count;
                    count++;
                }
                
                direction=2;
                top++;
            }
            
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++)
                {
                    res[i][right]=count;
                    count++;
                }
                
                direction=3;
                right--;
            }
            
            else if(direction==3)
            {
                for(int i=right;i>=left;i--)
                {
                    res[bottom][i]=count;
                    count++;
                }
                
                direction=4;
                bottom--;
            }
            
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res[i][left]=count;
                    count++;
                }
                
                direction=1;
                left++;
            }
        }
        
        
        return res;
        
        
        
    }
};