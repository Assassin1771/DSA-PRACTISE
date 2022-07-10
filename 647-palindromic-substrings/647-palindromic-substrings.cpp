// https://leetcode.com/problems/palindromic-substrings/discuss/1129589/Palindromic-Substrings-or-Short-and-Easy-w-Explanation-or-Beats-100 (EXPAND FROM CENTRE)


class Solution {
public:
    
    bool isPal(string temp)
    {
        int low=0, high=temp.length()-1;
        
        while(low<=high)
        {
            if(temp[low]!=temp[high])
                return false;   
            
            low++;
            high--;
        }
        
        return true;
    }
    
    int countSubstrings(string s) {
        
        int n=s.length();
        int res=0;
        
        string temp="";
        for(int i=0;i<n;i++)
        {
            temp.push_back(s[i]);
            
            if(isPal(temp))
                res++;
            
            for(int j=i+1;j<n;j++)
            {
                temp.push_back(s[j]);
                
                if(isPal(temp))
                    res++;
            }
            
            temp.clear();
        }
        
        return res;
        
    }
};