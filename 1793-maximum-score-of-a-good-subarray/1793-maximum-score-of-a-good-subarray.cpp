class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;
        int j=k;
        int mini=nums[k];
        int ans=nums[k];

        while(i>0 && j<nums.size()-1){
            if(nums[i-1]<nums[j+1]){
                j++;
                mini=min(mini,nums[j]);
                ans=max(ans,mini*(j-i+1));
            }
            else{
                i--;
                mini=min(mini,nums[i]);
                ans=max(ans,mini*(j-i+1));
            }
        }
        while(i>0){
            i--;
            mini=min(mini,nums[i]);
            ans=max(ans,mini*(j-i+1));
        }
        while(j<nums.size()-1){
            j++;
            mini=min(mini,nums[j]);
            ans=max(ans,mini*(j-i+1));
        }
        return ans;
    }
};