class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        typedef pair<int,int>p;
        unordered_map<char,int>mp;

        priority_queue<int>maxHeap;
        priority_queue<p,vector<p>,greater<p>>minHeap;

        for(auto &it:tasks){
            mp[it]++;
        }

        for(auto &it:mp){
            maxHeap.push(it.second);
        }

        int time=0;
        //pehle check kro min wala hojayega kya?
        while(!minHeap.empty() || !maxHeap.empty()){

            if(!minHeap.empty() && minHeap.top().first<=time ){
                int freq=minHeap.top().second;
                int availableTime=minHeap.top().first;
                minHeap.pop();

                if(freq>0) maxHeap.push(freq);

            }
            if(!maxHeap.empty()){
                int freq=maxHeap.top();
                freq--;
                maxHeap.pop();
                if(freq>0)  minHeap.push({time+n+1,freq});
            }
            time++;
        }
        return time;

    }
};