class Solution {
public:
    
    bool check(string s)
    {
        int l=0,h=s.length()-1;
        
        while(l<=h)
        {
            if(s[l]!=s[h])
                return false;
            
            l++;
            h--;
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        
        int n=words.size();
        
        string res;
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            
            if(check(s))
            {
                res=s;
                break;
            }
        }
        
        return res;
        
    }
};