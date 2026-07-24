class Solution {
public:
    vector<vector<int>>result;
    unordered_set<int>s;
    void check(vector<int>& nums,vector<int>&ans){
        if(ans.size()==nums.size()){
            result.push_back(ans);
            return;
        }
        
        for(int j=0;j<nums.size();j++){
           if(s.find(nums[j])==s.end()){
                ans.push_back(nums[j]);
                s.insert(nums[j]);
                check(nums,ans);
                ans.pop_back();
                s.erase(nums[j]);
            }
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        check(nums,ans);
        return result;
    }
};