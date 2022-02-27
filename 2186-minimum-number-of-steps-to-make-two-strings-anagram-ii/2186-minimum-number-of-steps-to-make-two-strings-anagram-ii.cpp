class Solution {
public:
    int minSteps(string s, string t) {
        
        int m=s.length();
        int n=t.length();
        
        int res=0;
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        vector<int> a(26);
        vector<int> b(26);
        
        for(int i=0;i<m;i++)
        {
            int x=s[i];
            x-=97;
            
            a[x]++;
        }
        
        for(int i=0;i<n;i++)
        {
            int x=t[i];
            x-=97;
            
            b[x]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                res+=abs(a[i]-b[i]);
            }
        }
        
        return res;
        
    }
};