class Solution {
public:
    typedef pair<int,int>p;
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<p,vector<p>,greater<p>>min_heap;
        priority_queue<p>max_heap;
        int l=0;
        int r=0;

        int result=1;
        while(r<nums.size()){
            min_heap.push({nums[r],r});
            max_heap.push({nums[r],r});

            while(true){
                while(!min_heap.empty() && min_heap.top().second<l){
                    min_heap.pop();
                }
                while(!max_heap.empty() && max_heap.top().second<l){
                    max_heap.pop();
                }
                if(max_heap.top().first-min_heap.top().first<=limit){
                    break;
                }
                l++;
            }

            result=max(result,r-l+1);
            r++;
        }
        return result;
    }
};