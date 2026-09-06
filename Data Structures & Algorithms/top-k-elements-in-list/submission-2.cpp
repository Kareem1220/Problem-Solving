class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> mp;
        vector<int> ans; 
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), 
        [](auto& a, auto& b) 
        {
            return a.second > b.second; 
        });
        int j = 0;
        for(auto& p : v)
        {
            if(j == k) break; 
            ans.push_back(p.first);
            j++;
        }
        return ans; 
    }
};
