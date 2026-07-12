class Solution {
public:
    bool check(vector<int>& nums,long long mid,long long x){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=(mid/nums[i])*1LL;
        }
        return count>=x;
    }
    long long minimumTime(vector<int>& nums, int x) {
        long long mini=*min_element(nums.begin(),nums.end());
        long long l=1;
        long long r=x*mini;
        long long ans=0;
        while(r>=l){
            long long mid=l+(r-l)/2;

            if(check(nums,mid,x)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};