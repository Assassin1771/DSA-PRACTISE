// Since there are only 26 * 26 * 1 distinct palindromes with length 3, we can iterate through all of the palindromes and check if the palindrome is a subsequence of the given string.
// O(26 * 26 * N) -> O(N)

bool sub(string &pattern, string &text)
{
    int i, j;
    for(i = 0, j = 0; i < text.size() && j < 3; ++i) 
    {
        if(text[i] == pattern[j])
            ++j;
    }
    
    return j == 3;
}

class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int ans = 0;
        for(char a = 'a'; a <= 'z'; a++) 
        {
            for(char b = 'a'; b <= 'z'; b++) 
            {
                string str;
                
                str += a;
                str += b;
                str += a;
                
                ans += sub(str, s);
            }
        }
        
        return ans;
    }
};