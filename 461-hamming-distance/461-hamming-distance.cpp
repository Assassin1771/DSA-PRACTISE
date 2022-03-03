class Solution {
public:
    
    void getBinary(int n, vector<int> &v)
    {
        int i=0;
        while(n>0)
        {
            v[i]=n%2;
            n=n/2;
            i++;
        }
        
        reverse(v.begin(),v.end());
            
    }
    
    int hammingDistance(int x, int y) {
        
        vector<int> v(32),v1(32);
        
        getBinary(x,v);
        getBinary(y,v1);
        
        int res=0;
        for(int i=0;i<32;i++)
            if(v[i]!=v1[i])
                res++;
        
        return res;
        
        
    }
};