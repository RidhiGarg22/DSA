#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        q.push({entrance[0], entrance[1]});
        dist[entrance[0]][entrance[1]] = 0;
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (maze[nr][nc] == '+' || dist[nr][nc] != -1) continue;
                
                dist[nr][nc] = dist[r][c] + 1;
                
                if ((nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) &&
                    !(nr == entrance[0] && nc == entrance[1])) {
                    return dist[nr][nc];
                }
                
                q.push({nr, nc});
            }
        }
        
        return -1;
    }
};
