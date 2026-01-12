class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowCount;
        
        // Store all rows
        for (int i = 0; i < n; i++) {
            rowCount[grid[i]]++;
        }
        
        int result = 0;
        
        // Compare each column
        for (int col = 0; col < n; col++) {
            vector<int> column;
            for (int row = 0; row < n; row++) {
                column.push_back(grid[row][col]);
            }
            
            if (rowCount.count(column)) {
                result += rowCount[column];
            }
        }
        
        return result;
    }
};
