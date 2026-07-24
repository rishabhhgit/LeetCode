class Solution {
public:
    vector<vector<int>> result;
    void check(int idx,vector<int>& nums){
        if(idx==nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            check(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        check(0,nums);
        return result;
    }
};