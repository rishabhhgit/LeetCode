class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        priority_queue<int,vector<int>,greater<int>>pq;
        long long maxi=-1;
        
        long long  currsum=0;
        for(int i=0;i<k;i++){
            currsum=(currsum+v[i][1]);
            pq.push(v[i][1]);
        }
        maxi = 1LL * currsum * v[k - 1][0];

        for(int i=k;i<v.size();i++){
            currsum=currsum+(1LL*v[i][1]-pq.top());
            pq.pop();
            pq.push(v[i][1]);
            maxi = max(maxi,1LL * currsum * v[i][0]);
        }
        return maxi;
    }
};