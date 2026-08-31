class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<string , vector<string>> mp;
        for(int i = 0; i< strs.size() ; i++)
        {
            string originalword = strs[i];
            string sortedkey = originalword; 
            sort(sortedkey.begin(), sortedkey.end());
            mp[sortedkey].push_back(originalword);
        }

        std::vector<vector<string>> result; 
        for(const auto& [key, pack] : mp)
        {
            result.push_back(pack);
        }

        return result; 

    
    }
};
