class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_sum = 0, l = 0, r = nums.size() - 1;
        while(l < r) {
            max_sum = fmax(max_sum, nums[l++] + nums[r--]);
        }
        return max_sum;
    }
};