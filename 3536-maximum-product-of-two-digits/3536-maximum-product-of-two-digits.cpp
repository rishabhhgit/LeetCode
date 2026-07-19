class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int>pq;
        int currnum=n;

        while(currnum>=1){
            int x=currnum%10;
            pq.push(x);
            currnum/=10;
        }
        int ans=1;
        for(int i=0;i<=1;i++){
            if(!pq.empty()){
                ans*=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};