class Solution {
public:
    int arr[10001];
    bool check(int i,vector<int>& nums){
        if(i==nums.size()-1) return true;
        if(i>=nums.size()) return false;
        if(arr[i]!=-1) return arr[i];

        for(int idx=i+1;idx<=i+nums[i] && idx<nums.size();idx++){
            if(check(idx,nums)) return arr[i]=true;
        }
        return arr[i]=false;
    }
    bool canJump(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        return check(0,nums);
    }
};