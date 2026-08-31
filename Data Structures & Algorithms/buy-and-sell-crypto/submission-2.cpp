class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        
        int bestvalue = 0;
        int buy = 0;
        int sell = buy + 1;
        while(sell < prices.size())
        {
            if(prices[buy] > prices[sell])
            {
                buy = sell;
            }
            else
            {
                if(prices[sell] - prices[buy] > bestvalue) bestvalue =prices[sell] - prices[buy];
            }   
            sell++;    
        }
        return bestvalue;
    }
};
