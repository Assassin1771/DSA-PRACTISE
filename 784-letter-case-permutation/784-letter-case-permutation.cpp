class Solution {
public:
    
    void fun(int ind, string &s, string temp, vector<string> &res)
    {   
        int n=s.length();
        if(ind==n-1)
        {
            if(isalpha(s[ind]))
            {
                if(isupper(s[ind]))
                {
                    temp.push_back(s[ind]);
                    res.push_back(temp);
                    
                    temp.pop_back();
                    temp.push_back(tolower(s[ind]));
                    res.push_back(temp);
                }
                
                else
                {
                    temp.push_back(s[ind]);
                    res.push_back(temp);
                    
                    temp.pop_back();
                    temp.push_back(toupper(s[ind]));
                    res.push_back(temp);
                }
            }
            
            else
            {
                temp.push_back(s[ind]);
                res.push_back(temp);
            }
            
            return;
        }
        
        if(isalpha(s[ind]))
        {
            
            char c=s[ind];
            
            if(isupper(c))
            {   
                // cout<<11<<endl;
                temp.push_back(s[ind]);
                fun(ind+1,s,temp,res);
                
                temp.pop_back();
                c=tolower(c);
                temp.push_back(c);
                
                fun(ind+1,s,temp,res);
            }
            
            else
            {
                // cout<<22<<endl;
                temp.push_back(s[ind]);
                fun(ind+1,s,temp,res);
                
                temp.pop_back();
                c=toupper(c);
                temp.push_back(c);
                
                fun(ind+1,s,temp,res);
            }
        }
        
        else
        {
            temp.push_back(s[ind]);
            fun(ind+1,s,temp,res);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        
        vector<string> res;
        string temp="";
        
        fun(0,s,temp,res);
        
        return res;
        
    }
};