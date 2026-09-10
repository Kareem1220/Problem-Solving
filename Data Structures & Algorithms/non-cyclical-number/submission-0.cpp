class Solution { 
public: 
    bool isHappy(int n)  
    {  
        unordered_set<int> st; 
        while (n != 1)
        {
            if (st.contains(n))return false;

            st.insert(n);
            n = sumSquare(n);
        }
        return true;
    } 
    int sumSquare(int n) 
    { 
        int sum = 0; 
        while(n != 0) 
        { 
            int digit = n % 10; 
            n = n / 10; 
            sum = sum + (digit * digit); 
        } 
        return sum; 
    } 
};