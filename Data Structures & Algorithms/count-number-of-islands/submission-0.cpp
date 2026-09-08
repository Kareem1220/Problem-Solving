class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = { {-1, 0} , {1, 0} , {0, -1} , {0, 1} };
        int islandNum = 0;
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(grid[r][c] == '1' && !visited[r][c])
                {
                    islandNum++;
                    visited[r][c] = true;
                    q.push({r, c});
                    while (!q.empty())
                    {
                        auto [currRow, currCol] = q.front();
                        q.pop();
                        for(auto [dr, dc] : directions)
                        {
                            int newRow = currRow + dr;
                            int newCol = currCol + dc;
                            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;
                            if (grid[newRow][newCol] == '1' && !visited[newRow][newCol])
                            {
                                visited[newRow][newCol] = true;
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
        return islandNum;
    }
};