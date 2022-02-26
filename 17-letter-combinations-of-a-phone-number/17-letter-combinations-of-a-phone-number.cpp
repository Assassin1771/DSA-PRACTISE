class Solution {
public:
    
    void getCombinations(int ind,int n,string digits, string temp, vector<string> &res,unordered_map<int,string> &mp)
    {
        if(ind==n)
        {
            res.push_back(temp);
            return;
        }
        
        int x=digits[ind]-48;
        string s=mp[x];
        
        for(int i=0;i<s.length();i++)
        {
            temp.push_back(s[i]);
            getCombinations(ind+1,n,digits,temp,res,mp);
            
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        int n=digits.size();
        
        vector<string> res;
        if(n==0)
            return res;
        
        string temp;
        
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        getCombinations(0,n,digits,temp,res,mp);
        
        return res;
        
    }
};