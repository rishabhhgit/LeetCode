class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        typedef pair<double,pair<int,int>> p;
        priority_queue<p>pq;

        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                double ans=(double)arr[i]/arr[j];
                pq.push({ans,{arr[i],arr[j]}});
                // cout<<arr[i]<<" "<<arr[j]<< " "<<(double)arr[i]/arr[j]<<endl;
                while(pq.size() >k){
                    pq.pop();
                }
            }
        }
        if(!pq.empty()){
            int x1=pq.top().second.first;
            int y1=pq.top().second.second;

            return{x1,y1};
        }
        return {};
    }
};