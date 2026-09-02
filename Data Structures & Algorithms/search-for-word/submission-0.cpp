class Solution {
public:
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) 
    {
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        int index = 0;
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size() ; j++)
            {
                if(backtrack(i,j,board,word,index)) return true;
            }
        }
        return false;
       
    }
    bool backtrack(int row,int column,vector<vector<char>>& board , string word, int index)
    {
        if(index == word.size()) return true;
        if(row < 0 || row >= board.size() || column < 0 || column >= board[0].size()) return false;
        if(index > word.size()) return false;
        if(visited[row][column]) return false; 
        if(board[row][column] != word[index]) return false;
    
        visited[row][column] = true;
        index++;
        bool found = backtrack(row + 1 , column , board , word, index) ||
        backtrack(row , column + 1 , board , word, index) ||
        backtrack(row - 1 , column , board , word, index) ||
        backtrack(row , column - 1 , board , word, index);
        visited[row][column] = false;
        return found;
    }
};
