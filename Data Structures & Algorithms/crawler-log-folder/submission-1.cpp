class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int minOp = 0;
        for(int i = 0 ; i < logs.size() ; i++)
        {
            string temp = logs[i];
            if(temp.starts_with("..") && minOp > 0) minOp--;
            else if(temp.starts_with(".")) continue;
            else minOp++;
        }
        return minOp;
    }
};