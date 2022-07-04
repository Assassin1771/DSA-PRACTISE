class Solution 
{
    public String longestPalindrome(String s) 
    {
        if (s == null || s.length() < 1)
            return "";
    
        int start = 0, end = 0;
    
        for (int i = 0; i < s.length(); i++) 
        {
            int len1 = expandAroundCenter(s, i, i); //racecar
            int len2 = expandAroundCenter(s, i, i + 1); // aabbaa
            int len = Math.max(len1, len2);
            
            // System.out.println("A " + len1);
            // System.out.println("B " + len2);
            // System.out.println("C " + len);
            
            //When answer is greater than our set bounds
            //if s=babad, i=0, len1=0,len2=0, thus boundary change required
            if (len > end - start) 
            {
                // System.out.println(i);
                
                start = i - (len - 1) / 2;
                end = i + len / 2;
                
                // System.out.println(start + " " + end);
            }
    }
        
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) 
{
    int L = left, R = right;

    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    
    return R - L - 1;
}
};