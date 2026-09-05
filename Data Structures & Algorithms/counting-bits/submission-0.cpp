class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> sol;
        while(n >= 0)
        {
            int ones = 0;
            int temp = n;
            while(temp > 0)
            {
                if(temp % 2 != 0) ones++;
                temp/=2;
            }
            sol.insert(sol.begin(),ones);
            n--;
        }
        return sol;
    }
};
