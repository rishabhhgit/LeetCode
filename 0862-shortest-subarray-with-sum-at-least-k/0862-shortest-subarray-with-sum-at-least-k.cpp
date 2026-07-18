class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>cumulativeSum(nums.size());

        int j=0;
        int minSize=1e9;
        while(j<nums.size()){
            if(j==0) cumulativeSum[j]=nums[j];
            else cumulativeSum[j]=cumulativeSum[j-1]+nums[j];
            if(cumulativeSum[j]>=k){
                minSize=min(minSize,j+1);
            }
            while(!dq.empty() && cumulativeSum[j]-cumulativeSum[dq.front()]>=k){
                minSize=min(minSize,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cumulativeSum[dq.back()]>=cumulativeSum[j]) dq.pop_back();
            dq.push_back(j);
            j++;
        }
        if(minSize==1e9) return -1;
        return minSize;
    }
};