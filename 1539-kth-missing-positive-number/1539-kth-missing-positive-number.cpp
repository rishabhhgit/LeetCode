class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int l=0;
        int r=nums.size()-1;
        while(r>=l){
            int mid=l+(r-l)/2;

            if(nums[mid]-(mid+1)<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l+k;
    }
};