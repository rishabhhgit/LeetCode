class Solution {
public:
    typedef long long ll;
    ll check(ll mid,vector<int>& nums, vector<int>& cost){
        ll count=0;
        for(int i=0;i<nums.size();i++){
            count+=abs(nums[i]-mid)*cost[i];
        }
        return count;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll i=*min_element(nums.begin(),nums.end());
        ll j=*max_element(nums.begin(),nums.end());
        ll ans=1e17;
        while(j>=i){
            ll mid=i+(j-i)/2;
            ll x=check(mid,nums,cost);
            ll y=check(mid+1,nums,cost);
            if(x>y){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
            ans=min({ans,x,y});
        }
        return ans;
    }
};