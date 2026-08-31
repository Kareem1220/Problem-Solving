class Solution {
public:

    string encode(vector<string>& strs) 
    {
        std::string s;
        int length;
        for(int i = 0 ; i < strs.size() ; i++)
        {
            length = strs[i].size();
            s+= std::to_string(length);
            s += '#';
            s+=strs[i];
        }
        return s;
    }
    vector<string> decode(string s) 
    {

        int length,digits;
        vector<std::string> ans; 
        std::string temp;
        for(int j = 0 ; j < s.size() ;)
        {
            temp.clear();
            if(std::isdigit(s[j]))
            {
                length = std::stoi(s.substr(j));
            }
            digits = (length == 0) ? 1 : std::floor(std::log10(length)) + 1 ;
            j+=digits+1;
            while(length > 0)
            {
                temp += s[j];
                length--;
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
