class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        
        int n=v.size();
        
        if(n==1)
            return v[0];
        
        string temp="";
        if(n==0)
            return temp;
        
        sort(v.begin(),v.end());
        
        string res;
        int i=0;
        
        int a=v[0].length();
        int b=v[1].length();
        
        while(a and b)
        {
            string s=v[0];
            string s1=v[n-1];
            
            if(s[i]==s1[i])
                res.push_back(s[i]);
            
            else
                return res;
            
            i++;
            a--;
            b--;
        }
        
        return res;
        
    }
};