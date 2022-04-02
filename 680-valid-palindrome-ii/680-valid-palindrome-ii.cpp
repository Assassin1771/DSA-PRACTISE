class Solution {
public:
    
    bool check(int l,int h, int x, string &s)
    {
        if(l>=h)
            return true;
        
        if(s[l]==s[h])
        {   
            return check(l+1,h-1,x,s);
        }
        
        else
        {
            if(x)
            {
                x--;
                
                return (check(l+1,h,x,s) or check(l,h-1,x,s));
            }
            
            else
            {
                return false;
            }
                
        }
        
        return false;
    }
    
    bool validPalindrome(string s) {
        
        int n=s.length();
        
        int x=1;
        
        return check(0,n-1,1,s);        
    }
};