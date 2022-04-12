class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        vector<string> s1;
        string temp="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(temp.size())
                s1.push_back(temp);
                
                temp.clear();
            }
            
            else
            {
                temp.push_back(s[i]);
            }
                
        }
        
        if(temp.size())
        s1.push_back(temp);
        
        // for(int i=0;i<s1.size();i++)
        // {
        //     cout<<i<<" "<<s1[i]<<endl;
        // }
        
        string res="";
        for(int i=s1.size()-1;i>=0;i--)
        {
            res+=s1[i];
            res.push_back(' ');
        }
        
        res.pop_back();
        
        return res;
        
    }
};