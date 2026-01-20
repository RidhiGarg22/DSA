class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++) {
            int p = nums[i];

            
            if (p == 2) continue;

            
            for (int x = 0; x <= p; x++) {
                if ((x | (x + 1)) == p) {
                    ans[i] = x;
                    break;
                }
            }
        }
        return ans;
    }
};
