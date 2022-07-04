class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        if(m>n)
            return false;
        
        vector<int> a(26),b(26);
        
        for(int i=0;i<m;i++)
        {
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }    
        
        for(int i=1;i<n-m+1;i++)
        {
            if(a==b)
                return true;
            
            b[s2[i-1]-'a']--;
            b[s2[i+m-1]-'a']++;
        }
        
        if(a==b)
            return true;
        
        return false;
        
    }
};