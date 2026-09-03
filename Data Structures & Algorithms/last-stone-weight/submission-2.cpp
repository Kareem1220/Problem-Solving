class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> maxheap; 
        for(int i = 0 ; i < stones.size() ; i++) maxheap.push(stones[i]);
        while(!maxheap.empty())
        {
           int k1 = maxheap.top();
           maxheap.pop();
           if(maxheap.empty()) return k1;
           int k2 = maxheap.top();
           maxheap.pop();
           if(k1 != k2) maxheap.push((k1-k2));
        }
        return 0;
    }
};
