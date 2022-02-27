class Solution {
public:
    int minSteps(string s, string t) {
        
        int n=s.length();
        int res=0;
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        cout<<s<<endl<<t<<endl;
        
        vector<int> a(26);
        vector<int> b(26);
        
        for(int i=0;i<n;i++)
        {
            int x=s[i];
            x-=97;
            
            a[x]++;
            
            int y=t[i];
            y-=97;
            
            b[y]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                res+=abs(a[i]-b[i]);
            }
        }
        
        return res/2;
        
    }
};