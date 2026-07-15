class Solution {
public:
    typedef long long ll;
    bool check(ll mid, vector<int>& nums,ll n){
        ll sum=0;
        ll target=n*mid;

        for(ll i=0;i<nums.size();i++){
            sum+=min((ll)nums[i],mid);
            if(sum>=target) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& nums) {
        ll i=*min_element(nums.begin(),nums.end());
        ll j=accumulate(nums.begin(),nums.end(),0LL);
        ll ans=-1;
        while(j>=i){
            ll mid=i+(j-i)/2;          

            if(check(mid,nums,n)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};