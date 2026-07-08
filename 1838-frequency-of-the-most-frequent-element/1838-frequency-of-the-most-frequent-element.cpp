class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        long long currsum=0;
        int result=0;
        for(int r=0;r<nums.size();r++){
            currsum+=nums[r];

            long long windowSum=nums[r]*1LL*(r-l+1);
            int operationsNeeded= abs(windowSum-currsum);
            
            while (1LL * nums[r] * (r - l + 1) - currsum > k) {
                currsum-=nums[l];
                l++;
            }

            result=max(result,r-l+1);
        }
        return result;
    }
};