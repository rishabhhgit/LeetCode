
class Solution {
public:
    map<pair<int,int>,int>arr;
    int solve(int i, vector<int>& range, int n, int maxEnd) {
        if (i >= range.size()) {
            if(maxEnd>=n) return 0;
            else return 1e9;
        }

        if (i > maxEnd) return 1e9;
        if(arr.find({i,maxEnd})!=arr.end()) return arr[{i,maxEnd}];
        int skip = solve(i + 1, range, n, maxEnd);
        int take = solve(i + 1, range, n, max(maxEnd, range[i])) + 1;
        return arr[{i,maxEnd}]=min(skip, take);
    }
    int minTaps(int n, vector<int>& nums) {
        vector<int>range(n+1,0);
        for(int i=0;i<nums.size();i++){
            int lowerRange=max(0,i-nums[i]);
            int upperRange=min(n,i+nums[i]);

            range[lowerRange]=max(range[lowerRange],upperRange);
        }
        int ans=solve(0, range, n, 0);
        if(ans==1e9) return -1;
        return ans;
    }
};