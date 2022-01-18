class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        vector<int> v(26);
        
        for(int i=0;i<allowed.length();i++)
        {
            char c=allowed[i];
            int x=(int)c;
            
            x-=97;
            v[x]++;
        }
        
        int res=0;
        
        bool flag=true;
        for(int i=0;i<words.size();i++)
        {   
            string s=words[i];
            for(int j=0;j<s.length();j++)
            {
                char c=s[j];
                int x=(int)c;
                
                x-=97;
                if(v[x]!=1)
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag==true)
                res++;
            
            flag=true;   
        }
        
        return res;
        
    }
};