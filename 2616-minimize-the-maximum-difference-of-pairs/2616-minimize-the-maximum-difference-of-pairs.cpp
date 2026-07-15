class Solution {
public:
    int n;
    bool check(int mid,vector<int>& nums, int p){
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(i+1<n && nums[i+1]-nums[i]<=mid){
                count++;
                i+=2;
            }
            else i++;
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        n=nums.size();

        int i=0;
        int j=nums[n-1]-nums[0];
        int ans=-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            if(check(mid,nums,p)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};