class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        std::stack<string> s; 
        int minOp = 0;
        for(int i = 0 ; i < logs.size() ; i++)
        {
            string temp = logs[i];
            if(temp.starts_with("..")) 
            {
                if(!s.empty()) 
                {
                    s.pop();
                    minOp--;
                }
            }
            else if(temp.starts_with(".")) continue;
            else 
            {
                s.push(logs[i]);
                minOp++;
            }
        }
        return minOp;
    }
};