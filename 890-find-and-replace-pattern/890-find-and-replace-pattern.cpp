//https://leetcode.com/problems/find-and-replace-pattern/discuss/1221096/Easy-Solutions-w-Explanation-or-Two-Maps-Single-Map-and-Word-Normalization

class Solution {
public:
    
    bool check(string &word, string &pattern)
    {
        map<char,char> mp1,mp2;
        
        for(int i=0;i<word.length();i++)
        {
            if((mp1.count(word[i]) and mp1[word[i]]!=pattern[i]) or (mp2.count(pattern[i]) and mp2[pattern[i]]!=word[i]))
                return false;
            
            mp1[word[i]]=pattern[i];
            mp2[pattern[i]]=word[i];
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        map<char,char> m1,m2;
        
        vector<string> res;
        for(auto i:words)
        {
            string word=i;
            
            if(check(word,pattern))
                res.push_back(word);
        }
        
        return res;
        
    }
};