class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size(),1);
        int n=nums.size();

        int leftVal=1;
        for(int i=0;i<n;i++){
            result[i]*=leftVal;
            leftVal*=nums[i];
        }
        int rightVal=1;
        for(int i=n-1;i>=0;i--){
            result[i]*=rightVal;
            rightVal*=nums[i];
        }
        return result;
    }
};