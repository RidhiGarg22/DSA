class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> pairs;

        // Pair nums2 with nums1
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }

        // Sort by nums2 descending
        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, ans = 0;

        for (auto &[minVal, val] : pairs) {
            minHeap.push(val);
            sum += val;

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                ans = max(ans, sum * minVal);
            }
        }

        return ans;
    }
};
