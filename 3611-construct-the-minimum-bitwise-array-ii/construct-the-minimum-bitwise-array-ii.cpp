class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int p = nums[i];

            // Even numbers are impossible
            if ((p & 1) == 0) {
                ans[i] = -1;
                continue;
            }

            // Count trailing ones
            int cnt = 0;
            int temp = p;
            while (temp & 1) {
                cnt++;
                temp >>= 1;
            }

            // Minimum x
            ans[i] = p - (1 << (cnt - 1));
        }

        return ans;
    }
};
