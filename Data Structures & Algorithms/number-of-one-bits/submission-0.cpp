class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int ones = 0;
        while(n > 0)
        {
            if(n % 2 == 1) ones++;
            n=n/2;
        }
        return ones;
    }
};
