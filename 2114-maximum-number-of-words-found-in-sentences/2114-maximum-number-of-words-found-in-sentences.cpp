class Solution {
public:
    
    int count(string s)
    {
        int n=s.length();
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                res++;
            }
        }
        
        res++;
        return res;
    }
    
    int mostWordsFound(vector<string>& sentences) {
        
        int n=sentences.size();
        
        int maxx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            string s=sentences[i];
            maxx=max(maxx,count(s));
        }
        
        return maxx;
        
    }
};