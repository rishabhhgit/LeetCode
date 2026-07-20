class Solution {
public:
    int arr[501][501];
    int check(int i,vector<int>& nums,int time){
        if(i>=nums.size()) return 0;

        if(arr[i][time]!=-1) return arr[i][time];
        int skip=check(i+1,nums,time);
        int take=nums[i]*time+check(i+1,nums,time+1);

        return arr[i][time]=max(skip,take);
    }
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(arr,-1,sizeof(arr));
        return check(0,nums,1);
    }
};