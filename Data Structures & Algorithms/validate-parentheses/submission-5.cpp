class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size() > 1)
        {
            std::stack<char> t; 
            char temp;
            for(int i = 0 ; i < s.size() ; i++)
            {
                if(s[i] == '(' ||
                   s[i] == '[' ||
                   s[i] == '{')
                {
                    t.push(s[i]);
                }

                if(s[i] == ')') 
                {
                    if(!t.empty()) temp = t.top();
                    if(temp != '(' || t.empty() ) return false; 
                    t.pop(); 
                }
                if(s[i] == ']') 
                {
                    if(!t.empty()) temp = t.top();
                    if(temp != '[' || t.empty() ) return false; 
                    t.pop(); 
                }
                if(s[i] == '}') 
                {
                    if(!t.empty()) temp = t.top();
                    if(temp != '{' || t.empty() ) return false; 
                    t.pop(); 
                }
            }
            if(t.empty()) return true;

        }
        return false; 
    }
};
