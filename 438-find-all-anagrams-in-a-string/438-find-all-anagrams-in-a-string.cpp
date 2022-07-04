class Solution {
public:
    
    bool isSame(vector<int> a, vector<int> b)
    {
        for(int i=0;i<256;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        int m=s.length();
        int n=p.length();
        
        vector<int> res;
        
        if(n>m)
            return res;
        
        vector<int> a(256), b(256);
        
        for(int i=0;i<n;i++)
        {
            a[s[i]-97]++;
            b[p[i]-97]++;
        }
        
        for(int i=1;i<m-n+1;i++)
        {
            if(isSame(a,b))
                res.push_back(i-1);
            
            a[s[i+n-1]-97]++;
            a[s[i-1]-97]--;
        }
        
        if(isSame(a,b))
            res.push_back(m-n);
        
        return res;
        
    }
};