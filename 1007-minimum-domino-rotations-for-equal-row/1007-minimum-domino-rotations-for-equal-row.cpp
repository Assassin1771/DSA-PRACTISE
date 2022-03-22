class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n=tops.size();
        
        map<int,int> mp,mp1;
        for(int i=0;i<n;i++)
        {
            mp[tops[i]]++;
            mp1[bottoms[i]]++;
        }
        
        int a=-1,b=-1,c,d;
        
        for(auto [x,y]:mp)
        {
            if(y>b)
            {
                a=x;
                b=y;
            }
        }
        
        for(auto [x,y]:mp1)
        {
            if(y>b)
            {
                c=x;
                d=y;
            }
        }
        
        int res=0;
        if(b>d)
        {
            for(int i=0;i<n;i++)
            {
                if(tops[i]!=a and bottoms[i]==a)
                {
                    swap(tops[i],bottoms[i]);
                    res++;
                }
            }
            
            for(int i=0;i<n;i++)
            {
                if(tops[i]!=a)
                    return -1;
            }
            
            return res;
    
        }
        
        else
        {
            for(int i=0;i<n;i++)
            {
                if(bottoms[i]!=c)
                {
                    swap(tops[i],bottoms[i]);
                    res++;
                }
            }
            
            for(int i=0;i<n;i++)
            {
                if(bottoms[i]!=c)
                    return -1;
            }
            
            return res;
        }
        
        return 0;
        
        
        
        
        
        
    }
};