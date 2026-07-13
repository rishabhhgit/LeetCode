class Solution {
public:
    
    bool check(double mid,vector<int>& nums, double hour){
        double ans=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            ans+=ceil(nums[i]/mid);
        }
        ans+=(double)nums[n-1]/mid;
        return ans<=hour;
    }
    int minSpeedOnTime(vector<int>& nums, double hour) {
        int i=1;
        int j=1e7;
        int ans=-1;
        while(j>=i){
            int mid=i+(j-i)/2;

            if(check(mid,nums,hour)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        if(ans==-1) return -1;
        return ans;
    }
};