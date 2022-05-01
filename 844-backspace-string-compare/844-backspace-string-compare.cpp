class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string temp1="",temp2="";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#')
                temp1.push_back(s[i]);
            
            else
            {
                if(temp1.size())
                    temp1.pop_back();
            }
        }
        
        for(int i=0;i<t.length();i++)
        {
            
            if(t[i]!='#')
                temp2.push_back(t[i]);
            
            else
            {
                if(temp2.size())
                    temp2.pop_back();    
            }
                
        }
        
        // cout<<temp1<<endl<<temp2<<endl;
        
        return (temp1==temp2?1:0);
        
    }
};