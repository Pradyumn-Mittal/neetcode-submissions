class Solution {
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() ||
        j < 0 || j >= grid[0].size()) 
        return 1;

        if (grid[i][j] == 0) {
        return 1;
        }

        // Already visited land
        if (grid[i][j] == -1) {
            return 0;
        }

        // Mark visited
        grid[i][j] = -1;

        int perimeter = 0;

        perimeter += dfs(i + 1, j, grid);
        perimeter += dfs(i - 1, j, grid);
        perimeter += dfs(i, j + 1, grid);
        perimeter += dfs(i, j - 1, grid);

        return perimeter;
    }
public:
     int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, grid);
                }
            }
        }

        return 0;
    }
};