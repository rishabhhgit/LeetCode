class Solution {
public:
    int arr[100001][2][2];
    int solve(int i,vector<int>& nums,pair<bool,bool>check){
        if(i>=nums.size()) return 0;
        
        int buy=0;
        int sell=0;
        bool canBuy=check.first;
        bool sellAvailable=check.second;

        if(arr[i][canBuy][sellAvailable]!=-1) return arr[i][canBuy][sellAvailable];

        int skip=solve(i+1,nums,{canBuy,sellAvailable});
        if(canBuy){
            buy=solve(i+1,nums,{false,true})-nums[i];
        }
        if(sellAvailable){
            sell=solve(i+1,nums,{false,false})+nums[i];
        }
        return arr[i][canBuy][sellAvailable]=max(skip,max(buy,sell));
    }
    int maxProfit(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        return solve(0,nums,{true,false});
    }
};