class Solution {
public:
    bool isPalindrome(string s) {
        
        int n=s.length();
        string res;
        
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(isalnum(c))
            {   
                c=tolower(c);
                res.push_back(c);    
            }
        }
        
        // cout<<res<<endl;
        string res1=res;
        reverse(res1.begin(),res1.end());
        
        // cout<<res<<endl;
        return (res==res1);
        
    }
};