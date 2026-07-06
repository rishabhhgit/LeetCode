class Solution {
public:
    vector<int> curr;
    vector<int> best;

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>prev_idx(nums.size(),-1);
        vector<int>dp(nums.size(),1);
        int max_length=1;
        int last_max_idx=0;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev_idx[i]=j;
                        
                    }
                    if(dp[i]>max_length){
                        max_length=dp[i];
                        last_max_idx=i;
                    }
                }
            }
        }
        vector<int>result;
        while( last_max_idx!=-1){
            result.push_back(nums[last_max_idx]);
            last_max_idx=prev_idx[last_max_idx];
        }
        return result;
    }
};