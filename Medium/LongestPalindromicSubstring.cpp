class Solution {
public:
    string longestPalindrome(string s) {
        int ssStart = 0, ssLen = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            int l1 = expandAroundCenter(s, i, i);
            int l2 = expandAroundCenter(s, i, i+1);
            int len = max(l1,l2);
            if (len > ssLen)
            {
                ssStart = i - (len - 1) / 2;
                ssLen = len;
            }
        }
        return s.substr(ssStart, ssLen);
    }
    
    int expandAroundCenter(string s, int left, int right)
    {
        int R = right, L = left;
        while(L >= 0 && R < s.length() && s.at(L) == s.at(R))
        {
            R++;
            L--;
        }
        return R - L - 1;
    }
};