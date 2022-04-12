class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        vector<string> s1;
        string temp="";
        
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(temp.size())
                {
                    string temp1=temp;
                    reverse(temp1.begin(),temp1.end());
                    
                    // s1.push_back(temp1);
                    
                    res+=(temp1);
                    res.push_back(' ');
                }
                
                temp.clear();
            }
            
            else
            {
                temp.push_back(s[i]);
            }
                
        }
        
        if(temp.size())
        {
            string temp1=temp;
            reverse(temp1.begin(),temp1.end());
            
            res+=(temp1);
        }
        if(res.back() == ' ') res.pop_back();
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};