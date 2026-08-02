class Solution {
public:
    int maxProfit(vector<int>& nums) {
        long long minPrice=INT_MAX;
        long long maxProfit=0;

        for(int i=0;i<nums.size();i++){
            minPrice=min(minPrice,(long long)nums[i]);
            maxProfit=max(maxProfit,nums[i]-minPrice);
        }
        return maxProfit;
    }
};