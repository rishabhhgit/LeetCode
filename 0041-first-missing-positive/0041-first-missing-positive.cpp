class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // First pass: mark numbers that are out of range
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Second pass: use index as a hash key and mark the presence of numbers
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Third pass: find the first cell which isn't negative
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // If all numbers from 1 to n are present, return n + 1
        return n + 1;
    }
};