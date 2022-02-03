class Solution {
public:
    
    int minMoves(int t, int d) {
        
        int count=0;    
        while(d>0 and t>1)
        {
            if(t%2==0)
            {
                t=t/2;
                count++;
                d--;
            }
            
            else
            {
                t--;
                count++;
            }
        }
        
        count+=(t-1);
        return count;
            
        
    }
};