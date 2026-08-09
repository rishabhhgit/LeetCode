class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        int prev=INT_MIN;
        int k=3;
        if(nums.size()==1) return nums[0];
        int ans=nums[nums.size()-1];
        while(i>=0){
            if(nums[i]!=prev){
                k--;
                prev=nums[i];
            }
            if(k==0){
                ans=nums[i];
                break;
            }
            i--;
        }
        return ans;
    }
};