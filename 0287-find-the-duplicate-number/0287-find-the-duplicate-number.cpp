class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long l=0;
        long long r=nums.size()-1;
        // 1 2 2 3 4
        while(r>=l){
            long long mid=l+(r-l)/2;
            if(nums[mid]<=mid) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};