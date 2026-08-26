class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int prefix=1;
        int suffix=1;
        //prefix
        for(int i=0;i<nums.size();i++){
            prefix*=nums[i];
            maxi=max(maxi,prefix);
            if(nums[i]==0) prefix=1;
        }
        //suffix
        for(int i=nums.size()-1;i>=0;i--){
            suffix*=nums[i];
            maxi=max(maxi,suffix);
            if(nums[i]==0) suffix=1;
        }
        return maxi;
    }
};