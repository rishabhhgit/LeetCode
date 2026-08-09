class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num1=nums[0];
        for(int i=1;i<nums.size();i++){
            num1=num1^nums[i];
        }
        return num1;
    }
};