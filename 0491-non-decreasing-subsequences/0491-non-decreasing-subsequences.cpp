class Solution {
public:
    vector<int>ans;
    vector<vector<int>>result;
    void solve(vector<int>& nums,int idx){
        set<int>s;
        if(ans.size()>=2) result.push_back(ans);
        
        for(int i=idx;i<nums.size();i++){
            if( (ans.empty() || nums[i]>=ans.back() )&& s.find(nums[i])==s.end()){
                ans.push_back(nums[i]);
                s.insert(nums[i]);
                solve(nums,i+1);
                ans.pop_back();
            }
            
        }
            
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,0);
        return result;
    }
};