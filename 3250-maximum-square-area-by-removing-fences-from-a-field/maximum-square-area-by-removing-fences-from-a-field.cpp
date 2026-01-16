class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // Add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> widthDiffs;

        // Compute all vertical differences
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                widthDiffs.insert(vFences[j] - vFences[i]);
            }
        }

        long long maxSide = -1;

        // Check horizontal differences against vertical ones
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                long long diff = hFences[j] - hFences[i];
                if (widthDiffs.count(diff)) {
                    maxSide = max(maxSide, diff);
                }
            }
        }

        if (maxSide == -1) return -1;

        return (maxSide * maxSide) % MOD;
    }
};
