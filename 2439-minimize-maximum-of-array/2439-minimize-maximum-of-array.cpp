class Solution {
public:
    bool check(vector<int>&nums,long long expectedMax){
        vector<long long>num(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(num[i]>expectedMax) return false;

            long long buffer=(expectedMax-num[i])*1LL;
            num[i+1]=(num[i+1]-buffer)*1LL;
        }
        return num[n-1]<=expectedMax;
    }
    int minimizeArrayValue(vector<int>& nums) {
        long long maxi=*max_element(nums.begin(),nums.end());

        int l=1;
        long long r=maxi;
        int ans=0;

        while(r>=l){
            long long mid=l+(r-l)/2;

            if(check(nums,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};