class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

        sort(points.begin(), points.end());

        int ans = 1;
        int curr = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= curr) {
                curr = min(curr,points[i][1]);
            }
            else {
                ans++;
                curr = points[i][1];
            }
        }
        return ans;
    }
};