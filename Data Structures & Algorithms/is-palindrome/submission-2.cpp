class Solution {
public:
    bool isPalindrome(string s) 
    {
        int j = (int)s.size() - 1; 
        int i = 0;
        while(i<j)
        {
            if((s[i] < 48) || 
                (s[i] > 57 && s[i] < 65) || 
                (s[i] > 90 && s[i] < 97) || 
                (s[i] > 122))
            {
                i++;
                continue;
            }
            if((s[j] < 48) || 
                (s[j] > 57 && s[j] < 65) || 
                (s[j] > 90 && s[j] < 97) || 
                (s[j] > 122))
            {
                j--;
                continue;
            }
            if(s[i] >= 65 && s[i] <= 90)
            {
                s[i] += 32; 
            }
            if(s[j] >= 65 && s[j] <= 90)
            {
                s[j] += 32; 
            }

            if(s[i] != s[j]) return false;
            j--;
            i++;
        }
        return true;
        
    }
};
