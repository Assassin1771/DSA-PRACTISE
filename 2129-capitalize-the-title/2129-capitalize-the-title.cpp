class Solution {
public:
    string capitalizeTitle(string s) {
        
        int n=s.length();
        vector<string> res;
        
        string temp;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                res.push_back(temp);
                temp="";
            }
            
            else
            {
                temp.push_back(s[i]);
            }
        }
        
        res.push_back(temp);
        
        for(int i=0;i<res.size();i++)
        {
            string s1=res[i];
            for(int i=0;i<s1.length();i++)
            {
                s1[i]=tolower(s1[i]);
            }
            
            if(s1.length()>2)
            s1[0]=toupper(s1[0]);
            
            res[i]=s1;
        }
        
        string final;
        for(auto i:res)
        {
            final+=i;
            final.push_back(' ');
        }
        
        final.pop_back();
        return final;
        
        
        
    }
};