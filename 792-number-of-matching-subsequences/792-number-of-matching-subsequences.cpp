class Solution {
public:
    
    int check(string s, string word)
    {
        int m=s.length();
        int n=word.length();
        
        int i=0,j=0;
        while(i<m and j<n)
        {
            if(s[i]==word[j])
                j++;
            
            i++;
        }
        
        if(j==n)
            return 1;
        
        return 0;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=words.size();
        sort(words.begin(),words.end());
        
        map<string,int> mp;
        for(auto i:words)
            mp[i]++;
    
        int res=0;
        for(auto [x,y]:mp)
        {   
            res+=(check(s,x))*(y);
        }
        
        return res;
        
    }
};