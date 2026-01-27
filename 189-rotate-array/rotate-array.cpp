class Solution {
public:
    void rever(vector<int>& nums, int start, int end){
        while (start<end){
            swap(nums[start], nums[end]);
            start+=1;
            end -= 1;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();

        k = k % length;
        if (k==0) return;

        int someMid = nums.size()-k;

        rever(nums, 0, someMid-1);
        rever(nums, someMid, length-1);
        rever(nums, 0, length-1);
    }
};