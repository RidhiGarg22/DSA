class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 1e18, high = -1e18;

        // Compute total area and bounds for binary search
        for (auto& s : squares) {
            double y = s[1], l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        // Binary search for y-coordinate
        for (int iter = 0; iter < 80; iter++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0;

            for (auto& s : squares) {
                double y = s[1], l = s[2];
                if (mid <= y) continue;
                else if (mid >= y + l)
                    areaBelow += l * l;
                else
                    areaBelow += (mid - y) * l;
            }

            if (areaBelow < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
