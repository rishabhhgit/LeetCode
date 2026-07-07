class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum=0;
        int rsum=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            lsum+=nums[i];
        }
        maxi=lsum;
        int p=nums.size()-1;
        int j=k-1;
        while(k--){

            lsum-=nums[j--];
            rsum+=nums[p--];
            maxi=max(maxi,lsum+rsum);
        }
        return maxi;
    }
};