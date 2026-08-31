class Solution {
public:
    bool isAnagram(string s, string t) {
       if(t.size() != s.size() ) return false;
       std::unordered_map<char , int> mp; 
       
       for( int i =0 ; i < s.size() ; i++ ){
        mp[s[i]]++;
        mp[t[i]]--;
       }
        for(const auto& [letter , count]  : mp){
          if(count != 0) return false; 

        }
        return true;
    }
};
