class Solution {
public:
    typedef pair<int,int> p;
    long long continuousSubarrays(vector<int>& nums) {
        priority_queue<p>maxHeap;
        priority_queue<p,vector<p>,greater<p>>minHeap;

        long long i=0;
        long long j=0;
        long long n=nums.size();
        long long ans=0;

        while(j<n){
            minHeap.push({nums[j],j});
            maxHeap.push({nums[j],j});

            while(true){
                while(!minHeap.empty() && minHeap.top().second<i){
                    minHeap.pop();
                }
                while(!maxHeap.empty() && maxHeap.top().second<i){
                    maxHeap.pop();
                }
                if(!maxHeap.empty() && !minHeap.empty() && abs(maxHeap.top().first-minHeap.top().first)<=2){
                    break;
                }
                i++;
            }

            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};