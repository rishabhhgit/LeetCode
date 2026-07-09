class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        vector<int>result;

        int i=0;
        int j=0;
        int badpairs=0;
        while(j<nums.size()){
            if(j>0 && nums[j]!=1+nums[j-1]) badpairs++;

            while(j-i+1>k){
                if(nums[i+1]!=1+nums[i]){
                    badpairs--;
                }
                i++;
            }
            if(j-i+1==k){
                if(badpairs==0){
                    result.push_back(nums[j]);
                }
                else{
                    result.push_back(-1);
                }
            }
            j++;
        }
        return result;
    }
};